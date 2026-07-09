#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int i=1;
	while(i){
		if(fork()==0){
			do{
				printf("I am a forker %d!\n",getpid());
				sleep(1);
			}while(1);
		}
	}
	return 0;
}
