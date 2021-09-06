/*
  queue: queue-v2.c - windows version
  objective: queue demonstration (struct)
  author: Prof. Macris, set-2021, tch.macris@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXQUEUE 100

typedef struct TQueue {
  char item[MAXQUEUE];
  int front, rear;
} queue;

void create(queue *q) {
  q->front = 0;
  q->rear = -1;
}

int isEmpty(queue *q) {
  return (q->rear < q->front);
}

int isFull(queue *q) {
  return (q->rear == MAXQUEUE - 1);
}

void enqueue(queue *q, char x)
{
  q->item[++q->rear] = x;
}

char dequeue(queue *q) {
  int i;
  char x = q->item[0];
  for (i = 0; i < q->rear; i++) {
    q->item[i] = q->item[i + 1];
  }
  q->rear--;
  return x;
}

void report(queue *q) {
  //code here
  printf("\n* Maybe a homework?");
}

queue q1;

int main() {
  int option, i;
  char value;

  queue q1;

  create(&q1);

  while (option != 4) {
    system("cls");
    printf("\n# Queue Demo Menu #\n");
    printf("\n1. Enqueue\n2. Dequeue\n3. List\n4. Exit\n\nChoose an option: ");
    scanf("%i", &option);

    switch (option) {
      case 1:
        printf("\nEnter a char value: ");
        scanf(" %c", &value);
        if (isFull(&q1)) {
          printf("\n* queue is full.");
        } else {
          enqueue(&q1, value);
          printf("\n* enqueue %c ok.", value);
        }
        break;
      case 2:
        if (!isEmpty(&q1)) {
          value = dequeue(&q1);
          printf("\n* dequeue %c ok.", value);
        } else {
          printf("\n* queue is empty.");
        }
        break;
      case 3:
        report(&q1);
        break;
      case 4:
        exit(1);
      default:
        printf("* Invalid option");
        break;
    }
    printf("\nPress a key...");
    getch();
  }
  return 0;
}
