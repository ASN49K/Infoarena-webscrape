#include<fstream>
using namespace std;
int t,x,sum,n;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    fin>>t;
    for(;t>0;t--)
    {
        fin>>n;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            fin>>x;
            sum^=x;
        }
        if(sum)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}
