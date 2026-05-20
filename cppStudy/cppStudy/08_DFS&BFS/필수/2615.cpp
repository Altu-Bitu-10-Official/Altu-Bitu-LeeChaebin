
#include <iostream>
using namespace std;
//검1, 흰2, 없0

int graph[21][21]; //인덱스 1번부터 시작

//오른쪽위, 오, 오른쪽아래, 아래
int dy[4] = { -1,0,1,1 }; //행
int dx[4] = { 1,1,1,0 }; //열

int main() {
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            cin >> graph[i][j];
        }
    }

    //가장 왼쪽 돌
    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= 19; i++) {
            if (graph[i][j] == 0) continue;

            int color = graph[i][j];

            for (int d = 0; d < 4; d++) {
                int cnt = 1; //현재 위치 돌

                int nr = i + dy[d]; //행
                int nc = j + dx[d]; //열

                while (nr > 0 && nr < 20 && nc>0 && nc < 20 && graph[nr][nc] == color) {
                    cnt++;
                    nr += dy[d];
                    nc += dx[d];
                }


                if (cnt == 5) {
                    int prev_r = i - dy[d];
                    int prev_c = j - dx[d];

                    if (prev_r > 0 && prev_r < 20 && prev_c>0 && prev_c < 20 && graph[prev_r][prev_c] == color) {
                        continue;
                    }

                    cout << color << '\n';
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }

    //승자x
    cout << 0 << '\n';
    return 0;
}