#include <iostream>
#include <fstream>

using namespace std;


int cmmdc(int a, int b){
    if(b == 0)
    return a;
    else return cmmdc(b, a % b);
}
int a, b, n;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b) << "\n";
    }
}
