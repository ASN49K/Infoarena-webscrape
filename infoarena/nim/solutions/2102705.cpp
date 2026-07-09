#include <fstream>

using namespace std;
int t,n,s,i,x;
int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    f>>t;
    while(t)
    {
        t--;
        f>>n;
        s=0;
        for(i=1; i<=n; i++)
        {
            f>>x;
            s=s xor x;
        }
        if(s) g<<"DA\n";
        else g<<"NU\n";
    }
    f.close(); g.close();
    return 0;
}
