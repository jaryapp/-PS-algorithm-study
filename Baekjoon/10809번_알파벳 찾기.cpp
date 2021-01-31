#include <iostream>
#include <cstring>
using namespace std;

int alphabet[30];

int main() {
	
	char str[102];
	
	scanf("%s",str);
	
	int len = strlen(str);
	
	for(int i = 0; i < len; i++){
		if(!alphabet[str[i]-'a']) alphabet[str[i]-'a'] = i+1;
	}
	
	for(int i = 0; i <= 'z' - 'a'; i++){
		printf("%d ",alphabet[i]-1);
	}
	
	return 0;
}