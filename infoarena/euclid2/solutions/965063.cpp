#include<fstream>
using namespace std;
int main()
{

    int a,b,i,r,aux;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> i;
    for( ; i ;--i)
    {

        in>>a>>b;
        if(b > a)
        {

            aux = a;
            a = b;
            b = aux;
        }
        r = a % b;
        while( r != 0)
        {

            a = b;
            b = r;
            r = a % b;
        }
        out<<b<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
