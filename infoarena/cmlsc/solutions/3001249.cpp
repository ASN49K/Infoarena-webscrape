#include<bits/stdc++.h>

using namespace std;
#define MAXI 1025

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,A[MAXI],B[MAXI];

void read(){
fin>>n>>m;
for(int i=1;i<=n;i++) fin>>A[i];
for(int j=1;j<=m;j++) fin>>B[j];
}
void cmsc(int V1[], int V2[], int a, int b){
  vector<int>L;
  int k=1;
  for(int i=1;i<=a;i++)
    for(int j=k;j<=b;j++)
      if(V1[i]==V2[j]) {L.push_back(V1[i]),k=j+1;break;}
  fout<<L.size()<<'\n';
  for(auto x:L)
  fout<<x<<" ";
}


int main(){
    read();
    if(n<m) cmsc(A,B,n,m);
    else cmsc(B,A,m,n);
    return 0;
}
/*
5 3
1 7 3 9 8
7 5 8
*/