#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{
     int r;
     r=a%b;
     while(r)
    {
            a=b;
            b=r;
            r=a%b;
    }
    return b;
}
int main ()
{
    int a,b,n,i;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>n;
    for(i=0;i<n;i++)
    {
        in>>a;
        in>>b;
        out<<cmmdc(a,b);
        out<<'\n';
    }
    in.close();
    out.close();
    return 0;
}
