#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int n,t,s,x;

int main()
{
    fin>>t;

    for(int i=1;i<=t;i++)
    {
        fin>>n;
        s=0;

        for(int j=1;j<=n;j++)
        {
            fin>>x;

            if(j==1)
            {
                s=x;
            }

            else s^=x;
        }

        if(s==0)
        {
            fout<<"NU\n";
        }

        else fout<<"DA\n";
    }

    return 0;
}
