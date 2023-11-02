#include "zadatak01.hpp"
#include "zadatak01.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	zadatak01 vec;
	vector<int> v;
	vector<int> v1;
	int el;
	int a;
	int b;
	cout << "Unesi broj elemenata vektora: " << endl;
	cin >> el;
	vec.VectorInput(v, el);
	vec.VectorOutput(v);
	cout << endl;

	cout << "Unesi raspon clanova vektora [a,b]: " << endl;
	cin >> a >> b;
	vec.VectorInputLimits(v1, a, b);
	vec.VectorOutput(v1);
	return 0;
}

