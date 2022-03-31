#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long liczba, ile = 0, cyfra;
	cin >> liczba;
	while (liczba > 0){
		cyfra = liczba % 10;
		if (cyfra == 4 || cyfra == 7) {
			++ile;
		}
		liczba /= 10;
	}
	if (ile == 4 || ile == 7) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}