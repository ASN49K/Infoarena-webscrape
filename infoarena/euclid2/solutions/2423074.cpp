#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;

void Citire()
{
     f>>n;
     int a,b;
     while(n!=0)
     {
          n--;
          f>>a>>b;
          while(b)
          {
               int r=a%b;
               a=b;
               b=r;
          }
          g<<a<<endl;
     }
}

int main()
{Citire();
    cout << "Hello world!" << endl;
    return 0;
}
