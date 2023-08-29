#include <iostream>
#include <vector>
#include <limits.h>

#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;
const int MAX_V = 501;
vector<pii> adj[MAX_V];

vector<long long> Bellman_ford(int st, int N) {
	vector<long long> dist(N + 1, INF);
    //vector<int> dist(N + 1, INF); // dist를 이렇게 선언하면 출력초과
	dist[0] = 1;	// 시간을 무한히 되돌릴 수 있는 경우 이 값이 0이 된다
	dist[st] = 0;	// 시작점 설정

	for (int i = 0; i < N-1; i++) {
		for (int from = 1; from<=N; from++)
			for (pii& edge : adj[from]) {
				int to = edge.second;
				int cost = edge.first;

				if (dist[from] != INF)	// 한번이라도 계산된 정점이라면
					dist[to] = min(dist[to], dist[from] + cost);
		}
	}

	// 만약 N-1번의 탐색 이후 추가로 한 번의 탐색을 더 진행하였는데,
	// 거리가 바뀌는 경우가 있다면 '시작지점에서 도달할 수 있는 정점들' 중에 음의 사이클이 존재하는 경우이다.
	// 따라서 시간을 무한히 오래 전으로 되돌릴 수 있다.
	for (int from = 1; from <= N; from++)
		for (pii edge : adj[from]) {
			int to = edge.second;
			int cost = edge.first;

			if (dist[from] != INF && dist[to] > dist[from] + cost) {
				dist[0] = 0;	// 시간을 무한히 되돌릴 수 있는 경우
				break;
			}
		}

	return dist;
}

void PRINT(vector<long long> vec) {
	if (vec[0] == 1)
		for (unsigned int i = 2; i < vec.size(); i++)
			if (vec[i] == INF)
				cout << -1 << endl;
			else
				cout << vec[i] << endl;
	else
		cout << -1;
}

int main() {cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back({ C, B });
	}

	vector<long long> ans = Bellman_ford(1, N);

	PRINT(ans);

	return 0;
}