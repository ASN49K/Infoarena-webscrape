#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
    int a,b;
    cin>>a>>b;
    while(a!=b)
        a>b?a-=b:b-=a;
    cout<<a;
}
