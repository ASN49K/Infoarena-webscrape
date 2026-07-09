#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a,b,n,i,cmmdc,r;
int main()
{
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cmmdc=a;
        fout<<cmmdc<<endl;
    }
    return 0;
}
