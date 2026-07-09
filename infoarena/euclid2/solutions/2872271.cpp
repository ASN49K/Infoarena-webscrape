// arhiva educationala 000 Algoritmul lui Euclid infoarena
// 30p time limit exceeded

#include <iostream>
#include <fstream>

using namespace std;
int T, a, b;

int main()
{
    ifstream f ("euclid2.in");
    f>>T;
    ofstream g ("euclid2.out");
    for(int i=1; i<=T; i++)
    {
        f>>a>>b;
        while (b)
        {
            int rest=a%b;
            a=b;
            b=rest;
        }
        g<<a<<endl;
    }

    return 0;
}
