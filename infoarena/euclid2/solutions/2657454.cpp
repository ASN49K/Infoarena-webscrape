#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n,i,a,b,r;
void euclid(int &a, int b)
{ int r=0;
    while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        r=0;
        fin>>a>>b;
        euclid(a,b);
   fout<<a<<'\n';
    }
    return 0;
}
