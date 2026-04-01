#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		stack<char> ch;
		string str;
		getline(cin, str);

		bool isOk = true;

		if (str == ".")
			break;

		for (char c : str) {
			if (c == '(' || c == '[') {
				ch.push(c);
			}
			else if (c == ')') {
				if (ch.empty() || ch.top() != '(') {
					isOk = false;
					break;
				}
				else {
					ch.pop();
				}
			}
			else if (c == ']') {
				if (ch.empty() || ch.top() != '[') {
					isOk = false;
					break;
				}
				else {
					ch.pop();
				}
			}
		}
		if (isOk && ch.empty()) {
			cout << "yes\n";
		}
		else
			cout << "no\n";
	}
	return 0;
}