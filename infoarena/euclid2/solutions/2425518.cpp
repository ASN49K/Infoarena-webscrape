#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    unsigned int n;
    in>>n;
    unsigned int a,b;
    while(n>0)
    {
        in>>a>>b;
        while(a!=b)
        {
            if(a>b)a=a-b;
            else b=b-a;
        }
        out<<a<<endl;
        n--;
    }
    return 0;
}
