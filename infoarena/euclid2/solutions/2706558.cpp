#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T;
    in >> T;
    for(int i =1; i<=T; i++)
    {
        int a,b;
        in >> a >> b;
        int auxa =a;
        int auxb = b;
        a = max(auxa,auxb);
        b = min(auxa,auxb);
        //cout << a << " " <<b;
        while(true)
        {
            if(a%b == 0)
            {
                out << b;
                break;
            }
            else
            {
                int aux = a%b;
                a = b;
                b = aux;
            }
        }
    }
    return 0;
}
