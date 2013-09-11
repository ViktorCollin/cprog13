#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main ( int argc, char * argsv[] ) {
  int n = 0;
  char s[] = "world";
  printf("Hello");
  if(argc !=  1) {
    n = atoi(argsv[1]);
  }
  if(n != 0 && argc >= 3) {
    strcpy(s, argsv[2]);
  }
  else if(n == 0 && argc >= 2){
    strcpy(s, argsv[1]);
  }
  if( n == 0)
    n = 1;
  for(int i = 0; i < n; i++) {
    printf(" %s", s);
  }
  printf("!\n");
  return 0;
}
