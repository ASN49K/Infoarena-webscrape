#include<fstream>

using namespace std;
int cmmdc(int a, int b)
{
    if(a==b)return a;
    else if(a>b)return cmmdc(a-b,b);
    else return cmmdc(a,b-a);
}
int T,a, b;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");


    f>>T;
    while(f>>a>>b)
    {
        g<<cmmdc(a,b)<<endl;
    }
    return 0;
}
