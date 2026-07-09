#include <iostream>
#include <fstream>
#define MAX 100001

using namespace std;
ifstream in("euclid.in");
ofstream out("euclid.out");
int n;

int euclid(int a,int b)
{
    if(!b) return a;
    else euclid(b, a%b);
}

int main()
{
    int x,y;
    in>>n;
    for (int i=1;i<=n;i++)
    {
        in>>x>>y;
        out<<euclid(x,y)<<endl;
    }
    return 0;
}
