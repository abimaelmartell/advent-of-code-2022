#include <stdio.h>
#include <stdlib.h>

#define TOP_CALORIES_NUMBER 3

int main()
{
  char buffer[255];
  FILE *filePointer = fopen("./input", "r");

  int topElves[TOP_CALORIES_NUMBER] = {0};

  int currentElf = 0;
  int currentLine = 0;

  while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
  {
    if (buffer[0] == '\n')
    {
      for (int i = 0; i < TOP_CALORIES_NUMBER; i++)
      {
        if (currentElf > topElves[i])
        {
          for (int j = TOP_CALORIES_NUMBER - 1; j > i; j--)
          {
            topElves[j] = topElves[j - 1];
          }

          topElves[i] = currentElf;

          break;
        }
      }

      currentElf = 0;
      continue;
    }

    currentLine = strtol(buffer, NULL, 10);
    currentElf += currentLine;
  }

  fclose(filePointer);

  int topCaloryCount = 0;

  for (int i = 0; i < TOP_CALORIES_NUMBER; i++)
  {
    printf("#%i: %i Calories\n", i + 1, topElves[i]);
    topCaloryCount += topElves[i];
  }

  printf("Total Top Calories: %i\n", topCaloryCount);

  return 0;
}
