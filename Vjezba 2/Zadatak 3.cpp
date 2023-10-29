#include<iostream>

struct Vector {

	int* a;
	int lsize, fsize;

	void vector_new(int n = 0)
	{
		a = new int[n];
		lsize = n;
		fsize = 0;
	}
	void vector_delete()
	{
		delete &a;
	}

	void vector_push_back(int n)
	{
		if (lsize == fsize) {
			lsize *= 2;
			int* aa = new int[lsize];

			for (int i = 0; i < (lsize - 1); i++) {
				aa[i] = a[i];
			}

			delete a;

			a = aa;
		}

		a[fsize] = n;
		fsize++;
	}

	void vector_pop_back()
	{
		fsize -= 1;
	}

	int& vector_front()
	{
		return a[0];
	}

	int& vector_back()
	{
		return a[fsize - 1];
	}

	int vector_size()
	{
		return fsize;
	}
};


int main() {
	Vector vector;
	int n;

	vector.vector_new(4);

	std::cout << "Unesite element ili unesite 0 za prekid." << std::endl;
	std::cin >> n;

	while (n != 0) {
		vector.vector_push_back(n);
		std::cout << "Unesite element ili unesite 0 za prekid." << std::endl;
		std::cin >> n;
	}

	for (int i = 0; i < vector.vector_size(); i++) {
		std::cout << vector.a[i] << " ";
	}


	std::cout << "Prvi element vektora je: " << vector.vector_front() << std::endl;
	std::cout << "Zadnji element vektora je: " << vector.vector_back() << std::endl;

	std::cout << "Fizicka velicina vektora je: " << vector.vector_size() << std::endl;
	std::cout << "Logicka velicina vektora je: " << vector.lsize << std::endl;

	std::cout << "Brisanje zadnjeg elementa: " << std::endl;
	vector.vector_pop_back();
	for (int i = 0; i < vector.vector_size(); i++) {
		std::cout << vector.a[i] << " ";
	}

	std::cout << std::endl;
	std::cout << "Brisanje vektora: " << std::endl;
	vector.vector_delete();
	for (int i = 0; i < vector.vector_size(); i++) {
		std::cout << vector.a[i] << " ";
	}

	std::cout << std::endl;
}