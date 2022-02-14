#include <gtest/gtest.h>

extern "C" {
    #include "../include/queue.h"
}

//Test for createQueue
TEST(queueTests, createQueue)
{
    struct queue *q;
    q = createQueue();
    EXPECT_EQ(q->head, nullptr);
    EXPECT_EQ(q->tail, nullptr);
    free(q);
}

//Test for enqueue
TEST(queueTests, enqueue) {
    struct queue *q;
    q = createQueue();
    enqueue(q, 1);
    struct node *node1 = q->head;
    EXPECT_NE(node1, nullptr);
    EXPECT_EQ(node1->value, 1);
    EXPECT_EQ(q->head, node1);
    EXPECT_EQ(q->tail, node1);

    enqueue(q, 2);
    struct node *node2 = q->tail;
    EXPECT_NE(node2, nullptr);
    EXPECT_EQ(node2->value, 2);
    EXPECT_EQ(q->head, node1);
    EXPECT_EQ(q->tail, node2);

    free(q);
}

//Test for dequeue
TEST(queueTests, dequeue) {
    struct queue *q;
    q = createQueue();
    enqueue(q, 1);
    struct node *node1 = q->tail;
    enqueue(q, 2);
    struct node *node2 = q->tail;
    enqueue(q, 3);
    struct node *node3 = q->tail;

    EXPECT_NE(node1, nullptr);
    EXPECT_NE(node2, nullptr);
    EXPECT_NE(node3, nullptr);
    EXPECT_EQ(q->head, node1);
    EXPECT_EQ(q->tail, node3);

    dequeue(q);

    EXPECT_EQ(q->head, node2);
    EXPECT_EQ(q->tail, node3);

    free(q);
}

//Test for destroyQueue
TEST(queueTests, emptyQueue) {
    struct queue *q;
    q = createQueue();
    enqueue(q, 1);
    struct node *node1 = q->tail;
    enqueue(q, 2);
    struct node *node2 = q->tail;
    enqueue(q, 3);
    struct node *node3 = q->tail;

    EXPECT_NE(q->head, nullptr);

    emptyQueue(q);

    EXPECT_EQ(q->head, nullptr);

    free(q);
}