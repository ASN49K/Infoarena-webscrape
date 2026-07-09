#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int x,y,r,a,b,t,i;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        x=a;
        y=b;
        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }

        fout<<x<<"\n";
    }
    fout.close();
    fin.close();
    return 0;
}
