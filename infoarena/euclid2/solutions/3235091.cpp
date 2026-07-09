#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int main()
{
    int n,m,r;
    f>>n>>m;
    for(int i = 0; i < n; ++i)
    while(m!=0)
    {
        r=n%m;
        n=m;
        m=r;
    }
    o<<n<<endl;

    return 0;
}
