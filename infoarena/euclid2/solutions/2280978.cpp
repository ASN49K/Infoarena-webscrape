#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned int a,b,aux,i,t,j;
int main(){
    f>>t;
    for(i=1;i<=t;i++){
        f>>a>>b;
    if(a>b){
            aux=a;
    a=b;
    b=aux;}
    for(j=a;j>=1;j--)
    if(a%j==0&&b%j==0){
    g<<j<<endl;
    break;}}
    return 0;}
