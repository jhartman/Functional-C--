
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <algorithm>

template<typename T, typename V>
class Fn {
	virtual V operator()(const T & from);
};

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

#endif /* FUNCTIONS_H_ */
