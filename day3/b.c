#include <stdio.h>
/*
999 = i + 999
998 = i + 997
*/
void main()
{
  int ch;
  FILE *fp = fopen("input_a.txt", "r");
  int input_arr[1000][12] = {0};
  int flag = 0;
  int bit_num = 0;
  int row = 0;
  while ((ch = fgetc(fp)) != EOF)
  {
    if (ch != '\n')
    {
      input_arr[row][bit_num]++;
      bit_num++;
    }
    else
    {
      row++;
      bit_num = 0;
    }
  }
  int numbers_removed = 0;
  int average;
  int size_of_array = 1000;
  bit_num = 0;
  while (numbers_left < 999)
  {
    row = 0;
    average = 0
    int new_arr[size_of_array][12];

    for (int i = 0; i < size_of_array; i++)
    {
      if (input_a[i][bit_num] - 48 == 1)
      {
        average++;
      }
      else
      {
        average--;
      }
    }
    if (average >= 0)
    {
      for (int i = 0; i < size_of_array; i++)
      {
        if (input_a[i] == 1)
        {
          new_arr[size_of_array--] = input_a[a];
        }
      }
    }
    row++;

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
