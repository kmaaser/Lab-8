// Set.cpp
// Karenna Maaser
// Dr. Reed
// 4/20/2017
#include <iostream>
#include "Set.h"
using namespace std;

void Set::addElement(int x) {
	_items[_numItems] = x;
	++_numItems;
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
		else {
			return false;
		}
	}
}

bool Set::isSubsetOf(const Set &other) const {
	for (int i = 0; i < _numItems; ++i) {
		if (other.containsElement(i)) {
			return true;
		}
		else {
			return false;
		}
	}
}