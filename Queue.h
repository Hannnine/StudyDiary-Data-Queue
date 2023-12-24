#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int Element;
/*À≥–Ú∂”¡–*/
typedef struct {
	Element data[MAX_QUEUE_SIZE];
	int front;
	int rear; 
	int num;
}arrQueue;

arrQueue *creatarrQueue();
void releaseArrQue(arrQueue *queue);

int enArrQueue(arrQueue *queue, Element val);
int deArrQueue(arrQueue *queue, Element *val);

void showArrQueue(arrQueue *queue);

/*---------------------------*/

typedef struct _node {
	Element data;
	struct _node *next;
}Node;

typedef struct {
	Node *front;
	Node *rear;
	int num;
}LinkQueue;

LinkQueue *creatLinkQueue();
void releaseLinkQueue(LinkQueue *queue);

int enLinkQueue(LinkQueue *queue, Element val);
int deLinkQueue(LinkQueue *queue, Element *val);