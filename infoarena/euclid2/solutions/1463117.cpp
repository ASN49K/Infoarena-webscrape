#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int N,a,b,r;
    ifstream g("euclid2.in");
    ofstream f("euclid2.out");
    g>>N;
    for(int i=1;i<=N;i++)
    {
        g>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        f<<a<<endl;
    }
}
