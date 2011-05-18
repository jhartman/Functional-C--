#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <string>
#include "ArrayBuffer.h"
#include "CopyOnWriteArrayBuffer.h"
#include "List.h"

struct ToCharArray {
	ArrayBuffer<char> operator()(string elem) {
		ArrayBuffer<char> result;
		for(unsigned int i = 0; i < elem.size(); i++)
			result += elem[i];
		return result;
	}
};

template<typename T, typename Iterable>
bool search(Iterable collection, T value) {
	return collection.contains(value);
}

void testArrayBuffer() {
	ArrayBuffer<int> iterable = {5, 1, 3, 2};
	iterable[0] = 4;
	iterable += 4;

	iterable.map(Square()).foreach(Print());

	std::vector<string> text0 = {"Lorem", "Ipsum", "Delta"};
	ArrayBuffer<string> text(text0);

	auto flattenedText = text.flatMap([](string elem) { return ToCharArray()(elem); } );
	flattenedText.foreach(Print());
}

void testCopyOnWriteArrayBuffer() {
	vector<int> some_list = {5, 1, 3, 2};

	auto iterable = CopyOnWriteArrayBuffer<int>(some_list);
	auto iterable2 = iterable.updated(0, 2);
	assert(iterable[0] == 5);
	assert(iterable2[0] == 2);

	iterable.map(Square()).foreach(Print());
	auto squared = iterable.map(Square());
	assert(search(squared, 25) == true);

	assert(!squared.filter([](int x) { return (x == 25); }).isEmpty());
	assert(!squared.filter([](int x) { return (x == 24); }).isEmpty());
}

void testList() {
	auto list = List<int>(1);

	auto list2 = list + 2;
	List<int> list3 = {1, 2, 3, 4};

	list2.foreach(Print());
	list3.foreach(Print());

	list3.reverse().foreach(Print());

	list3.map(Square()).foreach(Print());

	cout<<"The size is "<<list3.size()<<endl;
}

int main() {
	cout<<"Test started"<<endl;
//	testArrayBuffer();
//	testCopyOnWriteArrayBuffer();
	testList();
	cout<<"Test finished"<<endl;
}

