#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n , x , y , i;
void cmmdc(int a , int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    out<<a<<"\n";
}
int main()
{
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>x>>y;
        cmmdc(x,y);
    }
    return 0;
}
