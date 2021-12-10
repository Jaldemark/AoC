#include <stdio.h>

void main()
{
  int ch;
  FILE *fp = fopen("input_a.txt", "r");
  int input_arr[12] = {0};
  int flag = 0;
  int bit_num = 0;
  while ((ch = fgetc(fp)) != EOF)
  {
    if (ch != '\n')
    {
      if (ch - 48 == 1)
      {
        input_arr[bit_num]++;
      }
      else
      {
        input_arr[bit_num]--;
      }
      bit_num++;
    }
    else
    {
      bit_num = 0;
    }
  }
  for (int i = 0; i < 12; i++)
  {
    if (input_arr[i] < 0)
    {
        printf("%d", 1);
    }
    else
    {
        printf("%d", 0);
    }//943 *
  }
}
