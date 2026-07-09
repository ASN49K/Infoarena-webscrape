#include <iostream>
#include <fstream>

using namespace std;
ifstream r("maxrec.in");
ofstream w("maxrec.out");
long long maxim=-10000000000, nr;
int maximul(long long maxim, int n)
{
    r>>nr;
    maxim=max(maxim,nr);
    if(n==1)
    {
        return maxim;
    }
    maximul(maxim, n-1);
}
int main()
{
    int n;
    r>>n;
    w<<maximul(maxim, n);
    return 0;
}
