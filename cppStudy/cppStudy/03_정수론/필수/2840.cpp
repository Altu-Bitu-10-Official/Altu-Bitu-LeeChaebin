#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
n: 바퀴 칸 수
k: 바퀴 돌리는 횟수
s: 회전한 칸 수
출력: 시계방향
?: 결정x
!: 없음
*/

string solve(int n, int k, const vector<int>& s_list, const vector<char>& c_list) {
	vector<char> wheel(n, '?');
	int index = 0;
	
	for (int i = 0; i < k; i++) {
		int s = s_list[i];
		char c = c_list[i];
		
		//화살표 이동
		index = (index - (s % n) + n) % n;

		if (wheel[index] != '?' && wheel[index]!=c)
			return "!";
		wheel[index] = c;
	}

	for (int i = 0; i < n; i++) {
		if (wheel[i] == '?')
			continue;
		for (int j = i + 1; j < n; j++) {
			if (wheel[i] == wheel[j]) //같은 문자가 여러 칸에 있을 때
				return "!";
		}
	}

	string result = "";
	for (int i = 0; i < n; i++) {
		result += wheel[(index + i) % n];
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> s_list(k);
	vector<char> c_list(k);

	for (int i = 0; i < k; i++) {
		cin >> s_list[i] >> c_list[i];
	}

	cout << solve(n, k, s_list, c_list);
}
