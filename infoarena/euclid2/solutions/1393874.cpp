#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int t,a,b,r,i;
    ifstream f("euclid2in.txt");
    ofstream g("euclid2out.txt");
    f>>t;
    for(i=0;i<t;i++)
    {
        f>>a>>b;r=a%b;
        while(r!=0)
        {
           a=b;b=r;r=a%b;
        }
        g<<b<<endl;
    }

    f.close();
    g.close();
    return 0;
}
