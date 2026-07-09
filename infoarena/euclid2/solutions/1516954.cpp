#include <fstream>
using namespace std;
int n,i,a,b,x,y,r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()

{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        x=a;
        y=b;
        while(y>0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<'\n';


    }
    return 0;
}
