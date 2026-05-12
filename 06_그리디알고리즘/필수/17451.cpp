//속도를 줄이기만 하면서 정수배니까 
// 뒤에서 앞으로-> 배수 늘려가면서 그 중 최소
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 끝 -> 앞
    long long speed = v[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (speed % v[i] != 0) {
            speed = (speed/v[i] + 1) * v[i];
        }
    }
    cout << speed;

    return 0;
}