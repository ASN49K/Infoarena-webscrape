#include <iostream>
#include <fstream>
#include<stdio.h>
//#include <cstring>
//#include <cmath>
using namespace std;
 ifstream iFile("cmlsc.in");
//int minimum(int num1, int num2)
//{ if(num1<num2) return num1;
//  else return num2; }

int main(){
 int T=0, M=0, N=0, K=0;
 freopen("cmlsc.out", "w", stdout);  
 iFile>>M; iFile>>N; 
 int A[M], B[N], subs[256]; 

 for(int i=0; i<M;i++) iFile>>A[i]; //read A
 for(int i=0; i<N;i++) iFile>>B[i]; //read B
 
 for(int i=0; i<M; i++){
  for (int j=0; j<N; j++) {
   if (A[i]==B[j]) { subs[K]=A[i]; K++; break;}
  }
 }

 printf("%d\n", K);
 for(int i=0; i<K;i++) printf("%d ", subs[i]);
 return 0;
}