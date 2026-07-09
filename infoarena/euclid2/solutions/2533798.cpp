#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long n,u,t,r,i;
int main()
{
    f>>n;
    for(i=1;i<=n;i++){
        f>>u>>t;
        while(t){
            r=u%t;
            u=t;
            t=r;
        }
        g<<u<<'\n';
    }

    return 0;
}
