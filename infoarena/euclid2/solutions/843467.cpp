#include<fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long a,b,c,t,i;
    f>>t;
    for (i=0;i<t;++i)
{


    f>>a>>b;

    while(b)
    {
        c=b;
        b=a%b;
        a=c;
    }
    g<<a<<endl;
}
}
