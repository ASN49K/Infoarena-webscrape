#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int i;
    long long T,a,b;
    ifstream f("euclid2.in.txt");
    ofstream g("euclid2.out.txt");
    f>>T;
     for(i=1;i<=T;i++)
        {f>>a;f>>b;
        while(a!=b)
            {if (a>b)
                a=a-b;
            else b=b-a;}
            g<<a<<endl;}

    f.close();
    g.close();
    return 0;
}
