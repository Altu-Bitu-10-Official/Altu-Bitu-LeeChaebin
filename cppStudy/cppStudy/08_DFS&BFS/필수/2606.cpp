#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];
int cnt = 0; //감염된 컴

int main()
{
    int n, connected;
    cin >> n; //컴퓨터 수
    cin >> connected; //연결된 쌍 수

    for (int i = 0; i < connected; i++) {
        int u, v;
        cin >> u >> v;

        //양방향 연결
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];


            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;


    return 0;
}