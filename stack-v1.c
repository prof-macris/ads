/*
  file: stack-v1.c - windows version
  objective: stack demonstration (array)
  author: Prof. Macris, set-2021, tch.macris@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int sstack[MAX];
int top;

void create() {
  top = 0;
}

int isFull() {
  return (top == MAX);
}

int isEmpty() {
  return (top == 0);
}

int push(int x ) {
  if (isFull()) {
    return 0;
  } else {
    sstack[top++] = x;
    return 1;
  }
}

int pop() {
  if (isEmpty()) {
    return 0;
  } else {
    return sstack[--top];
  }
}

int search(int value) {
  //code here
  return 0;
}

int main() {
  int option = 0, value = 0;
  char keep = 'y';

  create();

  do {
    printf("\n# Stack Demo Menu #\n");
    printf("\n1. Push\n2. Pop\n3. Exit\n\nChoose an option: ");
    scanf("%i", &option);

    switch (option) {
    case 1:
      printf("\nEnter a integer number: ");
      scanf("%i", &value);
      if (push(value)) {
        printf("* Push ok.");
      } else {
        printf("* Push error.");
      }
      break;
    case 2:
      value = pop();
      if (value != 0) {
        printf("* Pop ok.");
      } else {
        printf("* Pop error.");
      }
      break;
    case 3:
      exit(1);
    default:
      printf("* Invalid option");
      break;
    }
    printf("\n\nContinue ? (y/n): ");
    scanf(" %c", &keep);
  } while (keep == 'y');
  return 0;
}
