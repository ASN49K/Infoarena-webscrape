#include<fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
    while(b!=0)
    {
        int r;
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}
int main()
{
    int n,a,b;
    in>>n;
    for(int i=1; i<=n; i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
