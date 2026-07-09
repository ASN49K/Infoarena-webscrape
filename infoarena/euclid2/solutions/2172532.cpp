#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b){
    int c;
    if (a<b){
        c=a;
        a=b;
        b=c;
    }
    c=a%b;
    while (c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,i,a,b;
    f >> n;
    for (i=1; i<=n;i++){
        f >> a >> b;
        g << cmmdc(a,b)<< "\n";
    }
    return 0;
}
