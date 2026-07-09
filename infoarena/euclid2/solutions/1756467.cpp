#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n,n1,n2,i,rest;
    in>>n;
    for(i=1;  i<=n; i++)
    {
        in>>n1>>n2;
        while(n2)
        {
            rest=n1%n2;
            n1=n2;
            n2=rest;
        }
        out<<n1<<'\n';

    }
    return 0;
}
