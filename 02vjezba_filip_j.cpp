#include <iostream>

void funkcija(int popis[], int f, int& najmanji, int& najveci)
{
	najveci = popis[0];
	najmanji = popis[0];
	for (int i=0; i < f; i++)
	{
		if (popis[i] > najveci)
		{
			najveci = popis[i];
		}
		if (popis[i] < najmanji)
		{
			najmanji = popis[i];
		}
		}
		
}

int& nova(int* niz,int size,int broj)
{
	for (int i = 0; i < size; i++)
	{
		if (broj == i)
		{
			return niz[i];
			break;
		}
	}
}

int main()
{/*
	int f = 6;
	int popis[6] = {5, 6, 12, 1, 14, 7};
	int najmanji;
	int najveci;
	funkcija(popis, f, najmanji, najveci);
	std::cout << "Najmanji broj je\n " << najmanji << std::endl;
	std::cout << "Najveci broj je\n " << najveci << std::endl;
	*/
	int niz[5] = { 1 , 4 , 6 ,12,5 };
	int broj;
	std::cout << "unesi zeljeni broj" << std::endl;
	std::cin >> broj;
	int& index = nova(niz, 5, broj);
	std::cout << index << std::endl;
	niz[broj] = index + 1;
	std::cout << "rezultat je:"<<niz[broj] << std::endl;

	


}