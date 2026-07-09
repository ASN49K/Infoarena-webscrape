#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long n, x, y;
int main()
{
    fin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        fin>>x>>y;
        while(x!=y)
        {
            if(x>y)
                x=x-y;
            else
                y=y-x;
        }
        fout<<x<<"\n";
    }
    return 0;
}
