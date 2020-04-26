#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

ll arr[1000005];
ll ntree[4000005];
ll xtree[4000005];

ll getMax(int index, int start, int end, int left, int right) {
	if (start > right || end < left) return INT_MIN;
	else if (start >= left && end <= right) return xtree[index];
	else {
		int mid = (start + end) / 2;
		return max(getMax(index * 2 + 1, start, mid, left, right), getMax(index * 2 + 2, mid + 1, end, left, right));
	}

}

ll xinit(int index, int start, int end) {
	if (start == end) {
		xtree[index] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		xtree[index] = max(xinit(index * 2 + 1, start, mid), xinit(index * 2 + 2, mid + 1, end));
	}

	return xtree[index];

}


ll getMin(int index, int start, int end, int left, int right) {
	if (start > right || end < left) return INT_MAX;
	else if (start >= left && end <= right) return ntree[index];
	else {
		int mid = (start + end) / 2;
		return min(getMin(index * 2 + 1, start, mid, left, right), getMin(index * 2 + 2, mid + 1, end, left, right));
	}

}

ll ninit(int index, int start, int end) {
	if (start == end) {
		ntree[index] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		ntree[index] = min(ninit(index * 2 + 1, start, mid), ninit(index * 2 + 2, mid + 1, end));
	}

	return ntree[index];

}

int main(void) {


	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	int a, b;

	ninit(0, 0, N - 1);
	xinit(0, 0, N - 1);

	while (M--) {
		scanf("%d %d", &a, &b);
		printf("%lld %lld\n", getMin(0, 0, N - 1, a - 1, b - 1), getMax(0, 0, N - 1, a - 1, b - 1));
	}



	return 0;
}