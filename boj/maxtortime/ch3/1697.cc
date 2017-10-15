#include <iostream>
#include <queue>

using namespace std;

int main() {
    // BFS
    int N, K;
    const int MAX = 200000; // 예제에도 나오듯이 들르는 정점이 N보다 커질 수 있음
    bool check[MAX];
    int dist[MAX];
    queue<int> q;

    cin >> N >> K;
    check[N] = true; // 들렀던 곳은 안들리기 위해
    dist[N] = 0; // depth를 계산하기 위함
    q.push(N); // 첫 정점 넣기

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        // X-1 , X+1, 2*X 큐에 넣을 값들 저장
        int t[3] = { now-1, now+1, now*2 };

        for (int i = 0 ; i < 3 ; i++) {
            if (t[i] >= 0 && t[i] < MAX && check[t[i]] == false) { // 정점이 0 이상 MAX 이하이면서 들르지 않았던 곳이여야함
                check[t[i]] = true;
                q.push(t[i]);
                dist[t[i]] = dist[now] + 1; // 다음 depth이므로 +1
            }
        }
    }
    
    cout << dist[K] << '\n';
    
    return 0;
}



