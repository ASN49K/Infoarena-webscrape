#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a,b,r,t;
int main()
{
    in>>t;
    while(t)
    {
    in>>a>>b;
    if(a<b)
       swap(a,b);
    r=1;
    while(r!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    out<<a<<'\n';
    t--;
    }
    in.close();
    out.close();
    return 0;
}
