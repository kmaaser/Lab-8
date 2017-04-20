//
//  Set.h
//  CPP-Set
//
//  Created by David M Reed on 3/26/15.
//  Copyright (c) 2015 David M Reed. All rights reserved.
//

#ifndef __CPP_Set__Set__
#define __CPP_Set__Set__

#include <iostream>

const int MAX_SET_ITEMS = 100;

class Set {

	friend Set operator+(const Set &a, const Set &b);
	friend Set operator-(const Set &a, const Set & b);
	friend std::ostream& operator<<(std::ostream &os, const Set &a);

public:
	Set();

	int numElements() const { return _numItems; }

	/// adds x to the Set
	///
	/// @param x the value to add to the Set
	/// @post the Set now contains x
	///
	void addElement(int x);

	/// removes x from the Set
	///
	/// @param x the value to remove from the Set
	/// @post x is not in the Set
	///
	void removeElement(int x);

	/// removes all elements from the set
	///
	/// @post the Set is empty
	///
	void removeAllElements();

	/// determines if x is in the Set
	///
	/// @param x the value to determine if it is in the Set
	/// @returns true if x is in the Set or false if x is not in the Set
	///
	bool containsElement(int x) const;

	/// determines if other is a subset of the Set
	///
	/// @param other the Set to determine if this is a subset of
	/// @returns true if this is a subset of the Set other or false if it is not a subset of the Set other
	///
	bool isSubsetOf(const Set &other) const;

private:
	int _items[MAX_SET_ITEMS];
	int _numItems;
};


/// unions Set a and Set b
///
/// @returns a new Set that is the union of Set a and Set b
///
Set operator+(const Set &a, const Set &b);

/// difference of Set a and Set b
///
/// @returns returns the difference of Set a and Set b (a - b)
///
Set operator-(const Set &a, const Set &b);

/// output contents of set
///
/// @param os the ostream to output to
/// @param a the Set to output
/// @returns the ostream os that is passed to it
std::ostream& operator<<(std::ostream &os, const Set &a);

#endif /* defined(__CPP_Set__Set__) */