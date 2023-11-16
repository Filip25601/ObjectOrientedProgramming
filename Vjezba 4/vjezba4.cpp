#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

int brojanje_podstringa(string main,string sub) 
{
    int br = 0;
    size_t pozicija = 0;

    while ((pozicija = main.find(sub, pozicija)) != string::npos) {
        br++;
        pozicija += sub.length();
    }

    return br;
}

void MakniRazmake(string& string)
 {
    size_t poz = 0;
	for (poz = string.find(' ');poz != string::npos;poz = string.find(' ',poz + 1))
     {
		if (string[poz + 1] == ',') {
			string[poz] = ',';
			string[poz + 1] = ' ';
		}
		else if (string[poz] == ' ' && string[poz + 1] == ' ') {
			string.erase(poz + 1, 1);
		}
	}
}

void Preokreni() {

	int n;
	cout << "Unesite broj stringova: ";
	cin >> n;
	vector<string> str(n);

	for (int i = 0; i < n; i++) {
		cout << "Unesite " << i + 1 << " string: ";
		cin >> str[i];
		reverse(str[i].begin(), str[i].end());
	}

	sort(str.begin(), str.end());

	for (int i = 0; i < n; i++) {
		cout << str[i] << endl;
	}
}

bool samoglasnik(char c)
{
	string samoglasnik = "aeiouAEIOU";
	return samoglasnik.find(c) != string::npos;
}

string prevedi(string& str)
{
	string novi = str;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
		{
			if (samoglasnik(str[i]))
			{
				if (i == 0)
				{
					novi = str + "hay";
				}
				else
				{
					novi = str.substr(i) + str.substr(0, i) + "ay";
				}
				break;
			}
		}
	}
	return novi;
}

int main ()
{
string glavniString = "Danas je dobar dan";
string podstring = "je";
string rec = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno.";


int brojPojavljivanja = brojanje_podstringa(glavniString, podstring);
cout << "Podstring " << podstring << " se pojavljuje " << brojPojavljivanja << " puta u glavnom stringu." <<endl;

MakniRazmake(rec);
cout << rec << endl;

Preokreni();

vector<string> sentences = {
        "What time is it",
        "Hello, how are you",
        "Along came a spider",
        "Might as Well Be on Mars"
    };

int randomIndex = rand() % sentences.size();
string selectedSentence = sentences[randomIndex];

string randomString = sentences[randomIndex];
	string pigLatin = "";
	string str;
	istringstream iss(randomString);
	while (iss >> str)
	{
		if (!pigLatin.empty())
		{
			pigLatin += " ";
		}
		pigLatin += prevedi(str);
	}
	cout << "Random string: " << randomString << endl;
	cout << "Pig Latin transformacija: " << pigLatin << endl;


return 0;
}
