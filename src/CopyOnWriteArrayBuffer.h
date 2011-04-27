///*
// * CopyOnWriteArrayBuffer.h
// *
// *  Created on: Apr 25, 2011
// *      Author: jhartman
// */
//
//#ifndef COPYONWRITEARRAYBUFFER_H_
//#define COPYONWRITEARRAYBUFFER_H_
//
//#include <vector>
//#include "Iterable.h"
//using namespace std;
//
//template<class T>
//class CopyOnWriteArrayBuffer : Iterable<T, CopyOnWriteArrayBuffer<T>> {
//private:
//	vector<T> array;
//
//public:
//	CopyOnWriteArrayBuffer() {};
//
//	CopyOnWriteArrayBuffer(vector<T> a): array(a) {};
//
//	CopyOnWriteArrayBuffer<T> operator +(const T & elem) {
//		const vector<T> v(array.size() + 1);
//		for(int i = 0; i < array.size(); i++)
//			v[i] = array[i];
//		v[v.size() - 1] = elem;
//		return CopyOnWriteArrayBuffer(v);
//	}
//
//	T operator[](int index) const {
//	   	return array[index];
//	}
//
//	template<typename Fn>
//	auto map0(Fn fn) -> CopyOnWriteArrayBuffer<decltype(fn(declval<T>()))> {
//		vector<decltype(fn(declval<T>()))> result(array.size());
//		for(int unsigned i = 0; i < array.size(); i++) result[i] = fn(array[i]);
//		return CopyOnWriteArrayBuffer(result);
//	}
//
//	template<typename B, typename Fn>
//	auto foldLeft0(B seed, Fn fn) -> B {
//		B result = seed;
//		for(unsigned int i = 0; i < array.size(); i++) {
//			result = fn(result, array[i]);
//		}
//		return result;
//	}
//
//	template<typename Fn>
//	auto filter0(Fn fn) -> CopyOnWriteArrayBuffer<T> {
//		vector<T> result(array.size());
//		for(int unsigned i = 0; i < array.size(); i++) if(fn(array[i])) result.push_back(array[i]);
//		return CopyOnWriteArrayBuffer(result);
//	}
//
//};
//
//#endif /* COPYONWRITEARRAYBUFFER_H_ */
