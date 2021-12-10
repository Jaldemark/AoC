#include <stdio.h>


void main()
{
  int ch;
  FILE *fp = fopen("input_a.txt", "r");
  int depth = 0;
  int horizontal = 0;
  int direction = -1;
  int aim = 0;
  int val = 0;
  int flag = 0;
  while ((ch = fgetc(fp)) != EOF)
  {
    if (ch != '\n')
    {
      if (direction == -1)
      {
        direction = ch;
      }
      else if (ch == ' ')
      {
        flag = 1;
      }
      else if (flag == 1)
      {
        flag = 0;
        char dir = direction;
        switch (direction) {
          case 'f':
            horizontal += ch-48;
            depth += aim*(ch-48);
            break;
          case 'u':
            aim -= ch-48;
            break;
          case 'd':
            aim += ch-48;
            break;
        }
        direction = -1;
      }
    }

  }
  printf("%d", horizontal*depth);
}
