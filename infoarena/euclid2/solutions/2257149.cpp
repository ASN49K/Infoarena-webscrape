#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int,int);
int main()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){

        int x,y;
        cin>>x>>y;
        cout<<cmmdc(x,y)<<'\n';
    }

    return 0;
}

int cmmdc(int a,int b)
{
    int r;
    while( b ){

        r=a%b;
        a=b;
        b=r;

    }

    return a;
}
