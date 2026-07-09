#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
    while(a!=b)
    if(a>b)
    a=a-b;
    else
    b=b-a;
    return a;}
int main()
{
    int a,b,n,i;
    ifstream f("euclid2.in", ios::in);
    ofstream g("euclid2.out", ios::out);
    f>>n;
    while(n!=0)
    {
               f>>a;
               f>>b;
               g<<cmmdc(a,b);
               n--;}
    f.close();
    g.close();
    return 0;}
