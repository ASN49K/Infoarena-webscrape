#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in ("nim.in");
    ofstream out ("nim.out");

    int n, t, ans, aux;
    in>>t;
    while(t--)
    {
        ans = 0;
        in>>n;
        for(int i = 0; i < n; ++i)
            {
                in>>aux;
                ans = ans ^ aux;
            }
        if(!ans)
            out<<"NU\n";
        else
            out<<"DA\n";
    }
    return 0;
}
