#include<fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
    int c;
    while (b)
    {
          c=a%b;
          a=b;
          b=c;
    }
    return a;
}

int main()
{
    int n,a,b;
    in>>n;
    for (int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<"\n";
    }
    return 0;
}
