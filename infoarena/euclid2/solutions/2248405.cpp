#include <iostream>
#include <fstream>

using namespace std;

int cm(int a, int b)
{
    int r;
     while(b != 0)
            {
                r = a % b;
                a = b;
                b = r;
            }
        return a;
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
