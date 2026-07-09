#include <fstream>

using namespace std;

ifstream in;
ofstream out;

int main()
{
    int N,s,Test,x;

    in.open("nim.in");

    in>>Test;

    out.open("nim.out");

    for(;Test--;)
    {
        in>>N;
        s=0;
        for(;N--;)
        {
            in>>x;
            s^=x;
        }

        if(s) out<<"DA\n";
        else out<<"NU\n";
    }

    in.close();
    out.close();

    return 0;
}
