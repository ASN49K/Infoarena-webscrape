#include <fstream>

using namespace std;
ifstream fcin("test.in");
ofstream fout("test.out");
int n,a,b;
int main()
{
    fcin>>n;
    while(n--)
    {
        fcin>>a>>b;
        while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';
    }
    return 0;
}
