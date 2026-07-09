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

    int t, a, b, i;

    f>>t;
    for(i=1;i<=t;i++){
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }

    return 0;
}
