template<class ItemType>
ArrayList<ItemType>::ArrayList() : maxCount(DEFAULT_CAPACITY), itemCount(0){}

template<class ItemType>
ArrayList<ItemType>::ArrayList(const ArrayList<ItemType>& aList){
	itemCount = aList.itemCount; //copy the itemCount of other array
	maxCount = aList.maxCount;	//copy maxCount of other array

	for (int i = 1; i <= itemCount; i++ ){
		items[i] = aList.items[i];
	}
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	bool ableToInsert = (newPosition >= 1) &&
                        (newPosition <= itemCount + 1) &&
                        (itemCount < maxCount);
	if (ableToInsert){
		for(int pos = itemCount + 1; pos > newPosition; pos--){
			items[pos] = items[pos - 1];
        	}
        	items[newPosition] = newEntry;
        	itemCount++;
    	}
    	return ableToInsert;
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) &&
                        (position <= itemCount + 1);
	if (ableToRemove){
		for(int pos = position; pos < itemCount; pos++){
			items[pos] = items[pos + 1];
        	}
        	itemCount--;
    	}
    	return ableToRemove;
}

template<class ItemType>
void ArrayList<ItemType>::clear(){
	itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);

	if (ableToGet){
		return items[position];
	} 
	throw "Item not found";
} 

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry){
	ItemType temp;
	bool ableToReplace = (position >= 1) &&
                        (position <= itemCount);
	if (ableToReplace){
			temp = items[position];
        	items[position] = newEntry;
    	}
	throw "Item not found";
	
    return temp;
}
