#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;

int Aflare(int a, int b)
{
     if(a==b)
     return a;
     else
     if(a>b)
     return Aflare(a-b,b);
     else
     return Aflare(a,b-a);
}

void Citire()
{
     f>>n;
     int x,y;
     while(n!=0)
     {
          n--;
          f>>x>>y;
          g<<Aflare(x,y)<<endl;

     }
}

int main()
{Citire();
    cout << "Hello world!" << endl;
    return 0;
}
