#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int t,nrt,a,b,x,y,cmmmc;

    in>>t;

    for(nrt=0;nrt<t;++nrt)
    {
        in>>a>>b;

        x=a;
        y=b;
        /*while(a!=b)
            if(a>b) a-=b;
            else b-=a;*/

        while(a!=0 && b!=0)
        {
            if(a>b) a%=b;
            else b%=a;
        }

        if(b>a) a=b;
        out<<a<<"\n";
        //cmmmc=x*y/a;
        //out<<a<<"\n"<<cmmmc;
    }

    in.close();
    out.close();
    return 0;
}
