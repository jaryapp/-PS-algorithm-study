#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;


class Answer {
public:
	int num[3];
	long long sum = LLONG_MAX;
};


int main(void) {

	int N;
	long long arr[5002];
	Answer ans;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int k = 0; k < N-2; k++) {
		int i = k+1;
		int j = N - 1;

		do
		{
			long long sum = arr[k] + arr[i] + arr[j];

			if (abs(sum) < abs(ans.sum)) {
				ans.num[0] = arr[k];
				ans.num[1] = arr[i];
				ans.num[2] = arr[j];
				ans.sum = sum;
			}
			if (sum > 0) j--;
			else i++;
		} while (i < j);
		
	}

	sort(ans.num, ans.num + 3);
	cout << ans.num[0] << " " << ans.num[1] << " " << ans.num[2];





	return 0;
}