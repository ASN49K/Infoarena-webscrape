#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,x,y,Div;

void Euclid(int x,int y)
{
   while(x!=y)
   {
       if(x>y)
        x=x-y;
       else
        y=y-x;
   }
   Div=y;
}
int main()
{
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>x>>y;
        Euclid(x,y);
        fout<<Div<<endl;
    }
    return 0;
}
