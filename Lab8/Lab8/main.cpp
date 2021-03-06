// main.cpp
// Karenna Maaser
// Dr. Reed
// 4/20/2017
#include <cassert>
#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
	Set a;
	Set b;
	Set c;
	Set d;

	cout << "Test add element" << endl;
	a.addElement(6);
	assert(a.numElements() == 1);
	cout << "add element passed" << endl;

	cout << "Test add element 2" << endl;
	a.addElement(3);
	a.addElement(6);
	assert(a.numElements() == 2);
	cout << "add element test 2 passed" << endl;

	cout << "Test remove element" << endl;
	a.removeElement(6);
	assert(a.numElements() == 1);
	cout << "remove element passed" << endl;

	cout << "Test remove all elements" << endl;
	a.removeAllElements();
	assert(a.numElements() == 0);
	cout << "remove all elements passed" << endl;

	cout << "Test contains element" << endl;
	a.addElement(6);
	a.addElement(3);
	a.containsElement(6);
	assert(a.containsElement(6) == true);
	cout << "contains elements passed" << endl;
	
	cout << "Test contains element 2" << endl;
	a.containsElement(5);
	assert(a.containsElement(5) == false);
	cout << "contains element 2 test passed" << endl;

	cout << "Test is subset of" << endl;
	b.addElement(2);
	b.addElement(3);
	b.isSubsetOf(a);
	assert(b.isSubsetOf(a) == false);
	cout << "is subset of passed" << endl;

	cout << "Test operator+" << endl;
	c = a + b;
	assert(c.numElements() == 3);
	cout << "test operator+ passed" << endl;

	cout << "Test operator-" << endl;
	d = a - b;
	assert(d.numElements() == 1);
	cout << "test operator- passed" << endl;

	return 0;
}