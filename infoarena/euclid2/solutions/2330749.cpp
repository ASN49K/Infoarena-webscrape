#include<bits/stdc++.h> 
	
using namespace std;
	
int getdiv(int a,int b){
	
int r=0;
	
if(a==0)
return b;
else
if
(b==0)
return a;
else 
	
 while(b!=0) {
	
     r=a%b;
	
     a=b; 
	
     b=r; 
	
 } 
	
return a;
	
}
	
int main(){
	
ifstream fin("euclid2.in");
	
ofstream fout("euclid2.out");
	
int n,m;
	
int k;
	
int i;
	
fin>>k;
	
for(i=1;i<=k;i++){
	
fin>>n>>m;
	
fout<<getdiv(n,m);
	
n=0;
	
m=0;
	
}
	
}
