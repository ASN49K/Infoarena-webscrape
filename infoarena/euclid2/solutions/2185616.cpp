#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,x,y,Div;

int main()
{
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>x>>y;
           while(x!=y)
       {
           if(x>y)
             x-=y;
          else
            y-=x;
       }

        fout<<y<<endl;
    }
    return 0;
}
