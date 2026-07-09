#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t,n,i,j,v[10000],X;
    fin>>t;
    for(i=0;i<t;i++)
    {
        X=0;
        fin>>n;
        for(j=0;j<n;j++)
        {
            fin>>v[j];
            X=X^v[j];
        }
        if (X==0) fout<<"NU"<<endl;
        else fout<<"DA";
    }
    return 0;
}
