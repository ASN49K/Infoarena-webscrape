#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int t,n;
int main()
{
    fin>>t;
    while(t--)
    {
        fin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            fin>>a;
            ans^=a;
        }
        if(ans)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}
