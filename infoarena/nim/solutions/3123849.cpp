#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");
int t, n, x, sum;

int main()
{
    in>>t;
    while(t--)
    {
        in>>n;
        sum = 0;
        for(int i = 1; i<=n; i++)
        {
            in>>x;

            sum = sum ^ x;
        }

        if(sum != 0)
        {
            out<<"DA \n";
        }
        else
        {
            out<<"NU \n";
        }
    }
    return 0;
}
