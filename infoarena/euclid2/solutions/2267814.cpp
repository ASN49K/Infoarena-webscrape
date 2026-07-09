#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b;
int main()
{
    f>>T;
    while(T--){
        f>>a>>b;
        int r=a%b;
        while(r)a=b,b=r,r=a%b;
        g<<b<<'\n';
    }
    return 0;
}
