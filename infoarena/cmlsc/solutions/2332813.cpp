#include <iostream>
#include<fstream>
using namespace std;
ifstream fin("numere.in");
ofstream f("numere.in");
ofstream fout("numere.out");
int main()
{
    int n=0,y=0,scif=0,x,mi=162,ma=0;
    while(fin>>n)
    {

        y=n; scif=0;
        while(y!=0)
        {

            if((y%10)!=(y%100))
            {
                scif=scif+y%10;
            }
            y/=10;
        }
        if(scif%2==0)
            fout<<n<<' ';
        if(scif<=mi)
        {
            mi=scif;
             if(n>ma)
                ma=n;

        }


    }

    fout<<"Numarul cu suma cifrelor distincte minima este: "<<mi<<endl;
    fout<<"Nr cu scif max este "<<ma;
    return 0;
}
