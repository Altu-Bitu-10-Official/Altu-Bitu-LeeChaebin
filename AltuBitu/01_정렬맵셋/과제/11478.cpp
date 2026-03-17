#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    set<string> subString; 
    for (int i = 0; i < s.length(); i++) {
        string t = ""; 

        for (int j = i; j < s.length(); j++) {
            t += s[j];
            subString.insert(t); //set이 알아서 중복 알아서 제거
        }
    }
    cout << subString.size();
    return 0;
}