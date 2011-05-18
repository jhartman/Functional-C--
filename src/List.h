/*
 * List.h
 *
 *  Created on: May 1, 2011
 *      Author: josh
 */

#ifndef LISTasf_H_
#define LISTasf_H_

#include <memory>
#include "Functions.h"

template<typename T>
class Cell;

template<class T>
class List : public enable_shared_from_this< List<T> > {
private:
	shared_ptr<const Cell<T> > cell;

	List(shared_ptr<const Cell<T> > c): cell(c) {}
public:
	List(T d) {
		auto c = new Cell<T>(d);
		cell = shared_ptr<Cell<T> >(c);
	}

	List() : cell(shared_ptr<const Cell<T> >()) {}

	List(initializer_list<T> list) {
		List<T> myList;
		for(auto iter = list.begin(); iter != list.end(); iter++) {
			myList = myList + (*iter);
		}
		cell = myList.reverse().cell;
	}

	List<T> operator +(const T elem) const {
		auto newCell = new Cell<T>(elem, cell);
		auto cellPtr = shared_ptr<const Cell<T> >(newCell);
		auto list = List(cellPtr);
		return list;
	}

	T head () const {
		return cell -> data;
	}

	template<typename Fn>
	void foreach(Fn fn) const {
		auto p = cell;
		auto null = shared_ptr<Cell<T> >();
		while(p != null) {
			fn(p -> data);
			p = p -> next;
		}
	}

	List<T> reverse() const {
		List<T> curr;
		foreach([&curr](const T & elem) -> void {
			curr = curr + elem;
		});
		return curr;
	}

	template<typename B, typename Fn>
	auto foldLeft(B seed, Fn fn) const -> B {
		B result = seed;
		foreach([&result, &fn](const T & elem) -> void {
			result = fn(result, elem);
		});
		return result;
	}

	int size() const {
		return foldLeft(0, [](int acc, T elem) { return acc + 1; });
	}

	template<typename Fn>
	auto map(Fn fn) -> List<decltype(fn(declval<T>()))> {
		List<decltype(fn(declval<T>()))> result;

		return foldLeft(result,
				[&fn](const List<decltype(fn(declval<T>()))> & acc, const T & elem) {
			return acc + fn(elem);
		}).reverse();
	}
};

template<typename T>
class Cell : public enable_shared_from_this< Cell<T> > {
private:
	friend class List<T>;
	const T data;
	shared_ptr<const Cell<T> > next;

	Cell(T d) : data(d), next(shared_ptr<Cell<T> >()) {}
	Cell(T d, shared_ptr<const Cell<T> > n) : data(d), next(n) {}
};

#endif /* LIST_H_ */
