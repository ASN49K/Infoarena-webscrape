#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long int a,b,T,r,i;

int main()
{
    fin>>T;
    for(i=1; i<=T; i++)
    {
        fin>>a>>b;
        if(b>a)
        {
            swap(a,b);
        }

        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }

        fout<<a<<"\n";
    }

    return 0;
}
