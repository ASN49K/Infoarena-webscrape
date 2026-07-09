#include <iostream>
#include <fstream>


using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a,b,r,nr;
    fin>>nr;
    for(int i=0;i<nr;i++)
    {
        fin>>a>>b;



    if(a>b)
    {
        r=a-b;
         while(r>b)
         {
             r=r-b;
         }
          fout<<r<<endl;
    }
    if(b>a)
    {
        r=b-a;
        while(r>a)
        {
             r=r-a;
        }
        fout<<r<<endl;;
    }
    }




}
