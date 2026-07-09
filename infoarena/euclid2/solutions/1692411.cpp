#include<iostream>
#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int n,x,y,t;

    for(int i=1; i<=n; i++)
    {
        f>>x; f>>y;

         while(y != 0)
         {
             t=y;
             y=x%y;
             x=t;
         }
        g<<x<<endl;

    }




    cout<<"\n";
    return 0;
}
