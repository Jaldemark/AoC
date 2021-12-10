#include <stdio.h>


void main()
{
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
      else
      {
        if(current_depth > last_val)
        {
          increase++;
        }
      }
      last_val = current_depth;
      current_depth = 0;
    }
  }
  printf("%d", increase);
}
