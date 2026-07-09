#include <fstream>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int main()
{   int n,a,b,r;
    fin>>n;
    for (int i=1;i<=n;i++)
    {
        fin>>a>>b;
         while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<endl;
    }
    return 0;
}
