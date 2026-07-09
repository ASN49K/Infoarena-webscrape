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
        while(a!=b)
        {
            if(a>b)
            {
                a-=b;

            }
            else
            {
                b-=a;
            }


        }

        fout<<a<<endl;











    }
    return 0;
}
