#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int n, s;
int main()
{
    int i, x, r=0, j;
    fin>>s;
    for(j=1; j<=s; j++)
    {
     fin>>n;
     for(i=1; i<=n; i++)
        {
            fin>>x;
            r=r^x;
        }
    if(r!=0)
        fout<<"DA"<<'\n';
       else
        fout<<"NU"<<'\n';
    }
    return 0;
}
