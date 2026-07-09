#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int a,b,n;
    cin>>n;
    while(n){
    cin>>a>>b;
    cout<<cmmdc(a,b)<<"\n";
    n-=2;
    }
    return 0;
}
