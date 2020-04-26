#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;


int A[5000005];
int N,L;
priority_queue<pair<int, int>> pq;

int main(void) {


	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		pq.push({ -A[i],i });
		while (pq.top().second <= i - L) pq.pop();
		cout << -pq.top().first << " ";
	}
}