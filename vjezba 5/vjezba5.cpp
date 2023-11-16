#include<iostream>
#include<algorithm>
#include<ctime>
#include<string>

class Karta {
public:
	Karta() { broj = 1; zog = " "; }
	int broj;
	std::string zog;
};

class Igrac {
public:
	Igrac(){bodovi=0;}
	std::string ime;
	Karta karte[10];
	int bodovi;
	void Akuza();
};

class Mac {
public:
	Karta mac[40];
	void GenerirajMac();
	void PromijesajMac();
	void PodijeliKarte(Igrac igraci[], int brojIgraca);

};


void Mac::GenerirajMac() {
	std::string zogovi[4] = { "Spade", "Dinari", "Bati", "Kupe" };
	int br = 0;
	int n = 1, h = 11;

	while (br < 40) {
		if (br < 10) {
			for (int i = 0; i < 10; i++) {
				mac[i].zog = zogovi[0];
				if (n <= 7) {
					mac[i].broj = n;
					n++;
				}
				else {
					mac[i].broj = h;
					h++;
				}
				br++;
			}
			n = 1;
			h = 11;
		}
		if (br < 20) {
			for (int j = 10; j < 20; j++) {
				mac[j].zog = zogovi[1];
				if (n <= 7) {
					mac[j].broj = n;
					n++;
				}
				else {
					mac[j].broj = h;
					h++;
				}
				br++;
			}
			n = 1;
			h = 11;
		}
		if (br < 30) {
			for (int k = 20; k < 30; k++) {
				mac[k].zog = zogovi[2];
				if (n <= 7) {
					mac[k].broj = n;
					n++;
				}
				else {
					mac[k].broj = h;
					h++;
				}
				br++;
			}
			n = 1;
			h = 11;
		}
		if (br < 40) {
			for (int z = 30; z < 40; z++) {
				mac[z].zog = zogovi[3];
				if (n <= 7) {
					mac[z].broj = n;
					n++;
				}
				else {
					mac[z].broj = h;
					h++;
				}
				br++;
			}
			n = 1;
			h = 11;
		}
	}
}

void Mac::PromijesajMac() {
	std::srand(std::time(0));
	std::random_shuffle(&mac[0], &mac[40]);
}

void Mac::PodijeliKarte(Igrac igraci[], int brojIgraca) {
	int j = 0;
	if (brojIgraca == 2) {
		for (int i = 0; i < 10; i++, j++) {
			igraci[0].karte[j] = mac[i];
		}
		j = 0;
		for (int i = 10; i < 20; i++, j++) {
			igraci[1].karte[j] = mac[i];
		}
		j = 0;
	}
	else if (brojIgraca == 4) {
		for (int i = 0; i < 10; i++, j++) {
			igraci[0].karte[j] = mac[i];
		}
		j = 0;
		for (int i = 10; i < 20; i++, j++) {
			igraci[1].karte[j] = mac[i];
		}
		j = 0;
		for (int i = 20; i < 30; i++, j++) {
			igraci[2].karte[j] = mac[i];
		}
		j = 0;
		for (int i = 30; i < 40; i++, j++) {
			igraci[3].karte[j] = mac[i];
		}
		j = 0;
	}
}

void Igrac::Akuza() {
	int a = 0, b = 0, c = 0;
	int spade = 0, dinari = 0, bati = 0, kupe = 0;
	for (int i = 0; i < 10; i++) {
		switch (karte[i].broj) {
			case 1:
				a++;
				break;
			case 2:
				b++;
				break;
			case 3:
				c++;
				break;
			default:
				break;
		}
		switch (karte[i].broj) {
		case 1:
			if(karte[i].zog == "Spade")
				spade++;
			if (karte[i].zog == "Dinari")
				dinari++;
			if (karte[i].zog == "Bati")
				bati++;
			if (karte[i].zog == "Kupe")
				kupe++;
			break;
		case 2:
			if (karte[i].zog == "Spade")
				spade++;
			if (karte[i].zog == "Dinari")
				dinari++;
			if (karte[i].zog == "Bati")
				bati++;
			if (karte[i].zog == "Kupe")
				kupe++;
			break;
		case 3:
			if (karte[i].zog == "Spade")
				spade++;
			if (karte[i].zog == "Dinari")
				dinari++;
			if (karte[i].zog == "Bati")
				bati++;
			if (karte[i].zog == "Kupe")
				kupe++;
			break;
		default:
			break;
		}
	}

	if (a == 4 || b == 4 || c == 4) {
		bodovi += 4;
	}
	if (a == 3 || b == 3 || c == 3) {
		bodovi += 3;
	}
	if (spade == 3 || kupe == 3 || dinari == 3 || bati == 3) {
		bodovi += 3;
	}

	std::cout << "Bodovi iz akuze su: " << bodovi << std::endl;
}

int main() {
	int brojIgraca;
	Mac mac;
	Igrac igraci[4];

	std::cout << "Unesite broj igraca(2 ili 4): ";
	std::cin >> brojIgraca;

	mac.GenerirajMac();
	mac.PromijesajMac();
	mac.PodijeliKarte(igraci, brojIgraca);

	for (int i = 0; i < brojIgraca; i++) {
		std::cout << "Unesite ime " << i + 1 << " igraca: ";
		std::cin >> igraci[i].ime;
	}

	for (int j = 0; j < brojIgraca; j++) {
		std::cout << igraci[j].ime << std::endl;
		igraci[j].Akuza();
		for (int i = 0; i < 10; i++) {
			std::cout << igraci[j].karte[i].zog << " " << igraci[j].karte[i].broj << std::endl;
		}
	}

	return 0;
}