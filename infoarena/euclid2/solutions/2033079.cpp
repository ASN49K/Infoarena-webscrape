#include <iostream>
#include <fstream>
using namespace std;

void prop(int a, int b)
{
      while(a!=b)
            if(a>b) a=a-b;
            else b=b-a;
}
int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    int n, r, a, b;
    f>>n;
    for(int i = 0; i < n; i++)
    {
        f>>a>>b;
        while(a!=b)
            if(a>b) a=a-b;
            else b=b-a;
        g<<a<<endl;
    }
    return 0;
}
