#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(long long x, long long y)
{
    if(!y)  return x;
    else{
    return euclid(y, x%y);}
}
int main()
{
    int n;
    f>>n;
    long long x, y;
    for(int i=1; i<=n; i++){
    f>>x>>y;    g<<euclid(x,y)<<"\n";
    }
    return 0;
}
