#include<iostream>
#include<fstream>
using namespace std;
int t,a,b;
int cmmdc1(int a, int b){
while(a!=b)if(a>b)a=a-b;
else b=b-a;
return a;}
int main(){ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
while(t){
    f>>a>>b;
    t--;
g<<cmmdc1(a,b)<<"\n";
}
g.close();
return 0;}

