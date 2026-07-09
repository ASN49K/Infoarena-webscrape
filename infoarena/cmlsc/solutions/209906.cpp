#include <iostream>
#include <fstream>
#include<stdio.h>
//#include <cstring>
//#include <cmath>
using namespace std;

int main(){
 int M=0, N=0, K=0, A[1024], B[1024], subs[1024], stop=0, j=0;
 ifstream iFile("cmlsc.in");
 freopen("cmlsc.out", "w", stdout);  
 iFile>>M; iFile>>N; 

 for(int i=0; i<M;i++) iFile>>A[i]; //read A
 for(int i=0; i<N;i++) iFile>>B[i]; //read B
 
 for(int i=0; i<M; i++){
  while (j<N){
   stop=0;
   if(A[i]!=B[j]) j++;
   else {subs[K]=B[j]; K++; j++; break;}
  }
 }
 

 printf("%d\n", K);
 for(int i=0; i<K;i++) printf("%d ", subs[i]);
 return 0;
}