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
    int n,a,b;
    input.open("euclid2.in");
    output.open("euclid2.out");

        input>>n;
        for(int i=0; i<n; i++)
        {
            input>>a>>b;
            output<<euclid(a,b)<<endl;

        }
    input.close();
    output.close();


    return 0;
}
