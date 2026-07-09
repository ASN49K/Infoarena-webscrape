#include <iostream>
#include <fstream>
#include<stdio.h>
//#include <cstring>
//#include <cmath>
using namespace std;

int main(){
 int M=0, N=0, K=0, K1=0, A[1024], B[1024], C[1024], D[1024], i=0, j=0, stop=0, position;
 ifstream iFile("cmlsc.in");
 freopen("cmlsc.out", "w", stdout);  
 iFile>>M; iFile>>N; 

 for(int i=0; i<M;i++) iFile>>A[i]; //read A 
 for(int i=0; i<N;i++) iFile>>B[i]; //read B

position=0;

 while (i<M){
  stop=0; j=position;
  while(stop==0 && j<N){
   if(A[i]==B[j]) { C[K]=B[j]; K++; position=j; stop=1; }
   j++;
  }
  i++;
 }

i=0; j=0; position=0;

 while(i<N) {
  stop=0; j=position;
  while(stop==0 && j<M) {
   if(B[i]==A[j]) { D[K1]=A[j]; K1++; position=j; stop=1; }
   j++;
  }
  i++;
 }

 if(K1>K) {printf("%d\n", K1); for(int i=0; i<K1;i++) printf("%d ", D[i]);}
 else {printf("%d\n", K); for (int i=0; i<K; i++) printf("%d ", C[i]);}



 iFile.close();
 return 0;
}