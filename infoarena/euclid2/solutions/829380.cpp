#include<iostream.h>
#include<fstream.h>
main(){
ifstream f1("D:\\euclid.in");
ofstream f2("D:\\euclid.out");     int T,i,a,b,rest;
f1>>T;
for(i=1;i<=T;i++){
f1>>a>>b;
while(a!=b){
if(a>b)
a=a-b; else
b=b-a;
}
f2<<a<<endl;}
return 0;}