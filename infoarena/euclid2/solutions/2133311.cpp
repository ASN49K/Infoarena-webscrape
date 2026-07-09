#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long int r,a,b,n;
int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }

}
