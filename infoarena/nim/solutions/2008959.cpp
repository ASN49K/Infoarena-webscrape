#include<fstream>
using namespace std;
fstream f1("nim.in", ios::in);
fstream f2("nim.out", ios::out);
int t;
long int n, x;
long long s=0;
int main()
{
    int i;
    long int j;
    f1>>t;
    for(i=1; i<=t; i++)
    {
        f1>>n;
        s=0;
        for(j=1; j<=n; j++)
        {
            f1>>x;
            s^=x;
        }
        if(s!=0) f2<<"DA"<<"\n";
        else f2<<"NU"<<"\n";
    }
    return 0;
}
