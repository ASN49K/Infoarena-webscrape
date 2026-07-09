#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n;
int euclid(int a,int b)
{       int r;
        while(b)
        {    r=a%b;
              a=b;
              b=r;
        }
        return a;
}
void Read()
{       int i,a,b;
        in>>n;
        for(i=1;i<=n;i++)
        {
            in>>a>>b;
            out<<euclid(a,b)<<"\n";
        }
}
int main()
{
    Read();
    in.close();
    out.close();
    return 0;
}
