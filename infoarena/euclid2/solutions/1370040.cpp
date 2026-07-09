#include<iostream>
#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main(void)
{
    int a,b,c,d,i;
    in>>a;
    for(i=1;i<=a;i++)
    {
        in>>b;
        in>>c;
        while(c!=0)
        {
            d=b%c;
            b=c;
            c=d;
        }
        out<<b<<endl;
    }
    in.close();
    out.close();
    return 0;
}
