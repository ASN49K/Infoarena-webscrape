#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int t;
long long int a, b;
int main()
{
    fin>>t;
    for(int i=1; i<=t; i++)
    {
        fin>>a>>b;
        long long r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<"\n";
    }

    return 0;
}
