#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int t;
    long long a, b;

    for(int i=1; i<=t; i++)
    {
        f >> a >> b;

        int r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g << b << '\n';
    }
}
