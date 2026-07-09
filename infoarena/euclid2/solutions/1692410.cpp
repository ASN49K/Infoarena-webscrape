#include<iostream>
#include<fstream>

using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");

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
