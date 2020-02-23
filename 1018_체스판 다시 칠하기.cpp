#include <iostream>
using namespace std;

int getCntPaint(char **board, int st_y, int st_x){
	
	int mi = 50*50+1;
	
	// 흰색 부터 시작
	char color = 'W';
	int cnt = 0;
	for(int y = st_y; y < st_y + 8; y++){
		for(int x = st_x; x < st_x + 8; x++){
			if(board[y][x] != color) cnt++;
			if(color == 'W') color = 'B';
			else color = 'W';
		}
		if(color == 'W') color = 'B';
		else color = 'W';
	}
	
	mi = cnt < mi ? cnt : mi;
	
	// 검은색 부터 시작
	color = 'B';
	cnt = 0;
	for(int y = st_y; y < st_y + 8; y++){
		for(int x = st_x; x < st_x + 8; x++){
			if(board[y][x] != color) cnt++;
			if(color == 'W') color = 'B';
			else color = 'W';
		}
		if(color == 'W') color = 'B';
		else color = 'W';
	}
	
	mi = cnt < mi ? cnt : mi;
	
	return mi;
}

int main() {
	char **board;
	int M,N;
	
	scanf("%d %d",&N,&M);
	
	board = new char*[N];
	
	for(int i = 0; i < N; i++){
		board[i] = new char[M];
		scanf("%s",board[i]);
	}
	
	int mi = 50*50+1;
	
	for(int i = 0; i <= N - 8; i++){
		for(int j = 0; j <= M - 8; j++){
			int cnt = getCntPaint(board,i,j);
			mi = cnt < mi ? cnt : mi;
			
		}
	}
	
	printf("%d",mi);
	
	
	
	return 0;
}