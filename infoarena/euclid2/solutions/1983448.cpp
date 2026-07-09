#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long i,n,a,b,c;
int cmmd(long a, long b)
{
    while (a!=b)
    {

        if (a>b) a=a-b;
         else if(a<b) b=b-a;
    }
    return a;
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a;
        fin>>b;
        fout<<cmmd(a,b)<<endl;

    }
    return 0;
}
