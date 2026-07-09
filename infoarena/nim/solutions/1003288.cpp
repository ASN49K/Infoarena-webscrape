#include <fstream>

using namespace std;

int t, n, a;
ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    f>>t;

    while(t--)
    {
        f>>n;
        x=0;
        for(int i=0;i<n;i++)
        {
            f>>a;
            x=x^a;
        }
        if(x)
        {
            g<<"DA/n";
        }
        else
        {
            g<<"NU/n";
        }
    }

    return 0;
}
