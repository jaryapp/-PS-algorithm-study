#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main(void) {
	ll N, M;
	int A[10002];
	ll sum = 0;
	int cnt = 0;

	scanf("%lld %lld", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int s, e;
	s = e = 0;
	while (true) {
		if (sum >= M) {
			if (sum == M) {
				cnt++;
			}
			sum -= A[s];
			s++;
		}
		else {
			if (e >= N)break;
			sum += A[e];
			e++;
		}
	}

	printf("%d", cnt);
}