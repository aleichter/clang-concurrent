struct node {
    int value;
    node *next;
};

struct queue {
    struct node *head, *tail;
};

struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->head = q->tail = NULL;
    return q;
};

void enqueue(struct queue *q, int v) {
    struct node *tempNode = (struct node*)malloc(sizeof(struct node));
    tempNode->value = v;
    tempNode->next = NULL;

    if(q->tail == NULL) {
        q->head = q->tail = tempNode;
        return;
    }

    q->tail->next = tempNode;
    q->tail = tempNode;
};

void dequeue(struct queue *q) {
    if(q->head == NULL)
        return;
    
    struct node *tempNode = q->head;
    q->head = q->head->next;
    if(q->head == NULL)
        q->tail = NULL;

    free(tempNode);
};

void emptyQueue(struct queue *q) {
    while(q->head != NULL) {
        dequeue(q);
    }
};