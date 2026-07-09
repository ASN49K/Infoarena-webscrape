//http://www.infoarena.ro/problema/euclid2
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
//cmmdc returneaza cel mai mare divizor prin impartiri a lui a si b
int cmmdc(int &a, int &b)//worst case O(log(max(a,b)))
{
    int r;
    while(b != 0)//cat timp restul nu e 0
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int bcmmdc(int &a ,int &b)//complexitate O((loga + logb)^2)
{
    int d = 0;
    while( a%2 == 0 && b%2 == 0)//cat timp ambele numere sunt pare
    {
        a >>= 1;
        b >>= 1;
        d++;
    }
    while(a != b)
    {
        if( a%2 == 0)
            a >>= 1;
        else
            if( b%2 == 0)
                b >>= 1;
            else
                if (a > b )
                    a = (a - b) >> 1;
                else
                    b = (b - a) >> 1;

    }
    return a * ( 1 << d) ;
}
int main()
{
   int a,b,t;
   in >> t;
   for(int i = 0; i < t ; i++)//pentru fiecare pereche
   {
       in >> a >> b;
       out << bcmmdc(a,b) << '\n';//afisam cmmdc
   }
}
