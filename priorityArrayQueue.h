#ifndef PRIORITY_ARRAY_QUEUE 
#define PRIORITY_ARRAY_QUEUE

#include "arrayQueue.h"

template<class ItemType> 
class PriorityArrayQueue: public ArrayQueue<ItemType> {
protected:
    //static const int DEFAULT_CAPACITY2 = 100;
    //int prioritys [DEFAULT_CAPACITY2 - 1];

public:  
    bool enqueue(const ItemType& newEntry);

    ~PriorityArrayQueue() { } 
};  
#include "priorityArrayQueue.cpp"
#endif