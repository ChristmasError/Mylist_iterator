#include"_list.h"
#include<iostream>
using namespace std;
template<class T>
void display(T start, T end) {
	cout << endl;
	for (T i = start; i != end; i++) {
		cout << *i << endl;
	}
	cout << endl;
}

int main() {
	list<int>a;
	for (int i = 0; i < 5; i++) {
		a.push_back(i);
	}
	list<int>::iterator itb = a.begin();
	list<int>::iterator ite = a.end();
	display(itb, ite); // 0 1 2 3 4

	a.insert(ite, 5);
	display(itb, ite); //0 1 2 3 4 5 

	cout << *itb<<endl; // 0
	cout<<*(++itb)<<endl;//1
	cout << *(--ite) << endl<<endl;//5

	a.pop_back();
	display(a.begin(), a.end());// 0 1 2 3 4

	
	system("pause");
	return 0;
}