#include <fstream>
using namespace std;
/*long int cmmdc(long long int x, long long int y)
{
    int r;          //variabila auxiliara
    while (y!=0)    //cat timp nu s-a gasit cmmdc
    {
        r=y;        //salvam valoarea lu y in r
        y=x%y;      //y ia valoarea restului
        x=r;        //x devine noul y
    }

    return x;

}*/
int main()
{
    int a, b, t, r;
    ifstream g ("euclid2.in");
    ofstream h ("euclid2.out");
    g>>t;
    while(t--)
    {
    g>>a>>b;              //citire
    while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
    h<<a<<"\n";
    }
    //g.close();
    //h.close();
    //return 0;
}
