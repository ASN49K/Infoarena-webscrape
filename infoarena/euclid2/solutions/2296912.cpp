
#include<bits/stdc++.h>

 using namespace std;
 ifstream fin("euclid2.in");
 ofstream fout("euclid2.out");
 int a,b,n;
 
 int cmd(int a,int b){
 	if(!b)return a;
 	return cmd(b,a%b);
 }
     int main(){
     	fin>>n;
     	for(int i=1;i<=n;i++){
     	fin>>a>>b;
     	fout<<cmd(a,b)<<"\n";
     }
       return 0; }
