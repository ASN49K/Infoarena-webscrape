#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

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
{       int n,a,b;
        in>>n;
        for(int i=1;i<=n;i++)
        {
            in>>a>>b;
            out<<euclid(a,b)<<endl;
        }
}
int main()
{
    Read();
    in.close();
    out.close();
    return 0;
}
