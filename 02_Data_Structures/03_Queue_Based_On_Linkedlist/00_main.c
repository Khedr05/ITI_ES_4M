
#include "03_queue_based_on_ll.h"

ST_queueHead_t ST_queue;

void main(void) {
  printf("\n\n");
  vQueueInit(&ST_queue, 0);
  vQueuePush(&ST_queue, 1);
  vQueuePush(&ST_queue, 1);
  vQueuePush(&ST_queue, 2);
  vQueueDisplay(&ST_queue);
  vQueuePop(&ST_queue);
  vQueuePop(&ST_queue);
  vQueueDisplay(&ST_queue);
  vQueuePush(&ST_queue, 4);
  vQueuePush(&ST_queue, 5);
  vQueueDisplay(&ST_queue);
  vQueuePop(&ST_queue);
  vQueueDisplay(&ST_queue);
  vQueuePush(&ST_queue, 15);
  vQueueDisplay(&ST_queue);
  vQueuePop(&ST_queue);
  vQueuePop(&ST_queue);
  vQueueDisplay(&ST_queue);
}