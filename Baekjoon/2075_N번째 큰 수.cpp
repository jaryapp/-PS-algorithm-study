#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main(void) {

	int N,d;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &d);
			pq.push(-d);
			if (pq.size() > N) pq.pop();
		}
	}

	printf("%d", -pq.top());



	return 0;
}