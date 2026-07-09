#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;



void read(vector<int> &v1, vector<int> &v2){
     int n,m;
     scanf("%d%d",&n,&m);
     for(int i =0; i < n; i++){
          int x;
          scanf("%d",&x);
          v1.push_back(x);
     }
     for(int i =0; i<m;i++){
          int x;
          scanf("%d",&x);
          v2.push_back(x);
     }
}

int mem[1025][1025];

int solve(const vector<int>& v1,const vector<int>& v2,int n,int m){
     if(n == -1 || m == -1){
          return 0;
     }
     if(mem[n][m] != -1)
          return mem[n][m];
     
     if(v1[n] == v2[m])
          return mem[n][m] = 1 + solve(v1,v2,n-1,m-1);
     return mem[n][m] = max(solve(v1,v2,n-1,m),solve(v1,v2,n,m-1));
}

int main(){
     freopen("cmlsc.in","r",stdin);
     freopen("cmlsc.out","w",stdout);
     vector<int>v1,v2;
     read(v1,v2);
     memset(mem,-1,sizeof mem);
     cout << solve(v1,v2,v1.size()-1,v2.size()-1) << endl;
     return 0;
}