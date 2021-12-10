#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define ASCII_OFFSET 48
#define SIZE 990

void main()
{
  int ch;
  FILE *fp = fopen("input.txt", "r");
  uint16_t coordinates[SIZE][SIZE] = {0};
  int line_coordinates[4] = {0};
  int number_index = 0;
  int in_number = 0;
  int debug_linenumber = 0;
  while ((ch = fgetc(fp)) != EOF)
  {
    if (ch != '\n' && ch != '-' && ch != ' ' && ch != ',' && ch != '>')
    {
      ch -= ASCII_OFFSET;
      line_coordinates[number_index] *= 10;
      line_coordinates[number_index] += ch;
    }
    if (ch == '>' || ch == ',')
    {
        number_index++;
    }
    else if (ch == '\n')
    {
      if ( line_coordinates[0] == line_coordinates[2] || line_coordinates[1] == line_coordinates[3])
      {
        int16_t x_start =  line_coordinates[0] - line_coordinates[2] < 0 ? line_coordinates[0] : line_coordinates[2];
        int16_t y_start = line_coordinates[1] - line_coordinates[3] < 0 ? line_coordinates[1] : line_coordinates[3];
        int16_t x_abs = line_coordinates[0] - line_coordinates[2];
        int16_t y_abs = line_coordinates[1] - line_coordinates[3];
        x_abs = x_abs < 0 ? -x_abs : x_abs;
        y_abs = y_abs < 0 ? -y_abs : y_abs;
        for (int16_t i = x_start; i <= (x_start + x_abs); i++)
        {
          for (int16_t j = y_start; j <= (y_start + y_abs); j++)
          {
            coordinates[i][j]++;
          }
        }
      }
      for (int i = 0; i < 4; i++)
      {
        line_coordinates[i] = 0;
      }
      number_index = 0;
    }
  }
  int count = 0;
  for (int k = 0; k < SIZE; k++)
  {
    for (int b = 0; b < SIZE; b++)
    {
      if (coordinates[k][b] > 1) { count++; }
    }
  }
  printf("%d", count);
}
