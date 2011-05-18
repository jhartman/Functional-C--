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

	List<T> tail() const {
		auto null = shared_ptr<Cell<T> >();
		return List<T>((cell == null) ? cell : cell -> next);
	}

	int size() const {
		return foldLeft(0, [](int acc, T elem) { return acc + 1; });
	}

	bool contains(T elem) const {
		auto p = cell;
		auto null = shared_ptr<Cell<T> >();
		while(p != null) {
			if((p -> data) == elem)
				return true;
			p = p -> next;
		}
		return false;
	}

	List<T> drop(int n) const {
		auto p = cell;
		int i = 0;
		auto null = shared_ptr<Cell<T> >();
		while(p != null && i < n) {
			i++;
			p = p -> next;
		}
		return List<T>(p);
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

	template<typename Fn>
	auto map(Fn fn) -> const List<decltype(fn(declval<T>()))> {
		List<decltype(fn(declval<T>()))> result;

		return foldLeft(result,
				[&fn](const List<decltype(fn(declval<T>()))> & acc, const T & elem) {
			return acc + fn(elem);
		}).reverse();
	}

	template<typename Fn>
	List<T> filter(Fn fn) const {
		List<T> result;

		return foldLeft(result,
				[&fn](const List<T> & acc, const T & elem) {
			return (fn(elem)) ? (acc + elem) : acc;
		}).reverse();
	}

	template<typename V>
	auto zip(List<V> that) -> const List<pair<T, V> > {
		auto END1 = shared_ptr<Cell<T> >();
		auto END2 = shared_ptr<Cell<V> >();

		auto p1 = cell;
		auto p2 = that -> cell;

		List<pair<T, V> > result;
		while(p1 != END1 && p2 != END2) {
			result = result + make_pair(p1 -> data, p2 -> data);
		}
		return result.reverse();
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
