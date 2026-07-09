#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t, n, x, ans;

int main()
{
    for(f>>t; t; t-=1)
    {
        ans=0;
        f>>n;
        for(; n; n-=1)
        {
            f>>x;
            ans = ans ^ x;
        }
        if(ans) g<<"DA\n";
        else g<<"NU\n";
    }
}
