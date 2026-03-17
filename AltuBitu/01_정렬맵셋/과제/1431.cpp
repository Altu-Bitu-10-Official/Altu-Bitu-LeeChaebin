#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//길이가 짧은 게 먼저
//길이 같다면 모든 자리수의 합이 작은 게 먼저
//사전순
int getSum(string s) {
	int total = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			total += (s[i] - '0');
	return total;
}

bool comp(const string& a, const string& b) {
	if (a.length() != b.length())
		return a.length() < b.length();

	else if (getSum(a) != getSum(b))
		return getSum(a) < getSum(b);

	else
		return a < b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];

	sort(s.begin(), s.end(), comp);

	for (int i = 0; i < n; i++)
		cout << s[i] << "\n";

	return 0;
}