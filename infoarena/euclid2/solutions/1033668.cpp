#include <fstream>

using namespace std;

int main()
{
    unsigned n,i,x,y;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        {
        {
        while(x!=y)
        if(x>y)
        x=x-y;
        else
        y=y-x;
        }
        fout<<x<<'\n';
        }
    }

    fin.close();
    fout.close();
    return 0;

}
