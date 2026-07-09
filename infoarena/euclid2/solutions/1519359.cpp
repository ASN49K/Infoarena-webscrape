#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long int a,b,c=-1,i,T,y;
    fin>>T;
    for(y=1; y<=T; y++)
    {
        fin>>a>>b;

        if(a==0)
        {
            fout<<b<<endl;
        }
        else if(b==0)
        {
            fout<<a<<endl;
        }
        else
        {


            for(i=1; i<a; i++)
            {
                if(a%i==0 && b%i==0)
                {
                    c=i;
                }
            }



                fout<<c<<endl;


        }
    }
    return 0;
}
