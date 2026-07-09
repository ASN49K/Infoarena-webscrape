#include <fstream>

using namespace std;
long long a,b,c,n,i;
int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        fout<<a<<'\n';
    }
    return 0;
}
