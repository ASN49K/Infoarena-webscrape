#include <iostream>
#include <fstream>

using namespace std;

int a, b, T;

int cm(int A, int B)
{
    if(!B)
        return A;
    return cm(B, A % B);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in>>T;

    for(int i = 1; i <= T; i++)
    {
        in>>a>>b;

        out<<cm(a, b)<<endl;
    }

    return 0;
}
