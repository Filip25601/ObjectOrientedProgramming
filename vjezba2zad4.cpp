#include <iostream>
#include<iomanip>

struct Matrica {

	int m, n;
	float a, b;
	float** mat;

	void Unos();
	void Generiraj(int, int, float, float);
	void Zbroji(Matrica mat);
	void Oduzmi(Matrica mat);
	void Pomnozi(Matrica mat);
	void Transponiraj();
	void Print();
};

void Matrica::Unos() {
	std::cout << "Unesite velicinu matrice mxn (Format:m n): ";
	std::cin >> m >> n;

	mat = new float* [m];
	for (int i = 0; i < n; i++) {
		mat[i] = new float[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "Unesite " << "[" << i + 1 << "]" << "[" << j + 1 << "]" << "element matrice: ";
			std::cin >> mat[i][j];
		}
	}
}

void Matrica::Generiraj(int M, int N, float a, float b) {
	m = M;
	n = N;
	mat = new float* [m];
	for (int i = 0; i < n; i++) {
		mat[i] = new float[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			float random = ((float)rand()) / (float)RAND_MAX;
			float diff = b - a;
			float r = random * diff;
			mat[i][j] = (a + r);
		}
	}
}

void Matrica::Zbroji(Matrica mat1) {
	if (m == mat1.m && n == mat1.n) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] += mat1.mat[i][j];
			}
		}
	}
	else {
		std::cout << "Matrice nisu kompatibilne za zbrajanje." << std::endl;
	}
}

void Matrica::Oduzmi(Matrica mat1) {
	if (m == mat1.m && n == mat1.n) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] -= mat1.mat[i][j];
			}
		}
	}
	else {
		std::cout << "Matrice nisu kompatibilne za oduzimanje." << std::endl;
	}
}

void Matrica::Pomnozi(Matrica mat1) {
	Matrica temp;
	if (n == mat1.m) {
		temp.Generiraj(n, mat1.m, 0, 0);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < mat1.n; j++) {
				for (int k = 0; k < n; k++) {
					temp.mat[i][j] += mat[i][k] * mat1.mat[k][j];
				}
			}
		}

		delete[] mat;
		mat = temp.mat;
	}
	else {
		std::cout << "Matrice nisu kompatibilne za mnozenje." << std::endl;
	}
}

void Matrica::Transponiraj() {
	Matrica temp;
	temp.Generiraj(m, n, 0, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp.mat[i][j] = mat[j][i];
		}
	}

	delete[] mat;
	mat = temp.mat;
}

void Matrica::Print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setprecision(4) << std::right << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {

	Matrica mat, mat1;

	std::cout << "Unost matrice: " << std::endl;
	mat.Unos();
	mat.Print();
	std::cout << "Generiranje matrice: " << std::endl;
	mat1.Generiraj(2,2,1,2);
	mat1.Print();
	std::cout << "Transponiranje matrice: " << std::endl;
	mat.Transponiraj();
	mat.Print();
	std::cout << "Mnozenje matrice: " << std::endl;
	mat.Pomnozi(mat);
	mat.Print();
	std::cout << "Zbrajanje matrice: " << std::endl;
	mat.Zbroji(mat1);
	mat.Print();
	std::cout << "Oduzimanje matrice: " << std::endl;
	mat.Oduzmi(mat1);
	mat.Print();

	return 0;
}