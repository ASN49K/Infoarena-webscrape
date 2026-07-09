#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclid(int x,int y)
{
    int r;
    while(y!=0)
    {
        r=y;
        y=x%y;
        x=r;
    }
    return x;
}

int main()
{
    int a,b,T;
    cin>>T;
    for(int i=1;i<=T;i++){
    cin>>a>>b;
    cout<<"\n"<<euclid(a,b)<<"\n";
    }
    return 0;
}
