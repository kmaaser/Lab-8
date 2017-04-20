// Set.cpp
// Karenna Maaser
// Dr. Reed
// 4/20/2017
#include <iostream>
#include "Set.h"
using namespace std;

void Set::addElement(int x) {
	for (int i = 0; i < _numItems; ++i) {
		if (x == _items[i]) {
			return;
		}
		else {
			_items[_numItems] = x;
			++_numItems;
		}
	}	
}

void Set::removeElement(int x) {
	for (int i = 0; i < _numItems; ++i) {
		if (x == _items[i]) {
			for (int j = i + 1; j < _numItems; ++j) {
				_items[j - 1] = _items[j];
			}
			_items[_numItems - 1] = 0;
			--_numItems;
		}
	}
}

void Set::removeAllElements() {
	for (int i = 0; i < _numItems; ++i) {
		_items[i] = 0;
	}
	_numItems = 0;
}

bool Set::containsElement(int x) const {
	for (int i = 0; i < _numItems; ++i) {
		if (x == _items[i]) {
			return true;
		}
	}
	return false;
}

bool Set::isSubsetOf(const Set &other) const {
	for (int i = 0; i < _numItems; ++i) {
		if (!other.containsElement(_items[i])) {
			return false;
		}
	}
	return true;
}

Set operator+(const Set &a, const Set &b) {
	Set set = Set();
	
	for (int i = 0; i < a.numElements(); ++i) {
		set.addElement(a._items[i]);
		++set._numItems;
	}
	for (int j = 0; j < b.numElements(); ++j) {
		if (!set.containsElement(b._items[j])) {
			set.addElement(b._items[j]);
			++set._numItems;
		}
	}
	return set;
}

Set operator-(const Set &a, const Set &b) {
	Set set;

	for (int i = 0; i < a.numElements(); ++i) {
		if (!b.containsElement(a._items[i])) {
			set.addElement(a._items[i]);
		}
	}
	return set;
}

std::ostream& operator<<(std::ostream &os, const Set &a) {
	for (int i = 0;i < a.numElements()-1;i++) {
		os << a._items[i]+",";
	}
	os << a._items[a.numElements() - 1];
	return os;
}