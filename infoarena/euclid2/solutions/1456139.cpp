#include<iostream>
#include<fstream>
using namespace std;
int t,a,b;
int cmmdc(int a,int b){
if(b)return cmmdc(b,a%b);
if(b==0) return a;
}

int cmmdc1(int a, int b){
int aux;
while(b)
{aux=a;
a=b;
b=aux%b;

}
return aux;
}
int main(){
ifstream f("euclid2.in");
ofstream g("euclid2.out");


f>>t;
while(t){
    f>>a>>b;
    t--;
g<<cmmdc(a,b);

}
//cout<<cmmdc1(25,15)<<endl<<cmmdc1(225,625);
//cout<<endl<<cmmdc(36,9);

return 0;}
