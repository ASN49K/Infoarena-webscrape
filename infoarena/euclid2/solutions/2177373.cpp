#include <fstream>
using namespace std;
ifstream date_in("euclid2.in");
ofstream date_out("euclid2.out");

int main()
{
    int teste;
    date_in>>teste;
    for(int p=teste;p;p--)
    {
        int a,b,r=1;
        date_in>>a>>b;
        while(r)
        {
            r=a%b;
            a=b;
            b=r;
        }
        date_out<<a<<"\n";
    }
    return 0;
}
