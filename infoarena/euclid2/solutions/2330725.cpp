
#include<bits/stdc++.h> 
using namespace std;
int getdiv(int a,int b){
int r=0;
if(a==0||b==0)
return 0;
else 
 while(b!=0) {
     r=a%b;
     a=b; 
     b=r; 
 } 
return a;
}
int main(){
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n,m;
int k;
int v[100];
int i;
cin>>k;
for(i=1;i<=k;i++){
cin>>n>>m;
v[i]=getdiv(n,m);
n=0;
m=0;
}
for(i=1;i<=k;i++)
cout<<v[i]<<" ";
}
