#include <fstream>
using namespace std;
int x,y,r,i,T;
int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>x>>y;
        while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
    }
    return 0;
}

