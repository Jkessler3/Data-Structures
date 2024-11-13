#include "arrayQueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(){
    itemCount = 0;
    frontIndex = 0;
    backIndex = itemCount - 1;  

}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const{
    return itemCount == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry){
    if(itemCount < DEFAULT_CAPACITY){
        backIndex = (backIndex + 1) % DEFAULT_CAPACITY;
        items[backIndex] = newEntry;
        itemCount++;
        return true;
    }
    else{
        throw("Error! Can't enqueue!\n");
        return false;
    }
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue(){
    if(!isEmpty()){
        frontIndex = (frontIndex + 1) % DEFAULT_CAPACITY;
        itemCount--;
        return true;
    }
    else{
        throw("Error! Can't remove. List is empty\n");
        return false;
    }
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const{
    if(!isEmpty()){
        return items[frontIndex];
    }
    else{
        throw("Error!");
    }
}

template<class ItemType>
ArrayQueue<ItemType>::~ArrayQueue(){

 } 