
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a,b,r,t;
    fin>>t;
    for(int i=1; i<=t; i++)

    {

     fin>>a>>b;

        while(b!=0)

        {
        r=a%b;
        a=b;
        b=r;
        }
        fout<<a<<"/n" ;

    }




    return 0;
}
