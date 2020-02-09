#include <iostream>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int T;
	
	cin >> T;
	
	int A,B;
	
	for(int t = 0; t < T; t++){
		cin >> A >> B;
		cout << A+B << "\n";
	}
	
	
	return 0;
}