#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main(void) {

	int N, start, end;
	int arr[100001];


	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];

	start = 0;
	end = N - 1;

	int v = INT_MAX;
	int v_s;
	int v_e;

	while (start < end) {
		int t = arr[end] + arr[start];
		if (v == INT_MAX || abs(t) < abs(v)) {
			v = t;
			v_s = start;
			v_e = end;
		}
		if (t < 0) {
			start++;
		}
		else end--;
	}

	cout << arr[v_s] <<" " << arr[v_e];



	return 0;
}