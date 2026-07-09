#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long int a,b,i,T,y;
    fin>>T;
    for(y=1; y<=T; y++)
    {
        fin>>a>>b;
        while(a!=0 && b!=0)
        {
            if(a>b)
            {
                a=a%b;

            }
            else
            {
                b=b%a;
            }


        }

        if(a==0)
            fout<<b<<endl;
        else
            fout<<a<<endl;











    }
    return 0;
}
