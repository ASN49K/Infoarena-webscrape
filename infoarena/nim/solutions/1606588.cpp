#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int a,n,t,suma,i;
int main()
{
    fin>>t;

    while(t>0)
    {
        fin>>n;
        suma=0;

        for(i=1;i<=n;i++)
        {
            fin>>a;

            suma= suma ^ a;
        }

        if(suma>0) fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';

        t--;
    }
    return 0;
}
