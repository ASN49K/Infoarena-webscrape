#include <iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int sir1[1024];
int sir2[1024];
int subsir[1024];
int subsir2[1024];
int subsir_max=0;
int m,n;
void read(int n,int sir[]){
for(int i=0;i<n;i++){
    in>>sir[i];
}
}
bool valabil(int limit,int number,int &p){
for(int i=limit;i<n;i++){
    if(sir2[i]==number){
        p=i+1;
        return true;
    }
}
return false;
}
string maxx;
void subsir_get(int index,int limit,int lungime,string a){
if(lungime>subsir_max){
subsir_max=lungime;
maxx=a;
}
int p=0;
for(int i=index;i<m;i++){
if(valabil(limit,sir1[i],p)){
string b=a+" "+std::to_string(sir1[i]);
subsir_get(i+1,p,lungime+1,b);
}
}
}
void readall(){
in>>m>>n;
read(m,sir1);
read(n,sir2);
}

int main()
{
readall();
subsir_get(0,0,0,"");
out<<subsir_max<<endl<<maxx;
}
