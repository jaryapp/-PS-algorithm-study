#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;

ll arr[1000005];
ll tree[5000005];

void update(int changed_index, ll diff, int index, int start, int end) {
	if (changed_index < start || changed_index > end) return;

	tree[index] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(changed_index, diff, index * 2 + 1, start, mid);
		update(changed_index, diff, index * 2 + 2, mid+1, end);
	}
}

ll sum(int index, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	else if (start >= left && end <= right) return tree[index];
	else {
		int mid = (start + end) / 2;
		return sum(index * 2 + 1, start, mid, left, right) + sum(index * 2 + 2, mid + 1, end, left, right);
	}

}

ll init(int index, int start, int end) {
	if (start == end) {
		tree[index] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		tree[index] = init(index * 2 + 1, start, mid) + init(index * 2 + 2, mid + 1, end);
	}

	return tree[index];

}

int main(void) {

	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	init(0, 0, N-1);

	ll a, b, c;
	for (int i = 0; i < M + K; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			update(b - 1, c - arr[b - 1], 0, 0, N - 1);
			arr[b - 1] = c;
		}
		else printf("%lld\n", sum(0, 0, N - 1, b-1, c-1));
	}



	return 0;
}