#include <bits/stdc++.h>
using namespace std;ifstream fin("nim.in");ofstream fout("nim.out");int main(){int nrop,n,x,i,j,s;fin>>nrop;for(i=1;i<=nrop;i++){fin>>n;s=0;for(j=1;j<=n;j++){fin>>x;s=s^x;}if(s)fout<<"DA\n";else fout<<"NU\n";}fin.close();fout.close();return 0;}
