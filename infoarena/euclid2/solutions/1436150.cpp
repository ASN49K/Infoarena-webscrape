using namespace std;
#include <fstream>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n;
    int a, b;
    int i, ok;
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>a>>b;
        ok=1;
        while(ok==1)
        {
            if(a==0||b==0) ok=0;
            if(ok)
            {
            if(a>b) a=a%b;
                else b=b%a;
            }
        }
        if(a==0) g<<b<<'\n';
            else g<<a<<'\n';
    }
    return 0;
}
