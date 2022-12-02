#include <stdio.h>
#include <stdlib.h>

#define ROCK 'A'
#define PAPER 'B'
#define SCISSORS 'C'

#define LOOSE 'X'
#define DRAW 'Y'
#define WIN 'Z'

#define PLAYER_ROCK 1
#define PLAYER_PAPER 2
#define PLAYER_SCISSORS 3

int getMatchScore(char expectedResult)
{
  if (expectedResult == WIN)
    return 6;

  if (expectedResult == DRAW)
    return 3;

  return 0; // loose
}

int getShapeScore(char opponentMove, char expectedResult)
{
  if (
      (opponentMove == ROCK && expectedResult == DRAW) ||
      (opponentMove == PAPER && expectedResult == LOOSE) ||
      (opponentMove == SCISSORS && expectedResult == WIN))
    return PLAYER_ROCK;

  if (
      (opponentMove == ROCK && expectedResult == WIN) ||
      (opponentMove == PAPER && expectedResult == DRAW) ||
      (opponentMove == SCISSORS && expectedResult == LOOSE))
    return PLAYER_PAPER;

  if (
      (opponentMove == ROCK && expectedResult == LOOSE) ||
      (opponentMove == PAPER && expectedResult == WIN) ||
      (opponentMove == SCISSORS && expectedResult == DRAW))
    return PLAYER_SCISSORS;

  return 0; // not reachable
}

int main()
{
  int currentMaxCalorie = 0;

  char buffer[255];
  FILE *filePointer = fopen("./input", "r");

  int totalScore = 0;

  char expectedResult;
  char opponentMove;

  int shapeScore;
  int matchScore;

  while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
  {
    opponentMove = buffer[0];
    expectedResult = buffer[2];

    shapeScore = 0;
    matchScore = 0;

    totalScore += getMatchScore(expectedResult);
    totalScore += getShapeScore(opponentMove, expectedResult);
  }

  fclose(filePointer);

  printf("Total Score: %i\n", totalScore);

  return 0;
}
