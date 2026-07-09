#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    long long x,y,a,b,n,i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        x=a;
        y=b;
        while(a!=b)
            if(a>b)
            a-=b;
        else
            b-=a;
        fout<<a<<endl;
    }
    return 0;
}
