#include <fstream>

using namespace std;

long int cmmdc(long int a,long int b )
{

    if(!b) return a;
        else return cmmdc(b,a%b);
}
int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");
    long int a,b,c;
    in>>c;
    for(  ;c ;--c )
    {

    in>>a>>b;
    out<<cmmdc(a,b)<<endl;
    }
    in.close();
    out.close();

    return 0;

}
