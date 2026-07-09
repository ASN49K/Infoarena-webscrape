#include <fstream>
#include <algorithm>
using namespace std;
unsigned long a,b,c,t;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    fin>>t;
    while(t)
    {
        fin>>a>>b;
        if(a<b)
            swap(a,b);
            c=a%b;
            while(c)
            {
                a=b;
                b=c;
                c=a%b;
            }
        fout<<b<<endl;
        --t;
    }
    return 0;
}
