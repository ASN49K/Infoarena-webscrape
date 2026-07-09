#include <iostream>
#include <fstream>
#define FIN ("euclid2.in");
#define FOUT("euclid2.out");
using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    while(a!=0)
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    cout<<b;

    return 0;
}
