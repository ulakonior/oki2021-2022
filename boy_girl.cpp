#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int tab_letters[26];

int main() { 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string nick;
	cin >> nick;
	int number_of_leters = 0;
	for (int i = 0; i < nick.size(); ++i) {
		if (tab_letters[nick[i]-'a'] == 0) {
			++number_of_leters;
			tab_letters[nick[i] - 'a'] += 1;
		}
	}
	if (number_of_leters % 2 == 0) {
		cout << "CHAT WITH HER!";
	}
	else {
		cout << "IGNORE HIM!";
	}
}