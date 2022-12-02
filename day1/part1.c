#include <stdio.h>
#include <stdlib.h>

int main()
{
  int currentMaxCalorie = 0;

  char buffer[255];
  FILE *filePointer = fopen("./input", "r");

  int currentElf = 0;
  int currentLine = 0;

  while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
  {
    if (buffer[0] == '\n')
    {
      if (currentElf > currentMaxCalorie)
      {
        currentMaxCalorie = currentElf;
      }

      currentElf = 0;
      continue;
    }

    currentLine = strtol(buffer, NULL, 10);
    currentElf += currentLine;
  }

  fclose(filePointer);

  printf("Max Calorie Count: %i\n", currentMaxCalorie);

  return 0;
}
