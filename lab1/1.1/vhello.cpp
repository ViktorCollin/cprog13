#include <cstdio>
#include <cstdlib>
#include <cstring>
int main(const int argc, const char * argv[]){
	int n(1);
	char s[100] = "world";
	printf("Hello");
	if(argc == 2){
		if(atoi(argv[1])){
			 n = atoi(argv[1]);
		}else{
			strcpy(s,argv[1]);
		}
	}else if(argc >= 3){
		n = atoi(argv[1]);
		strcpy(s, argv[2]);
	}
	for(int i = 0; i<n; ++i){
		printf(" %s", s);
	}
	printf("!\n");
	return 0;
}