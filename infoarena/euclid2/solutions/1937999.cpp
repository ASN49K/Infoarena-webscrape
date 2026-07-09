#include <iostream>
#include <fstream>

using namespace std;
int cmmdc(int a, int b)
{
    int r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int t, a, b, i, v[100];

    f>>t;
    for(i=1;i<=t;i++){
        a=0;b=0;
        f>>a>>b;
        v[i]=cmmdc(a,b);
    }
    for(i=1;i<=t;i++)
        g<<v[i];

    return 0;
}
