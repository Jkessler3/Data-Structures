template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
	// enforce precondition
	if((position >= 1) && (position <= itemCount)){
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return nullptr;
} 

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0){}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
	itemCount = aList.itemCount; //copy the itemCount of other array

	if(aList.head == nullptr){
		//if no data create a empty list
		headPtr = nullptr;
	}
	else{
		//Create the new head node
		headPtr = new Node<ItemType>;						//Sets new headPtr
		headPtr->setItem(aList.headPtr->getItem()); 		//copies the data of the new node with the old node


		Node<ItemType> *newPtr = headPtr; 	//Creates pointer to link the rest
		Node<ItemType> *copyPtr = aList.headPtr->next;				//creates ptr to the copied list and sets to the next

		for(int pos = 2; pos <= itemCount; pos++){
			newPtr->next = new Node<ItemType>;  //creates the next empty node
			newPtr = newPtr->next; //moves the node to the empty tail
			newPtr->item = copyPtr->item; //grabs the data from the orginal and fills the empty node
			copyPtr = copyPtr->next; //moves the copy to the next node of the copy.
			}
			newPtr->next = nullptr; //sets the tail to null

			//IS THIS DNA REPLICATION?
	}
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if(ableToInsert){
		//create new node
		Node<ItemType> *newNode = new Node<ItemType>;
		newNode->setItem(newEntry);

		if(newPosition == 1)
		{
			newNode->setNext(headPtr); //Point the new node to head
			headPtr = newNode;			//set the new node as head
		}
		else{
			Node<ItemType> *tempPtr = getNodeAt(newPosition - 1); //create a ptr to the previous node before insertion
			newNode->setNext(tempPtr->getNext()); //Links the new node to point to the next position.
			tempPtr->setNext(newNode);	//links the old node to the new node.
		}
		itemCount++;
	}

    return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove){
		Node<ItemType>* ptrToDelete = nullptr;
		if (position == 1){
			// Remove the first node in the chain
			ptrToDelete = headPtr; // Save pointer to node 
			headPtr = headPtr->getNext();// save pointer to next node
		}
		else{
			// Find node that is before the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			// Point to node to remove
			ptrToDelete = prevPtr->getNext();
			// Disconnect indicated node from chain by connecting the prior node with the one after
			prevPtr->setNext(ptrToDelete->getNext());
		}

		ptrToDelete->setNext(nullptr);
		delete ptrToDelete;
		ptrToDelete = nullptr;
		itemCount--; // Decrease count of entries
	}
	return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear(){
	while(!isEmpty()){
		remove(1);
	}
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if(ableToGet){
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	throw "Item not found";
} 

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
	// enforce precondition
	bool ableToReplace = (position >= 1) && (position <= itemCount);
	if (ableToReplace){
		Node<ItemType>* nodePtr = getNodeAt(position);
		ItemType oldEntry = nodePtr->getItem();
		nodePtr->setItem(newEntry);	
		return oldEntry;	
	} 
	throw "Item not found";
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	clear();
} 
