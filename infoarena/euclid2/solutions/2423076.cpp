#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{int n;
int a,b;
f>>n;
for(int i=1;i<=n;i++)
{
     f>>a>>b;
     while(b)
     {
          int r=a%b;
          a=b;
          b=r;
     }
     g<<a<<endl;
}
    cout << "Hello world!" << endl;
    return 0;
}
