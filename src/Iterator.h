/*
 * Iterator.h
 *
 *  Created on: Sep 17, 2010
 *      Author: jhartman
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

template<class T>
class Iterator {
public:
	Iterator();

	virtual bool hasNext();
	virtual T next();

	template<typename Fn>
	void foreach(Fn fn) {
		while(hasNext()) {
			fn(next());
		}
	}

//	template<typename Fn>
//	void map(Fn fn) {
//		while(hasNext()) {
//
//		}
//	}

	virtual ~Iterator();
};

#endif /* ITERATOR_H_ */
