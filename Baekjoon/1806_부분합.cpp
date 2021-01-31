#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

int main(void) {
	ll N, M;
	int A[100002];
	ll sum = 0;
	int cnt = 0;

	scanf("%lld %lld", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int s, e;
	s = e = 0;
	int k = INT_MAX;
	while (true) {
		if (sum >= M) {
			k = k > e - s ? e - s : k;
			sum -= A[s];
			s++;
		}
		else {
			if (e >= N)break;
			sum += A[e];
			e++;
		}
	}

	k = k == INT_MAX ? 0 : k;
	printf("%d", k);
}