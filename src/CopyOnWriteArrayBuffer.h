/*
 * CopyOnWriteArrayBuffer.h
 *
 *  Created on: Apr 25, 2011
 *      Author: jhartman
 */

using namespace std;

#ifndef COPYONWRITEARRAYBUFFER_H_
#define COPYONWRITEARRAYBUFFER_H_

#include <vector>
#include "Iterable.h"

template<class T>
class CopyOnWriteArrayBuffer {
private:
	vector<T> array;

public:
	CopyOnWriteArrayBuffer() {};

	CopyOnWriteArrayBuffer(vector<T> a): array(a) {};

	CopyOnWriteArrayBuffer(initializer_list<T> list) : array(list) {}

	CopyOnWriteArrayBuffer<T> operator +(T elem) {
		const vector<T> v(array.size() + 1);
		for(int i = 0; i < array.size(); i++)
			v[i] = array[i];
		v[v.size() - 1] = elem;
		return CopyOnWriteArrayBuffer(v);
	}

	T operator[](int index) const {
	   	return array[index];
	}

	CopyOnWriteArrayBuffer<T> updated(int index, T elem) const {
		vector<T> v = array;
		v[index] = elem;
		return v;
	}

	auto size() -> int {
		return array.size;
	}

	bool isEmpty() const {
		return array.empty();
	}

	template<typename Fn>
	void foreach(Fn fn) {
		for(unsigned int i = 0; i < array.size(); i++) fn(array[i]);
	}

	template<typename Fn>
	auto map(Fn fn) -> CopyOnWriteArrayBuffer<decltype(fn(declval<T>()))> {
		vector<decltype(fn(declval<T>()))> result(array.size());
		for(int unsigned i = 0; i < array.size(); i++) result[i] = fn(array[i]);
		return CopyOnWriteArrayBuffer(result);
	}

	template<typename B, typename Fn>
	auto foldLeft(B seed, Fn fn) -> B {
		B result = seed;
		for(unsigned int i = 0; i < array.size(); i++) {
			result = fn(result, array[i]);
		}
		return result;
	}

	template<typename Fn>
	auto filter(Fn fn) -> CopyOnWriteArrayBuffer<T> {
		vector<T> result(array.size());
		for(int unsigned i = 0; i < array.size(); i++) if(fn(array[i])) result.push_back(array[i]);
		return CopyOnWriteArrayBuffer(result);
	}

	auto contains(T elem) -> bool {
		for(int unsigned i = 0; i < array.size(); i++)
			if(array[i] == elem) return true;
		return false;
	}

};

#endif /* COPYONWRITEARRAYBUFFER_H_ */
