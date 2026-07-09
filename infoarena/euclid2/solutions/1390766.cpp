#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n,i;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        int a,b,r;


        fin>>a>>b;
        while (b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;
    }
    return 0;
}
