/*
 * ListIterator.h
 *
 *  Created on: Sep 18, 2010
 *      Author: jhartman
 */


#ifndef LISTITERATOR_H_
#define LISTITERATOR_H_

#include <vector>
#include "Iterator"
using namespace std;

template<class T>
class ListIterator : public Iterator<T> {
private:
	vector<T> elems;
public:
	ListIterator();
	virtual ~ListIterator();
};

#endif /* LISTITERATOR_H_ */
