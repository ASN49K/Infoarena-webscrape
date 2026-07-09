#include<iostream>
#include<fstream>


ifstream f("euclid.in");
ofstream g("euclid.out");


using namespace std;

int main()
{
    int n,x,y;
    int t;

    for(int i=1; i<=n; i++)
    {
        f>>x; f>>y;

         while(y != 0)
         {
             t=b;
             b=a%b;
             a=t;
         }
        g<<a<<endl;

    }




    cout<<"\n";
    return 0;
}
