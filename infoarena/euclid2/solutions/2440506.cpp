#include <fstream>
using namespace std;
int n,i,x,y;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int euclid(int a,int b){
    if(!b)return a;
    return euclid(b,a%b);
}
int main()
{
    in>>n;
    for(i=1;i<=n;i++){
        in>>x>>y;
        out<<euclid(x,y)<<'\n';
    }
    return 0;
}
