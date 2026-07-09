#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{int n,i,r,x,y;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        r=x%y;
        while(r!=0)
        {
            x=y;
            y=r;
            r=x%y;

        }
        fout<<y<<"\n";
    }

    return 0;
}
