#include <gtest/gtest.h>

extern "C" {
#include "../include/queue.h"
}

TEST(queueTests, queueAllocation)
{
    queue *q;
    q = createQueue();
    EXPECT_EQ(q->head, nullptr);
    EXPECT_EQ(q->tail, nullptr);
    //TODO:  Need a freeQueue function as before we free the q pointer
    // we need to free all the pointers in the linked list to nodes.
    // other wise we'll end up with memory leaks
    free(q);
}