#include "Queue.h"

int main() {
	int tmp;
	arrQueue *queue = creatarrQueue();
	enArrQueue(queue, 1);
	showArrQueue(queue);

	enArrQueue(queue, 3);
	showArrQueue(queue);

	enArrQueue(queue, 4);
	showArrQueue(queue);

	enArrQueue(queue, 3);
	showArrQueue(queue);

	deArrQueue(queue, &tmp);
	printf("tmp = %d\n", tmp);
	showArrQueue(queue);
/*-----------------------------------*/
	int ltmp;
	LinkQueue *lqueue = creatLinkQueue();
	enLinkQueue(lqueue, 0);
	showLinkQueue(lqueue);

	enLinkQueue(lqueue, 1);
	showLinkQueue(lqueue);

	enLinkQueue(lqueue, 4);
	showLinkQueue(lqueue);

	enLinkQueue(lqueue, 3);
	showLinkQueue(lqueue);

	deLinkQueue(lqueue, &ltmp);
	printf("tmp = %d\n", ltmp);
	showLinkQueue(lqueue);
	return 0;
}