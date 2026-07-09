#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t;
    f>>t;
    while(t--)
    {
        int n;
        f>>n;
        int ans=0;
        while(n--)
        {
            int x;
            f>>x;
            ans^=x;
        }
        if(!ans)
            g<<"NU";
        else
            g<<"DA";
        g<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
