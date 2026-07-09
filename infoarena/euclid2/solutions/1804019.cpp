#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out", "w",stdout);
    int T,a,b;

    cin>>T;

    for(int i = 1; i <= T; i++)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<endl;
    }


    return 0;
}
