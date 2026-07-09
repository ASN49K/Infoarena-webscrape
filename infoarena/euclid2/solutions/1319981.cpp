#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int o,k,b;
    in>>o;
    for(int i=1;i<o;i++)
    {
        in>>k>>b;
        int r=k%b;
        while(r>0)
        {
            k=b;
            b=r;
            r=k%b;
        }
        out<<b<<"\n";
    }
    return 0;
}
