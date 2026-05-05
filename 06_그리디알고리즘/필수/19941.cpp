//¿Þ->¿À·Î ÇÜ¹ö°Å Ã¼Å©
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, k, cnt=0;
	cin >> n >> k;
	
	string table;
	cin >> table;

	for (int i = 0; i < n; i++) {
		if (table[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) {
				if (j < 0 || j >= n) continue;

				if (table[j] == 'H') {
					cnt++;
					table[j] = '.';
					break;
				}
			}
		}



	}
	cout << cnt;
}