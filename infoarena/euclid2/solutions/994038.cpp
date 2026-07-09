#include <fstream>

using namespace std;

int cmmdc(int a,int b )
{

    if(!b) return a;
    return cmmdc(b,a%b);
}
int main()
{
    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");
    int a,b,c;
    in>>c;
    for(  ;c ;--c )
    {

    in>>a>>b;
    out<<cmmdc(a,b)<<endl;
    }


    return 0;

}
