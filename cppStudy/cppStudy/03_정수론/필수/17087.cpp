#include<iostream>
#include<algorithm>

using namespace std;

//S~동생까지 거리들의 최대공약수

int getGcd(int a, int b) {
	if (b == 0)
		return a;
	return getGcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
	cin >> n >> s;

	int d = 0;

	for (int i = 0; i < n; i++) {
		int dong;
		cin >> dong;
		
		//s~dong까지 거리
		int k = abs(dong - s);
		if (i == 0)
			d = k;
		else {
			d = getGcd(d, k);
		}
	}
	cout << d;
	return 0;
}