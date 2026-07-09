
#include<bits/stdc++.h>

 using namespace std;
 ifstream fin("cmmdc.in");
 ofstream fout("cmmdc.out");
 int a,b;
 
 int cmd(int a,int b){
 	if(!b)return a;
 	return cmd(b,a%b);
 }
     int main(){
     	fin>>a>>b;
     	int c=cmd(a,b);
     	if(c==1)
     fout <<0;
     else fout<<c;
       return 0; }