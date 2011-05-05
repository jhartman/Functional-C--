/*
 * List.h
 *
 *  Created on: May 1, 2011
 *      Author: josh
 */

#ifndef LISTasf_H_
#define LISTasf_H_

template<class T>
class List {
private:
	const T data;
	const List<T> & next;

public:
	List(T d): data(d), next(NULL) {}

	List(T d, const List & next): data(d), next(n) {}

	List<T> operator +(T elem) const {
		List<T> res = List(elem, *this);
		return res;
	}

	List<T> operator +()

//	List<T> operator +()

	T head () const {
		return data;
	}

	template<typename Fn>
	void foreach(Fn fn) {
		const List<T> * p = this;
		while(p != NULL) {
			fn(p -> data);
			p = &(p -> next);
		}
	}
};

#endif /* LIST_H_ */
