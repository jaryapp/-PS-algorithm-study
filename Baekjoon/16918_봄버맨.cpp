#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int R,C,N;

class Bomb{
public:
    int x;
    int y;
    int install_sec;
};

queue<Bomb> Q;


char map[202][202];

void setDot(int y, int x){
    if(y < 0 || y >= R || x < 0 || x >= C) return;
    map[y][x] = '.';
}

void boom(int y, int x){
    setDot(y,x);
    setDot(y+1,x);
    setDot(y-1,x);
    setDot(y,x+1);
    setDot(y,x-1);
}

void showMap(){
     for(int y = 0; y < R; y++){
        printf("%s\n",map[y]);
    }
}

void simulation(int sec){

    if(sec == N){
        // showMap();
        return;
    }
    
    while(!Q.empty()){
        Bomb b = Q.front();
        if(sec < b.install_sec + 2) break;
        boom(b.y,b.x);
        Q.pop();      
    }

    for(int y = 0; y < R; y++){
        for(int x = 0; x < C; x++){
            if(map[y][x] == '.'){
                Q.push({y,x,sec});
                map[y][x] = 'O';
            }
        }
    }
    
    simulation(sec+1);


}


int main(void){
    
    scanf("%d %d %d",&R,&C,&N);
    for(int i = 0; i < R; i++){
        scanf("%s",map[i]);   
    }

    for(int y = 0; y < R; y++){
        for(int x = 0; x < C; x++){
            if(map[y][x] == 'O'){
                Q.push({y,x,0});
            }   
        }
    }
    simulation(0);

    return 0;
}