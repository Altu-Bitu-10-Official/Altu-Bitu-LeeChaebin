#include<iostream>
#include<string>
#include <vector>
#include<algorithm>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	vector<int> A, B;
	for (int i = a.length() - 1; i >= 0; i--)
		A.push_back(a[i] - '0');
	for (int i = b.length() - 1; i >= 0; i--)
		B.push_back(b[i] - '0');

	int maxLength = max(A.size(), B.size());
	while (A.size() < maxLength)
		A.push_back(0);
	while (B.size() < maxLength)
		B.push_back(0);

	vector<int> result;
	int carry = 0;
	for (int i = 0; i < maxLength; i++) {
		int sum = A[i] + B[i] + carry;
		result.push_back(sum % 10);
		carry = sum / 10;
	}

	if (carry)
		result.push_back(carry);

	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];

	return 0;
}