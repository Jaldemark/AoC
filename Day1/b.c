#include <stdio.h>

#define INPUT_SIZE 2000
void main()
{
  int all_values[INPUT_SIZE];
  int inefficient_array[INPUT_SIZE];
  int index = 0;
  int ch;
  FILE *fp = fopen("input_a.txt", "r");
  int increase = 0;
  int last_val;
  int current_depth = 0;
  int flag = 0;
  while ((ch = fgetc(fp)) != EOF)
  {
    if (ch != '\n')
    {
      ch -= 48;
      current_depth *=10;
      current_depth += ch;
    }
    else
    {
      if (flag == 0)
      {
        last_val = current_depth;
        flag = 1;
      }
      all_values[index++] = current_depth;
      last_val = current_depth;
      current_depth = 0;
    }
  }
  for (int i = 0; i < 1998; i++)
  {
    inefficient_array[i] = all_values[i] + all_values[i+1] + all_values[i+2];
    if (i > 0)
    {
      if (inefficient_array[i] > inefficient_array[i-1])
      {
        increase++;
      }
    }
  }
  if (inefficient_array[1997] < (inefficient_array[1998])) increase++;
  if (inefficient_array[1998] < (inefficient_array[1999])) increase++;
  printf("%d", increase);
}
