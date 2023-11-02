/*Napisati funkciju za uklanjanje elementa iz vektora sa što manje operacija.
Poredak elemenata u vektoru nije bitan.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void input_vector(vector<int>& v, int el)
{
	int n;
	cout << "Unesi elemente vektora: " << endl;
	for (int i = 0; i < el; i++)
	{
		cin >> n;
		v.push_back(n);
	}
}
void output_vector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}
void delete_el(vector<int>& v,int index)
{	
	//int temp = v[index];
	v[index] = v.back();
	//v[index] = v[v.size() - 1];
	//v[v.size() - 1] = temp;
	v.pop_back();
}
int main(void)
{
	vector<int> v;
	int el;
	int el2;
	cout << "Unesi broj elemenata vektora: " << endl;
	cin >> el;
	input_vector(v, el);
	
	cout << "Unesi broj elementa kojeg zelis ukloniti: " << endl;
	cin >> el2;
	delete_el(v,el2-1);
	output_vector(v);
	return 0;
}

