#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int rezolvare(int a, int b)
{
    int c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n, i, a, b;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<rezolvare(a, b)<<endl;
    }
    return 0;
}
