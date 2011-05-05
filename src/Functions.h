
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <algorithm>
using namespace std;

struct Plus {
	template<typename T, typename V>
	auto operator()(T a, V b) -> decltype(a + b) { return a + b; };
};

struct Minus {
	template<typename T, typename V>
	auto operator()(T a, V b) -> decltype(a - b) { return a - b; };
};

struct Times {
	template<typename T, typename V>
	auto operator()(T a, V b) -> decltype(a * b) { return a * b; };
};

struct Divide {
	template<typename T, typename V>
	auto operator()(T a, V b) -> decltype(a / b) { return a / b; };
};

struct Max {
	template<typename T>
	auto operator()(T a, T b) -> decltype(a) { return max(a, b); };
};

struct Min {
	template<typename T>
	auto operator()(T a, T b) -> T { return min(a, b); };
};

struct Square {
	template<typename T>
	auto operator()(const T &a) -> T { return a * a; };
};

struct Print {
	template<typename T>
	auto operator()(T a) -> void { cout<<a<<endl; };
};


//template<typename T>
//class Print : public Function1<T, void>{
//public:
//	virtual void operator()(const T & elem) { cout<<elem<<endl; }
//};
//
//template<typename T>
//class Square : public Function1<T, T> {
//public:
//	T operator()(const T & elem) { return elem * elem; }
//};


#endif /* FUNCTIONS_H_ */
