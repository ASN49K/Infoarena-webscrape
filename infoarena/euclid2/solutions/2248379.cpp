#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int a, b, T;

    in>>T;

    for(int i = 1; i <= T; i++)
    {
        in>>a>>b;

        while(b != a)
            {
                if(a > b)
                    a = a - b;
                else
                    b = b - a;
            }
        out<<a<<endl;
    }



    return 0;
}
