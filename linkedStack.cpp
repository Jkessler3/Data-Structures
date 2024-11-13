#include "linkedStack.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(){
    topNode = nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    //cout << "Checking if linked list is empty\n";
    return topNode == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){

    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, topNode);
    topNode = newNodePtr;
    newNodePtr = nullptr;
    //cout << "Pushing new node onto stack: " << newEntry << '\n';


    return true;

}

template<class ItemType>
bool LinkedStack<ItemType>::pop(){
    bool canPop = !isEmpty();

    if (canPop){
            Node<ItemType>* newNodePtr = topNode;

            topNode = topNode->getNext();
            newNodePtr->setNext(nullptr);

            delete newNodePtr;
            newNodePtr = nullptr;
    }
    //cout << "Popping node off stack\n";

    return canPop;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    bool canPeek = !isEmpty();

    if(canPeek){
        //cout << "Peeking: " << topNode->getItem() << '\n';
        return topNode->getItem();
    }
    else{
        throw "empty stack";
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack(){
    while(!isEmpty()){
            pop();
        }
    }
