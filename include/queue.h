struct node {
    int value;
    node* next;
};

struct queue {
    struct node *head, *tail;
};

struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->head = q->tail = NULL;
    return q;
};