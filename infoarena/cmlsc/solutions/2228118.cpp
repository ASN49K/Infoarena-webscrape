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
    int u;
    f>>u;
    vn[i]=u;
}
for (int i=0; i<m; i++){
    int v;
    f>>v;
    vm[i]=v;
}
if (n>m){
nibab2(pred);
nibab(a);
mmaxa[0]=-1;
int GMAX=0;
for (int i=0; i<n; i++){ imax =0;
   for (int jj=0; jj<i; jj++){
    for (int j=0; j<m; j++){
        if ((mmaxa[jj]<j)&&(vm[j]==vn[i])&&(a[jj]+1>imax)){ imax=a[jj]+1; mmaxa[i]=j; pred[i]=jj;}
    }
   }
a[i]=imax;
if (a[i]> a[GMAX]){GMAX=i;}
if (imax==-1){mmaxa[i]=-1; pred[i]=-1;}
}


g << a[GMAX]<<endl;
int bl=0;
while(GMAX>0){
inversator[bl]=vn[GMAX];
GMAX=pred[GMAX];
bl++;
}
for (int j=bl-1; j>=0; j--){
    g << inversator[j]<<' ';
}
}
if (n<m){
nibab2(pred);
nibab(a);
mmaxa[0]=-1;
int GMAX=0;
for (int i=0; i<m; i++){ imax =0;
   for (int jj=0; jj<i; jj++){
    for (int j=0; j<n; j++){
        if ((mmaxa[jj]<j)&&(vn[j]==vm[i])&&(a[jj]+1>imax)){ imax=a[jj]+1; mmaxa[i]=j; pred[i]=jj;}
    }
   }
a[i]=imax;
if (a[i]> a[GMAX]){GMAX=i;}
if (imax==-1){mmaxa[i]=-1; pred[i]=-1;}
}


g << a[GMAX]<<endl;
int bl=0;
while(GMAX>0){
inversator[bl]=vm[GMAX];
GMAX=pred[GMAX];
bl++;
}
for (int j=bl-1; j>=0; j--){
    g << inversator[j]<<' ';
}
}
}



