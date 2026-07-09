#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b){
    if(a==b) return a;
    if(a>b) return cmmdc(a-b,b);
    if(b>a) return cmmdc(a,b-a);
    return 1;
}
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
int main()
{
    int t;
    int i=0;
    f>>t;
    int a,b;
    while(i!=t){
    f>>a>>b;
    g<<cmmdc(a,b);
    g<<endl;
    i++;}
    return 0;
}
