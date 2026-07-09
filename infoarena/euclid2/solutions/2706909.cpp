#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,M,r;
    fin>>M;
    for(r=1;r<=M;r++)
    {
        fin>>a>>b;
        while(a != b)
        {
            if(a > b)
                a = a - b;
            if(b > a)
                b = b - a;
        }
        fout << a<<endl;
    }
    return 0;
}
