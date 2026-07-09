#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,a,b,x,y;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }

}
