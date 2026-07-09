#include<bits/stdc++.h>

using namespace std;

#define MAXI 1025

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,A[MAXI],B[MAXI],L[MAXI][MAXI];

void read(){
fin>>m>>n;
for(int i=1;i<=m;i++) fin>>A[i];
for(int j=1;j<=n;j++) fin>>B[j];
}


void cmsc(int V1[], int V2[], int a, int b){
  for(int i=1;i<=a;i++)
   for(int j=1;j<=b;j++)
      if(V1[i]==V2[j]) L[i][j]=L[i-1][j-1]+1;
      else L[i][j]=max(L[i-1][j],L[i][j-1]);

  int nr=0;
  int i=a,j=b;
  stack<int>S;
  while(i&&j){
     if(V1[i]==V2[j]) S.push(V1[i]),i--,j--,++nr;
     else if(L[i-1][j]<L[i][j-1]) --j;
     else --i;
  }
  fout<<nr<<'\n';
  while(!S.empty()) fout<<S.top()<<" ",S.pop();
}


int main(){
    read();
    cmsc(A,B,m,n);
    return 0;
}
/*
13 12
4 15 2 4 1 11 6 13 2 9 11 14 9
12 14 1 11 9 5 14 4 3 4 7 6
*/