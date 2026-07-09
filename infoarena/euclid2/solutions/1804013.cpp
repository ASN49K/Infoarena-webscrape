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
    freopen("euclide2.in","r",stdin);
    freopen("euclide2.out", "w",stdout);
    int n,nr1,nr2;

    cin>>n;

    for(int i = 1; i <= n; i++)
    {
        cin>>nr1>>nr2;
        cout<<euclid(nr1,nr2)<<endl;
    }


    return 0;
}
