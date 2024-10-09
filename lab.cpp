#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;


string gram1;
vector <char> gramG;
vector <char> gramP;
char id;
pair <char, char> GS;
pair <pair<char, char>, char> P;
vector <pair<pair<char,char>, char>> GPS;
vector <char> letters;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main(){
	cout << "Insert grammatic G like this: {K,L,M,N} \n";
	cin >> gram1;
	for (int i = 0; i <= gram1.size(); i++) {
		if (gram1[i] != '{' and gram1[i] != '}' and gram1[i] != ',')
			gramG.push_back(gram1[i]);
	}

	cout << "Insert grammatic P like this: {a,b,+,-} \n";
	cin >> gram1;
	for (int i = 0; i <= gram1.size(); i++) {
		if (gram1[i] != '{' and gram1[i] != '}' and gram1[i] != ',')
			gramP.push_back(gram1[i]);
	}
	


	for (int i = 0; i <= 3; i++) {
		cout << "Insert " << i + 1 << " letter of grammar, by using ->  \n";
		cin >> gram1;
		if (gram1[1] != '-' || gram1[2] != '>')
		{
			cout << "incorrect insert";
			return 0;
		}

		GS = make_pair(gram1[0], gram1[4]);
		P = make_pair(GS, gram1[3]);
		GPS.push_back(P);

		for (int i = 0; i <= letters.size(); i++) {
			int flag = 1;
			if (gram1[0] == letters[i])
				flag = 0;
			else if (i == letters.size() && flag == 1)
				letters.push_back(gram1[0]);
		}
		for (int i = 0; i <= letters.size(); i++) {
			int flag = 1;
			if (gram1[4] == letters[i])
				flag = 0;
			else if (i == letters.size() && flag == 1)
				letters.push_back(gram1[4]);
		}

		if (gram1[5] == '|' && !(!gram1[6]) && !(!gram1[7])) {
			GS = make_pair(gram1[0], gram1[6]);
			P = make_pair(GS, gram1[7]);
			GPS.push_back(P);

			for (int i = 0; i <= letters.size(); i++) {
				int flag = 1;
				if (gram1[0] == letters[i])
					flag = 0;
				else if (i == letters.size() && flag==1)
				letters.push_back(gram1[0]);
			}
			for (int i = 0; i <= letters.size(); i++) {
				int flag = 1;
				if (gram1[7] == letters[i])
					flag = 0;
				else if (i == letters.size() && flag == 1)
					letters.push_back(gram1[7]);

			}

			for (int i = 0; i <= gramP.size(); i++) {
				if (gram1[gram1.size() - 1] == gramP[i])
				{
					gramG.push_back('@');
			
				for (int i = 0; i <= letters.size(); i++) {
					int flag = 1;
					if (gram1[0] == letters[i])
						flag = 0;
					else if (i == letters.size() && flag == 1)
						letters.push_back(gram1[0]);
				}
				for (int i = 0; i <= letters.size(); i++) {
					int flag = 1;
					if (gram1[gram1.size() - 1] == letters[i])
						flag = 0;
					else if (i == letters.size() && flag == 1)
						letters.push_back(gram1[gram1.size() - 1]);
				}
				}
		}

			for (int i = 0; i <= gramG.size(); i++) {
				for (int j = 0; j <= (alphabet.size() - gramG.size()); i++) {
					if (gramG[i] == alphabet[j])
						alphabet.erase(alphabet[j]);
				}
			}

			for (int i = 0; i <= gramP.size(); i++) {
				pair <pair<char, char>, char> letter = GPS[i];
				pair<char, char> letter1 = letter.first;

				char letter_first = letter1.first;
				char letter_second = GPS[i].second;
				int flag = 0;

				for (int j = 0; j <= gramP.size(); j++) {
					if (letter_first == GPS[j].second)
						flag++;
					else if (flag > 1) {
						GPS[j].second = alphabet[0];
						gramG.push_back(alphabet[0]);
						alphabet.erase(alphabet[0]);
					}
				}


				/*
				for (int i = 0; i <= gramP.size(); i++) {
					for (int j = 0; j <= gramP.size(); j++) {
						if (letter1.first == GPS[j].second)
							flag++;
						else if (flag > 1) {
							GPS[i].second = alphabet[0];
							alphabet.erase(alphabet[1]);
						}

					}
					*/
				}
			for (int i = 0; i <= GPS.size(); i++) {
				cout << gramG[i];
			}
			}
	}
		return 0;
	}
	/*
	for (int i = 0; i <= letters.size(); i++)
	{
		//int counter = 0;
		int flag = 1;
		for (int j = 0; j <= GPS.size(); j++)
		{
			if (letters[i] == GPS[][])
		}
	}
	*/
