#include<bits/stdc++.h>
using namespace std;
int main(){

ifstream fin("nim.in");
ofstream fout("nim.out");

int t,n,x,c,s,nr;

fin>>t;

for(int j=1;j<=t;j++){
    fin>>n;
    s=0;
    for(int i=1;i<=n;i++){
        fin>>nr;
       s=s^nr;
    }
    if(s!=0) fout<<"DA"<<"\n";
    else fout<<"NU"<<"\n";
}





return 0;
}
