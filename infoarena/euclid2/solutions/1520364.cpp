#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a,int b)
{
    if(!b)return a;
    return euclid(b,a%b);
}

int main()
{
    int a,b,n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>n;

    while(n)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
        n--

    }

      g.close();
      f.close();
    return 0;
}
