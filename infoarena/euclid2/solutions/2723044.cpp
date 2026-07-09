#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid( int a,int b)
{
    while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
    return a;
}
int main()
{
    int n,i;
    int a,b;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<endl;
    }
    return 0;
}
