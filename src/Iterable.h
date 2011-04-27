///*
// * Iterable.h
// *
// *  Created on: Sep 17, 2010
// *      Author: jhartman
// */
//
//#ifndef ITERABLE_H_
//#define ITERABLE_H_
//
//template<class IterableT>
//class Iterable {
//public:
////	Iterable();
//
////	template<typename Fn>
////	virtual void foreach(Fn fn);
//
//	template<typename Fn>
//	void foreach(Fn fn) {
//		static_cast<IterableT*>(this) -> foreach0(fn);
//	}
//
//	template<typename Fn>
//	IterableT map(Fn fn) {
//		return static_cast<IterableT*>(this) -> map0(fn);
//	}
//
//	template<typename B, typename Fn>
//	IterableT foldLeft(B seed, Fn fn) {
//		return static_cast<IterableT*>(this) -> foldLeft0(seed, fn);
//	}
//
////	virtual ~Iterable();
//};
//
//#endif /* ITERABLE_H_ */
