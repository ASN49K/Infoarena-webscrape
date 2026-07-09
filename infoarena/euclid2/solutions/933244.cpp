#include <fstream>

using namespace std;

int cmmdc(int a,int b)
{
    int r=a%b;
    if(r==0)
        return b;
    else
        return cmmdc(b,r);
}

int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");
    int n,a,b;
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }
    in.close();
    out.close();
    return 0;
}
