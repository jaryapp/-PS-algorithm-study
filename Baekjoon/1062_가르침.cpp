#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<string> words;
int N,K;
bool visited[200] = { false, };
int mx = 0;

bool check(string& word) {
	for (auto c : word) {
		if (!visited[c]) return false;
	}
	return true;
}

void dfs(int i, int depth) {
	if(depth > K){
		int n = 0;
		for (auto word : words) {
			if (check(word)) n++;
		}
		if (mx < n) mx = n;
		return;
	}

	for (int k = i; k <= 'z'; k++) {
		if (visited[k]) continue;
		visited[k] = true;
		dfs(k + 1, depth + 1);
		visited[k] = false;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	visited['a'] = true;
	visited['n'] = true;
	visited['t'] = true;
	visited['i'] = true;
	visited['c'] = true;

	cin >> N >> K;

	K -= 5;

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		word = word.substr(4, word.length() - 8);
		words.push_back(word);
	}

	if(K>=0) dfs('a', 1);

	cout << mx;

	return 0;
}