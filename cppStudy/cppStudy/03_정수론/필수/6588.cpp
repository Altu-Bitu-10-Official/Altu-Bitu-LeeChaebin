#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int MAX = 1000000; //백만
bool prime[MAX + 1];

//에라토스테네스의 체 - 소수 먼저
void getPrime() {
	//초기화 - true
	for (int i = 2; i <= MAX; i++)
		prime[i] = true;

	for (int i = 2; i <= sqrt(MAX); i++) {
		if (prime[i] == true) {
			for (int j = i * i; j <= MAX; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getPrime();

	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			break;

		bool found = false;

		for (int a = 3; a <= n / 2; a += 2) { //홀수
			int b = n - a;

			if (prime[a]==true && prime[b]==true) { //둘 다 소수
				cout << n << " = " << a << " + " << b<<"\n";
				found = true;
				break; // b-a가 최대일 때 구하고 탈출
			}
		}
		if (!found) {
			cout << "Goldbach's conjecture is wrong.";
		}
	}
	return 0;
}