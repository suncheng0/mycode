#include<stdio.h>
#include<stdlib.h>
#include <setjmp.h>
#include <signal.h>
using namespace std;
sigjmp_buf buf;
void FLPhandler(int sig) {
	printf("error type is SIGFPE!\n");
	siglongjmp(buf, 1);
}
int main() {
	int a, t;
	signal(SIGFPE, FLPhandler);
	if (!sigsetjmp(buf, 1)) {
		printf("starting\n");
		a = 100;
		t = 0;
		a = a / t;
	}
	printf("i am alive");
	exit(0);
}