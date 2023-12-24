#include "Queue.h"

arrQueue *creatarrQueue() {
	arrQueue *queue = (arrQueue *)malloc(sizeof(arrQueue));
	if (!queue) {
		fprintf(stderr, "malloc queuehead faild!\n");
		return NULL;
	}

	queue->rear = queue->front = 0;
	return queue;
}

void releaseArrQue(arrQueue *queue) {
	if (queue) {
		free(queue);
	}
}

int enArrQueue(arrQueue *queue, Element val) {
	//1.不能满
	if ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front) {
		printf("Queue overflowed!\n");
		return -1;
	}
	//2.入队
	queue->data[queue->rear] = val;
	queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
	queue->num++;
	return 0;
}

int deArrQueue(arrQueue *queue, Element *val) {
	//1.不能空
	if (queue->front == queue->rear) {
		printf("Queue underflow!\n");
		return -1;
	}
	//2.出队
	if (val) {
		*val = queue->data[queue->front];
	}
	queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
	queue->num--;
}

void showArrQueue(arrQueue *queue) {
	printf("[");
	int tmp = queue->front;
	do {
		printf("%d", queue->data[tmp]);
		tmp = (tmp + 1) % MAX_QUEUE_SIZE;
		if (tmp != queue->rear )
			printf(", ");
	} while (tmp != queue->rear);
	printf("]\n");
}

/*----------------------------------------*/

LinkQueue *creatLinkQueue() {
	LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
	queue->front = queue->rear = NULL;
	queue->num = 0;

	return queue;
}

void releaseLinkQueue(LinkQueue *queue) {
	if (queue) {
		Node *tmp;
		while (queue->front) {
			tmp = queue->front;
			queue->front = tmp->next;
			free(tmp);
			--queue->num;
		}
		printf("Queue have %d node left!\n", queue->num);
	}
}

int enLinkQueue(LinkQueue *queue, Element val) {
	//1.先创建控件
	Node *node = (Node *)malloc(sizeof(Node));
	if (!node) {
		fprintf(stderr, "malloc que faild!\n");
		return -1;
	}
	node->data = val;
	node->next = NULL;
	//2.处理队尾关系(空和有元素)
	if (queue->rear) {
		//有元素
		queue->rear->next = node;
	} else {
		queue->rear = queue->front = node;
	}
	queue->rear = node;
	queue->num++;
	return 0;
}

int deLinkQueue(LinkQueue *queue, Element *val) {
	if (!queue->front) {
		printf("Queue empty!\n");
		return -1;
	} else {
		Node *tmp = queue->front;
		queue->front = queue->front->next;
		if (val) {
			*val = tmp->data;
			//int a = 30;
			//int *p = &a;

			//printf("p = %p\n", (void *)p);
			//printf("*p = %d\n", *p);

			//// 下面这行代码是不安全的，应该避免直接将整数值赋给指针
			//// p = 35;

			//// 如果您想改变 *p 的值，您应该这样做：
			//*p = 35;

			//printf("p = %p\n", (void *)p);
			//printf("*p = %d\n", *p);
		}
		free(tmp);
		--queue->num;
	}
	if (!queue->front) {
		//队列中没有元素了
		queue->rear = NULL;
	}
	return 0;
}

void showLinkQueue(LinkQueue *queue) {
	printf("[");
	Node *tmp = queue->front;
	while (tmp != NULL) {
		printf("%d", tmp->data);
		if (tmp != queue->rear) {
			printf(", ");
		}
		tmp = tmp->next;
	}
	printf("]\n");
}
