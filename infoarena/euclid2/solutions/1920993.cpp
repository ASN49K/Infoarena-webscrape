#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a,b,n,i;
int euclidImp(int a, int b)
{
    if (!b) return a;
    return euclidImp(b, a % b);
}
int main()
{
    in>>n;
    for(i=1;i<=n;i++){
        in>>a>>b;
        out<<euclidImp(a,b)<<'\n';
    }
    return 0;
}
