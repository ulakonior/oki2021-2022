#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int tab_g[26];
int tab_s[26];

int main() { 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string g1, g2, g3;
	string s1, s2, s3;
	int number_of_greens = 0;
	int number_of_yellows = 0;
	cin >> g1 >> g2 >> g3;
	cin >> s1 >> s2 >> s3;
	for (int i = 0; i < 3; ++i) {
		if (g1[i] == s1[i]) {
			++number_of_greens;
		}
		else {
			++tab_g[g1[i] - 'A'];
			++tab_s[s1[i] - 'A'];
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (g2[i] == s2[i]) {
			++number_of_greens;
		}
		else {
			++tab_g[g2[i] - 'A'];
			++tab_s[s2[i] - 'A'];
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (g3[i] == s3[i]) {
			++number_of_greens;
		}
		else {
			++tab_g[g3[i] - 'A'];
			++tab_s[s3[i] - 'A'];
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (tab_s[i] > 0) {
			number_of_yellows += min(tab_s[i], tab_g[i]);
		}
	}
	cout << number_of_greens << "\n" << number_of_yellows;
}