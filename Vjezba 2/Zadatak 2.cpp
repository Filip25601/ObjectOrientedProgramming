#include<iostream>
using namespace std;

int& Funkcija(int* a) {
	int& ref = a[2];
	return ref;
}

int main() {
	int n;
	cout << "Unesite broj elemenata niza: ";
	cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "Unesite " << i + 1 << "." << "clan niza: " << endl;
		cin >> a[i];
	}
	Funkcija(a)++;
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}