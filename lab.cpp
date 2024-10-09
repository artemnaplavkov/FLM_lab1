#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

string gram1;
string gram2;

vector <char> gramG;
vector <char> gramP;

pair <char, char> GS;
pair <pair<char, char>, char> P;
vector <pair<pair<char, char>, char>> GPS;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



int main(){
	cout << "Insert grammatic G like this: {K,L,M,N} \n";
	cin >> gram1;
	for (int i = 0; i <= gram1.size(); i++) {
		if (gram1[i] != '{' and gram1[i] != '}' and gram1[i] != ',')
			gramG.push_back(gram1[i]);
	}
	for (int i = 0; i <= gramG.size()-1; i++) {
		cout << gramG[i] << " ";
	}
	cout << "\n";


	cout << "Insert grammatic P like this: {a,b,+,-} \n";
	cin >> gram2;
	for (int i = 0; i <= gram2.size(); i++) {
		if (gram2[i] != '{' and gram2[i] != '}' and gram2[i] != ',')
			gramP.push_back(gram2[i]);
	}
	for (int i = 0; i <= gramP.size()-1; i++) {
		cout << gramP[i] << " ";
	}
	cout << "\n";


	for (int i = 0; i <= 3; i++) {
		cout << "Insert " << i + 1 << " letter of grammar, by using ->  \n";
		cin >> gram1;

		if (gram1[1] != '-' || gram1[2] != '>' || (find(gramG.begin(), gramG.end(), gram1[1]) == gramG.end()) || (find(gramP.begin(), gramP.end(), gram1[4]) == gramP.end()))
		{
			cout << "incorrect insert";
			i--;
			continue;
		}

		if (gram1.size() == 4) {
			gramG.push_back('@');
			GS = make_pair(gram1[0], '@');
			P = make_pair(GS, gram1[3]);
			GPS.push_back(P);
		}

		GS = make_pair(gram1[0], gram1[4]);
		P = make_pair(GS, gram1[3]);
		GPS.push_back(P);


		
		if (gram1[5] == '|' && !(!gram1[6]) && !gram1[7]) {
			gramG.push_back('@');
			GS = make_pair(gram1[0], '@');
			P = make_pair(GS, gram1[5]);
			GPS.push_back(P);
		}
		else if (gram1[5] == '|' && !(!gram1[6]) && !(!gram1[7])) {
			GS = make_pair(gram1[0], gram1[7]);
			P = make_pair(GS, gram1[6]);
			GPS.push_back(P);
		}
			
		
	}


	for (int i = 0; i <= GPS.size() - 1; i++) {
		cout << GPS[i].first.first << " -> " << GPS[i].second <<  " -> " << GPS[i].first.second <<" \n";
	}

	for (int i = 0; i <= gramG.size(); i++) {
		for (int j = 0; j <= (alphabet.size() - gramG.size()); i++) {
			if (gramG[i] == alphabet[j])
				alphabet.erase(alphabet[j]);
		}

	for (int i = 0;i<=GPS.size();i++) {

		char letter_first = GPS[i].first.first;
		char letter_second = GPS[i].second;
		int flag = 0;

		for (int j = i; j <= GPS.size(); j++) {
			if (letter_first == GPS[j].first.first && flag > 0) {
				GPS[j].second = alphabet[0];
				gramG.push_back(alphabet[0]);
				alphabet.erase(alphabet[0]);
			}
			else {
				flag++; 
			}
		}
	}

	for (int i = 0; i <= GPS.size() - 1; i++) {
		cout << GPS[i].first.first << " -> " << GPS[i].second << " -> " << GPS[i].first.second << " \n";
	}

	return 0;
}








	/*
	for (int i = 0; i <= gramP.size(); i++) {
		char first_letter = GPS[i].first.first;
		char second_letter = GPS[i].first.second;

		int flag = 0;
		for (int j = 0; j <= gramP.size(); j++) {
			if (second_letter == GPS[j].first.first)
				flag = 1;
				continue;
			
		}
		if (flag==0)
			gramG.push_back('@');
		//if (gram1[gram1.size() - 1] == gramP[i])
			//gramG.push_back('@');
	}
	*/
