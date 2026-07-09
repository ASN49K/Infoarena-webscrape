#include<fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
    while(a!=b)
    {
        if(a>b) a=a-b;
        else b=b-a;
    }

    return b;
}
int main()
{
    unsigned int n,a,b;
    in>>n;
    for(int i=1; i<=n; i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
