#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t,n,x,xor_sum;

int main()
{
    fin>>t;

    for (int j=1; j<=t; j++)
    {
        xor_sum=0;
        fin>>n;
        for (int i=1; i<=n; i++)
        {
            fin>>x;
            xor_sum ^=x;
        }
        if (xor_sum==0) fout<<"NU";
        else fout<<"DA";
        fout<<"\n";
    }
}
