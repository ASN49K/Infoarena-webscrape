#include <iostream>
#include <fstream>
#include<stdio.h>
//#include <cstring>
//#include <cmath>
using namespace std;

int main(){
 int M=0, N=0, K=0, A[1024], B[1024], subs[1024], j=0, stop=0, i=0;
 ifstream iFile("cmlsc.in");
 freopen("cmlsc.out", "w", stdout);  
 iFile>>M; iFile>>N; 

 for(int i=0; i<M;i++) iFile>>A[i]; //read A
 for(int i=0; i<N;i++) iFile>>B[i]; //read B
 
 while(i<M){
  stop=0;
  while(stop==0 && j<N){
   if(A[i]==B[j]) {subs[K]=A[i]; K++; stop=1;}
   j++;}
  i++;
 }

 printf("%d\n", K);
 for(int i=0; i<K;i++) printf("%d ", subs[i]); cout<<endl;
 return 0;
}