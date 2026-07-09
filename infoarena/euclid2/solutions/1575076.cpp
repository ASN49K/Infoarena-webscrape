#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int eu(int &a,int &b)
{
    int r;
    while (b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void read(ifstream &f,ofstream &g,int &n,int &a,int &b)
{
    int i;
    f>>n;
    for (i=1;i<=n;i++){
        f>>a>>b;
        g<<eu(a,b)<<endl;
    }
}

int main()
{
    int n,a,b;
    read(f,g,n,a,b);
    return 0;
}
