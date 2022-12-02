#include <stdio.h>
#include <stdlib.h>

#define OPPONENT_ROCK 'A'
#define OPPONENT_PAPER 'B'
#define OPPONENT_SCISSORS 'C'

#define PLAYER_ROCK 'X'
#define PLAYER_PAPER 'Y'
#define PLAYER_SCISSORS 'Z'

int getMatchScore(char player, char opponent)
{
  if (player == PLAYER_ROCK && opponent == OPPONENT_SCISSORS ||
      player == PLAYER_PAPER && opponent == OPPONENT_ROCK ||
      player == PLAYER_SCISSORS && opponent == OPPONENT_PAPER)
    return 6;

  if (player == PLAYER_ROCK && opponent == OPPONENT_ROCK ||
      player == PLAYER_PAPER && opponent == OPPONENT_PAPER ||
      player == PLAYER_SCISSORS && opponent == OPPONENT_SCISSORS)
    return 3;

  return 0;
}

int getShapeScore(char shape)
{
  if (shape == PLAYER_ROCK)
    return 1;
  if (shape == PLAYER_PAPER)
    return 2;
  if (shape == PLAYER_SCISSORS)
    return 3;

  return 0;
}

int main()
{
  int currentMaxCalorie = 0;

  char buffer[255];
  FILE *filePointer = fopen("./input", "r");

  int totalScore = 0;

  char playerMove;
  char opponentMove;

  int shapeScore;
  int matchScore;

  while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
  {
    opponentMove = buffer[0];
    playerMove = buffer[2];

    shapeScore = 0;
    matchScore = 0;

    totalScore += getMatchScore(playerMove, opponentMove);
    totalScore += getShapeScore(playerMove);
  }

  fclose(filePointer);

  printf("Total Score: %i\n", totalScore);

  return 0;
}
