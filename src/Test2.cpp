#include <vector>
#include <iostream>
#include <algorithm>
#include "ArrayBuffer.h"
#include "CopyOnWriteArrayBuffer.h"
#include <string>

using namespace std;

class Print {
	public:
	template<typename T>
	void operator()(T elem) { cout<<elem<<endl; }
};

template<typename T>
class Square : Fn<T, T> {
public:
	virtual T operator()(const T &elem) { return elem * elem; }
};

struct ToCharArray {
	ArrayBuffer<char> operator()(string elem) {
		ArrayBuffer<char> result;
		for(unsigned int i = 0; i < elem.size(); i++)
			result += elem[i];
		return result;
	}
};

vector<int> some_list = {5, 1, 3, 2};

//bool testCopyOnWriteArrayBuffer() {
//	Iterable<int, CopyOnWriteArrayBuffer<int>> iterable = CopyOnWriteArrayBuffer(some_list);
//	iterable.map(Square()).foreach(Print())
//}

int main() {
	vector<int> some_list = {5, 1, 3, 2};
	ArrayBuffer<int> iterable(some_list);
	iterable += 4;
	iterable.map(Square<int>()).foreach(Print());

	vector<string> text0 = {"Lorem", "Ipsum", "Delta"};
	ArrayBuffer<string> text(text0);

	auto flattenedText = text.flatMap([](string elem) { return ToCharArray()(elem); } );
	flattenedText.foreach(Print());
}

