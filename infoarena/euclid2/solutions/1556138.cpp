#include <iostream>
#include <stdio.h>
using namespace std;

int T;
int a;
int b;

int euclid(const int & a , const int &b){
	if(!b) 
		return a;
	return euclid (b , a %b);
}


int main(){
	
	FILE * inFile = fopen("euclid2.in" ,  "r");
	FILE * outFile = fopen("euclid2.out", "w+");
	
	fscanf(inFile , "%d\n" , &T);
	for(int i = 0 ; i < T ; i++){
		fscanf(inFile , "%d %d\n", & a , & b);
		fprintf(outFile ,"%d\n" , euclid (a ,b));
		fflush(outFile);
	}
	
	fclose(inFile);
	fclose(outFile);
	
	return 0;
	
}