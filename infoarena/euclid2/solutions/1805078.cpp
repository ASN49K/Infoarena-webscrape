#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,a,b,i,r;
    f>>n;
    for(i=1;i<=n;i++){
        f>>a>>b;
        r=a%b;
        while(r){
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<endl;
    }
    return 0;
}
