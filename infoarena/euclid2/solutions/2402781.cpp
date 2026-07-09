#include <iostream>
#include <fstream>
using namespace std;

int euclid (int a, int b)
{
    int c;
    while (b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    ifstream input;
    ofstream output;
    int n,i,a,b,r;
    input.open("euclid2.in");
    output.open("euclid2.out");

        input>>n;
        for(i=0; i<n; i++)
        {
            input>>a;
            input>>b;

            r=euclid(a,b);


            output<<r<<endl;

        }


    return 0;
}
