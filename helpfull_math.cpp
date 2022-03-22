#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int tab[4];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string sumsonik_ogonik;
	cin >> sumsonik_ogonik;
	int ile_plusow = sumsonik_ogonik.size() / 2;
	for (int i = 0; i < sumsonik_ogonik.size(); ++i) {
		if (sumsonik_ogonik[i] == '1') {
			++tab[1];
		}
		else if (sumsonik_ogonik[i] == '2') {
			++tab[2];
		}
		else if (sumsonik_ogonik[i] == '3') {
			++tab[3];
		}
	}
	for (int i = 0; i < tab[1]; ++i) {
		cout << "1";
		if (ile_plusow > 0) {
			cout << "+";
			--ile_plusow;
		}
	}
	for (int i = 0; i < tab[2]; ++i) {
		cout << "2";
		if (ile_plusow > 0) {
			cout << "+";
			--ile_plusow;
		}
	}
	for (int i = 0; i < tab[3]; ++i) {
		cout << "3";
		if (ile_plusow > 0) {
			cout << "+";
			--ile_plusow;
		}
	}
}