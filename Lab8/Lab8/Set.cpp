// Set.cpp
// Karenna Maaser
// Dr. Reed
// 4/20/2017
#include <iostream>
#include "Set.h"
using namespace std;

//Initalize constructor: Set
//Initalizing _numItems to 0
Set::Set() {
	_numItems = 0;
}

//For loop goes through the array
//If statement checks to see if 'x' is in the set
//if x is in the set, then the return breaks out
//after going through the for loop and checking to
//see if x is in the set and it happens to be that
//x is not in the set, then it is added to the set
//in the next available spot
//_numItems is also increased because now there is
//another element added to the set
void Set::addElement(int x) {
	for (int i = 0; i < _numItems; ++i) {
		if (x == _items[i]) {
			return;
		}	
	}
	_items[_numItems] = x;
	++_numItems;	
}

//For loop goes through the array and checks to see
//if x is in the array. If x is in the array, then
//go through the rest of the array
//While doing this shift everything down 1 and overwriting 'x'.
//Set the last element to 0 because it is no longer needed
//and then finally decrement _numItems because of the shift
void Set::removeElement(int x) {
	for (int i = 0; i < _numItems; ++i) {
		if (x == _items[i]) {
			for (int j = i + 1; j < _numItems; ++j) {
				_items[j - 1] = _items[j];
			}
			_items[_numItems - 1] = 0;
			--_numItems;
			break;
		}
	}
}

//For loop goes through the array and sets the elements
//to 0, but all one really needs to do is set _numItems
//to 0 because we don't care what is in the array anymore
void Set::removeAllElements() {
	for (int i = 0; i < _numItems; ++i) {
		_items[i] = 0;
	}
	_numItems = 0;
}

//For loop goes through the array to check values
//If compares the values in the array to the value
//we are looking for. If we find it, we return true.
//If we don't find it, we return false
bool Set::containsElement(int x) const {
	for (int i = 0; i < _numItems; ++i) {
		if (x == _items[i]) {
			return true;
		}
	}
	return false;
}

//Similar to containsElement
//We use a for loop to go through the array (Set) and check
//the values in the array
//We use the containsElement to check and see if the subset
//is or is not in the array
//If the other set does not contain the items, we return false,
//and if it goes through the loop, then we return true
bool Set::isSubsetOf(const Set &other) const {
	for (int i = 0; i < _numItems; ++i) {
		if (!other.containsElement(_items[i])) {
			return false;
		}
	}
	return true;
}

//Create a new set so we can return it
//Then add the items of set a to the new set
//Second for loop to go thhrough set b and then
//check to make sure the new set does not contain
//any elements already in the new set then adds the
//ones that are not
//return the set
Set operator+(const Set &a, const Set &b) {
	Set set;
	
	for (int i = 0; i < a.numElements(); ++i) {
		set.addElement(a._items[i]);
	}
	for (int j = 0; j < b.numElements(); ++j) {
		if (!set.containsElement(b._items[j])) {
			set.addElement(b._items[j]);
		}
	}
	return set;
}

//Create new set
//goes through set a and then checks to see if
//set b doesnt contain the elemet of a
//If it doesn't, it is added to the new set
//return the set
Set operator-(const Set &a, const Set &b) {
	Set set;

	for (int i = 0; i < a.numElements(); ++i) {
		if (!b.containsElement(a._items[i])) {
			set.addElement(a._items[i]);
		}
	}
	return set;
}

//Goes through the array and adds them to a string
//Also puts a comma inbetween the numbers except the
//last one
//return the os
std::ostream& operator<<(std::ostream &os, const Set &a) {
	for (int i = 0;i < a.numElements()-1;i++) {
		os << a._items[i]+", ";
	}
	os << a._items[a.numElements() - 1];
	return os;
}