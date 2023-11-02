/*Koristeci funkcije iz prvog zadatka unijeti dva vektora i formirati novi vektor koji
se sastoji od elemenata iz prvog vektora koji nisu u drugom vektoru*/
#include <iostream>
#include <vector>
#include <string>
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
void input_vector1(vector<int>& v, int a, int b)
{
	cout << "Unesi elemente vektora: " << endl;
	int n;
	for (;;)
	{
		cin >> n;
		if (n >= a && n <= b)
		{
			v.push_back(n);
		}
		else
			break;
	}
}
void new_vector(vector<int> v, vector <int> v1, vector <int>& v2)
{
	int size_v, size_v1;
	size_v = v.size();
	size_v1 = v1.size();
	for (int i = 0; i < size_v; i++)
	{
		int flag =1;
		for (int j = 0; j < size_v1; j++)
		{
			if (v[i] == v1[j])
			{
				flag =0;
				break;
			}
		}
		if (flag >=1)
		{
			v2.push_back(v[i]);
		}
	}
}
void output_vector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}
int main(void)
{
	vector<int> v;
	vector<int> v1;
	vector<int> v2;
	int el;
	int a;
	int b;
	cout << "Unesi broj elemenata vektora: " << endl;
	cin >> el;
	input_vector(v, el);
	cout << "Prvi niz ->  ";
	output_vector(v);
	cout << endl;
	cout << "Unesi raspon clanova vektora [a,b]: " << endl;
	cin >> a >> b;
	input_vector1(v1, a, b);
	cout << "Drugi niz ->  ";
	output_vector(v1);
	cout << endl << endl;
	new_vector(v, v1, v2);
	cout << "Novi niz s elementima prvog niza bez elemenata drugog niza ->  ";
	output_vector(v2);
	return 0;

}
