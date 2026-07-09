#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    ifstream indata("euclid2.in");
    ofstream outdata("euclid2.out");
    int t, a, b;
    indata>>t;
    for (int i = 0; i < t; i++)
    {
        indata>>a>>b;
        int r = 0;
        do
        {
            r = a % b;
            a = b;
            b = r;
        } while (r != 0);
        outdata<<a<<"\n";
    }
    indata.close(); outdata.close();
    return 0;
}