#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream o("nim.out");
int t,n,i,s;
int main(void)
{
    f>>t;
    while (t--)
    {
        f>>n;
        n--; f>>s;
        while (n--)
        {
            f>>i;
            s^=i;
        }
        if (s==0) o<<"NU"<<"\n";
        else o<<"DA"<<"\n";
    }
}
