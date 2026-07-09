#include <iostream>
#include <fstream>

using namespace std;

int cm(int a, int b)
{
    if(!b)
        return a;
    return cm(b, a % b);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int a, b, T;

    in>>T;

    for(int i = 1; i <= T; i++)
    {
        in>>a>>b;

        out<<cm(a, b)<<endl;
    }

    return 0;
}
