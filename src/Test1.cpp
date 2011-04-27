///*
// * Test1.cpp
// *
// *  Created on: Sep 17, 2010
// *      Author: jhartman
// */
//
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//
//struct ListComparator : public binary_function<int, int, bool> {
//    bool operator()(int x, int y) { return x < y; }
//};
//
//
////bool comparisonFn(int x, int y) {
////	return x < y;
////}
//
//int main() {
//	vector<int> some_list;
//	some_list.push_back(2);
//	some_list.push_back(3);
//	some_list.push_back(1);
//	some_list.push_back(4);
//	some_list.push_back(5);
//
//	int total = 0;
//
//	auto value = 5;
//	cout<<value<<endl;
//
//	auto lambda = [](int x, int y) { return x + y; };
//	auto value2 = lambda(5, 6);
//
//	cout<<value2<<endl;
//
//	struct Accumulator : public unary_function<int, int> {
//		int * value;
//	    Accumulator(int * v) { value = v; }
//		int operator()(int x) { *value += x; return *value; }
//	};
//
//
////	for_each(some_list.begin(), some_list.end(), [](int elem) { total += elem; });
//	for_each(some_list.begin(), some_list.end(), Accumulator(&total));
//
//	ListComparator comparator;
//
//	sort(some_list.begin(), some_list.end(), [](int x, int y) { return x < y; });
//
////	sort(some_list.begin(), some_list.end(), comparator);
////	sort(some_list.begin(), some_list.end(), comparisonFn);
//
//	for(int i = 0; i < some_list.size(); i++)
//		cout<<some_list[i]<<endl;
//
//	cout<<"Total: "<<total<<endl;
//	return 0;
//}
