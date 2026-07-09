#include <fstream>
using namespace std;
int n,i,x,y,r;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int main()
{
    in>>n;
    for(i=1;i<=n;i++){
        in>>x>>y;
        while(y){
            r=x%y;
            x=y;
            y=r;
        }
        out<<x;
    }
    return 0;
}
