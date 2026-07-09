#include <iostream>
#include <fstream>

using namespace std;
int maxim(int a,int b)
{
     if (a>b) return a;
     else return b;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,n,k;
    f>>n;
    //
    /*
    int cmmdc,i;
    for (k=1;k<=n;k++)
    {
        cmmdc=1;
        f>>a;
        f>>b;
        for (i=2;i<=min(a,b);i++)
        {
            if (a%i==0&&b%i==0) cmmdc=i;
        }
        g<<cmmdc<<"\n";
    }
    */
    //varianta de 30 de puncte
    /*
    for (k=1;k<=n;k++)
    {
        f>>a;
        f>>b;
        while (a!=b)
        {
            if (max(a,b)%min(a,b)==0) break;
            if (a>b) a=a-b;
            else b=b-a;
        }
        g<<min(a,b)<<"\n";
    }
    */
    //varianta de 60 de puncte

    int t;
    for (k=1;k<=n;k++)
    {
        f>>a;
        f>>b;
        while (b!=0)
        {
            t=b;
            b=a%b;
            a=t;
        }
        g<<a<<"\n";
    }

    //varianta de 100 de puncte
    g.close();
    f.close();
    return 0;
}
