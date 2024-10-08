#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;


string gram1;
char id;
pair <char, char> GS;
pair <pair<char, char>, char> P;
vector <pair<pair<char,char>, char>> GPS;
vector <char> letters;


/*
vector <char> G;
vector <char> P;
vector <char> S;

void gramm() {
}
*/

int main(){
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

		if (gram1[5] == '|' && gram1[6] && gram1[7]) {
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
		}
	}


	return 0;
}

//for (int i = 0; i <= letters.size(); i++) {
	//if (GPS[i][0] ! letters)


/*
	G.push_back(gram1[0]);
	P.push_back(gram1[3]);
	S.push_back(gram1[4]);
	if (gram1[5] == "|")
		P.push_back(gram1[6]);
		S.push_back(gram1[7]);
*/

//cout << G[0];


