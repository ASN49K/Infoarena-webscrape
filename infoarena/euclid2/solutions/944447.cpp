#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){
    if(b==0) return a;
    return cmmdc(b,a%b);
}

int main()
{
    int n,aux1,aux2;
    f>>n;
    for(int i=1;i<=n;i++){
        f>>aux1>>aux2;
        g<<cmmdc(aux1,aux2)<<endl;
    }
}
