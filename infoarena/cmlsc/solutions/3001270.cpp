#include<bits/stdc++.h>

using namespace std;
#define MAXI 1025

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,A[MAXI],B[MAXI],L[MAXI][MAXI];

void read(){
fin>>n>>m;
for(int i=1;i<=n;i++) fin>>A[i];
for(int j=1;j<=m;j++) fin>>B[j];
}
void cmsc(int V1[], int V2[], int a, int b){
  for(int i=1;i<=a;i++)
   for(int j=1;j<=b;j++)
      if(V1[i]==V2[j]) L[i][j]=L[i][j-1]+1;
      else L[i][j]=max(L[i-1][j],L[i][j-1]);
  fout<<L[a][b]<<'\n';
  int i=a,j=b;
  stack<int>S;
  while(i&&j){
     if(V1[i]==V2[j]) S.push(V1[i]),i--,j--;
     else if(L[i-1][j]<L[i][j-1]) j--;
     else i--;
  }
  while(!S.empty()) fout<<S.top()<<" ",S.pop();
}


int main(){
    read();
    cmsc(A,B,n,m);
    return 0;
}
/*
5 3
1 7 3 9 8
7 5 8
*/