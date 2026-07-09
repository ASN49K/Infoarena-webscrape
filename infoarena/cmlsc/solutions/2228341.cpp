#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
int imax;
int vn[10000],vm[10000];
int a[10000];
int pred[10000];
int mmaxa[10000];
int inversator[10000];
int lll[10000][10000];
void nibab(int rudi[10000])
{
    for (int i=0; i<m+n; i++){
        rudi[i]=0;
    }
}
void nibab2(int rudi[10000])
{
    for (int i=0; i<m+n; i++){
        rudi[i]=0;
    }
}

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
f>>n>>m;

for (int i=0; i<n; i++){
    f >>vn[i];
}
for (int i=0; i<m; i++){
    f >>vm[i];
}
int s=-1;

int rmax=0;
for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        if (vn[i]==vm[j]){
            lll[i][j]=lll[i-1][j-1]+1;
        if (lll[i-1][j-1]==rmax){s++; a[s]=i;}
        }
        else{
            lll[i][j]=max(lll[i-1][j], lll[i][j-1]);
        }
if (lll[i][j]>rmax){rmax=lll[i][j];}
    }
}


        g << s+1<< endl;

for (int i=0; i<s+1; i++){
    g << vn[a[i]]<<' ';
}












}



