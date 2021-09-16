/*
  file: nvsearch.c - windows version
  objective: naive search demonstration
  author: Prof. Macris, set-2021, tch.macris@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 800

int array[MAX];

void initialize()
{
  int count;
  for (count = 0; count <= (MAX * 0.20); count++)
  {
    array[count] = (rand() % 1000) + 1;

    //uncomment line below if need some help
    //printf("%i ", array[count]);
  }
}
int search(int val)
{
  int count, res = 0;
  for (count = 0; count < MAX; count++)
  {
    if (array[count] == val && array[count] != 0)
    {
      res = 1;
    }
  }
  return res;
}

int main()
{
  int value = 0;
  char keep = 'y';

  initialize();

  do
  {
    system("cls");
    printf("\n# Naive Search Demo #\n");

    printf("\nEnter a integer number for search: ");
    scanf("%i", &value);

    printf((search(value)) ? ":) number found." : ":( number not found.");

    printf("\n\nContinue ? (y/n): ");
    scanf(" %c", &keep);
  } while (keep == 'y');
  return 0;
}