#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int n,i,a,b,d,cmmdc;
    in>>n;
    for(i=1;i<=n;i++)
    {
        cmmdc=0;
        in>>a>>b;
        if(a>b)
        for(d=1;d<=b;d++)
        {
            if(a%d==0 && b%d==0)
            cmmdc=d;
        }
        else if(b>a)
        for(d=1;d<=a;d++)
        {
            if(a%d==0 && b%d==0)
            cmmdc=d;
        }
        out<<cmmdc<<endl;
    }
    return 0;
}
