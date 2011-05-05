/*
 * ArrayBuffer.h
 *
 *  Created on: Sep 19, 2010
 *      Author: jhartman
 */

#ifndef ARRAYBUFFER_H_
#define ARRAYBUFFER_H_

#include <vector>
#include "Iterable.h"
#include "Functions.h"
using namespace std;

template<class T>
//class ArrayBuffer : public Iterable<T, ArrayBuffer<T> > {
class ArrayBuffer {
private:
	vector<T> array;

public:
	ArrayBuffer() {};

	ArrayBuffer(int size) {
		array(size);
	}

	ArrayBuffer(vector<T> vector): array(vector) {}

	ArrayBuffer(initializer_list<T> list) : array(list) {}

	ArrayBuffer<T> const operator +(const T & elem){
		array.push_back(elem);
		return *this;
	}

	ArrayBuffer<T> const operator +=(const T &elem) {
		array.push_back(elem);
		return *this;
	}

	T operator [](int index) const {
		return array[index];
	}

	T& operator [](int index) {
		return array[index];
	}

	template<typename Fn>
	void foreach(Fn fn) {
		for(unsigned int i = 0; i < array.size(); i++)
			fn(array[i]);
	}

	template<typename Fn>
	auto map(Fn fn) -> ArrayBuffer<decltype(fn(declval<T>()))> {
		vector<decltype(fn(declval<T>()))> result(array.size());
		for(int unsigned i = 0; i < array.size(); i++)
			result[i] = fn(array[i]);
		return ArrayBuffer(result);
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
	auto filter(Fn fn) -> ArrayBuffer<T> {
		vector<T> result();
		for(int unsigned i = 0; i < array.size(); i++) if(fn(array[i])) result.push_back(array[i]);
		return result;
	}

	template<typename Fn>
	auto flatMap(Fn fn) -> decltype(fn(declval<T>())) {
		// fn maps from T to Iterable[V]
		// If we have a Iterable[String] and we map them to Iterable[Char], we can have one big Iterable[Char]
		decltype(fn(declval<T>())) result;

		for(unsigned int i = 0; i < array.size(); i++) {
			auto iterable = fn(array[i]);
			result = iterable.foldLeft(result, Plus()); // Copy semantics make the foldLeft potentially inefficient here
		}
		return result;
	}

	auto contains(T elem) -> bool {
		for(unsigned int i = 0; i < array.size(); i++) {
			if(elem == array[i]) return true;
		}
		return false;
	}

	auto first() -> T {
		return array[0];
	}

	auto drop(int n) -> ArrayBuffer<T> {
		if(n > array.size())
			return ArrayBuffer<T>();
		else {
			ArrayBuffer<T> result();
			for(int i = 0; i < n; i++) result[i] = array[i];
			return result;
		}
	}

//	template<typename Fn>
//	void foreach0(Fn fn) {
//		for(unsigned int i = 0; i < array.size(); i++) fn(array[i]);
//	}
//
//	template<typename Fn>
//	auto ArrayBuffer<decltype(fn(T())> map(Fn fn) {
//		vector<decltype(fn(T())> result(array.size());
//		for(int unsigned i = 0; i < array.size(); i++) result[i] = fn(array[i]);
//		return result;
//	}
//
//	template<typename B, typename Fn>
//	ArrayBuffer foldLeft0(B seed, Fn fn) {
//		B result = seed;
//		for(unsigned int i = 0; i < array.size(); i++) {
//			result = fn(result, array[i]);
//		}
//		return result;
//	}
};

#endif /* ARRAYBUFFER_H_ */
