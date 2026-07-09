#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int div(int a,int b)
{
    if(!b) return a;
    return div(b,a%b);
}

int main()
{
    int a,b,n;
    f>>n;

    for(int i = 0 ; i < n ; i++)
        {
            f>>a>>b;
            g<<div(a,b)<<'\n';
        }
    return 0;
}
