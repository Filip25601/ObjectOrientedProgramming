#include<iostream>
void MinMax(int* a, int& min, int& max, int n) {
	min = a[0];
	max = a[0];

	for (int i = 0; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
		if (a[i] > max) {
			max = a[i];
		}
	}
}
int main() {
	int n, min, max;
	std::cout << "Unesite broj elemenata niza: " << std::endl;
	std::cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		std::cout << "Unesite " << i+1 << "." << "clan niza: " << std::endl;
		std::cin >> a[i];
	}
	MinMax(a, min, max, n);

	std::cout << "Max je: " << max << std::endl;
	std::cout << "Min je: " << min << std::endl;
	
	return 0;
}