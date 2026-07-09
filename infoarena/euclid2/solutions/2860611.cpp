#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int n,i,a,b,r;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        r=a%b;
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
