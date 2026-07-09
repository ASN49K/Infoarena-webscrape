#include <fstream.h>
using namespace std;
ifstream in("euclid2.in", ifstream::in);
ofstream out("euclid2.out", ofstream::out);
int t,a,b,r;
int main()
{
    in >> t;
    for (int i = 1; i <= t; i++)
     {
             a = in.get();
             b = in.get();
             while (b != 0)
             {      
                    r = a % b;
                    a = b;
                    b = r;             
             } 
             out << a << endl;
     }
    return 0;
}
