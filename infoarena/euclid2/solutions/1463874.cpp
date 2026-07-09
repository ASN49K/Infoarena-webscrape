#include<fstream>
#include<algorithm>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a,int b)
{
    int d;
    if(b > a)
        swap(a,b);
    while(b!=0)
    {
        d = a%b;
        a=b;
        b=d;
    }
    return a;
}

int main ()
{
    int n, a, b;
    in >> n;
    for(int i=1; i<=n; i++)
    {
        in>>a >> b;
        out<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
