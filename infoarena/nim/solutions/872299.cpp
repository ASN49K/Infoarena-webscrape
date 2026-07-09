#include<fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int n,i,j,x,s,t;

int main()
{
    in>>t;
    for (i=1;i<=t;i++)
    {
        in>>n;
        s=0;
        for (j=1;j<=n;j++)
        {
            in>>x;
            s^=x;
        }
        if (s) out<<"DA\n";
            else out<<"NU\n";
    }
}
