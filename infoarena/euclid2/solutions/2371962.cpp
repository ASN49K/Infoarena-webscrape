#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int n, r, a, b;
    in>>n;
    for(int i=1; i<=n; i++)
    {
        r=0;
        in>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }
    return 0;
}
