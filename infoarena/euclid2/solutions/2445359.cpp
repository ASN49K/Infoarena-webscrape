#include <iostream>
#include <fstream>



using namespace std;

int divizor(int a, int b)
{
    int d = 0;
    for(int i=min(a,b); i>=0; i--)
    {
        if (a%i == 0 and b%i ==0)
        {
            d = i;
            break;
        }
    }
    return d;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n, a, b;
    in>>n;
    for(int i = 0; i< n; i++)
    {
        in>> a>>b;
        out<<divizor(a, b)<<endl;
    }

    return 0;
}
