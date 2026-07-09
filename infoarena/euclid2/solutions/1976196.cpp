#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int main(){
    int a,b,aa,bb,n;
    f>>n;
    for(int i=1;i<=n;i++){
    f>>a>>b;
    aa=a;
    bb=b;
    while(a!=b)
        if(a>b) a=a-b;
        else b=b-a;
        g<<b<<endl;
    }
    return 0;
}
