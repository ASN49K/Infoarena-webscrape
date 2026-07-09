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
    int v[T][2];
    for(int i=1;i<=T;i++)
        for(int j = 1;j<=2;j++)
            in >> v[i][j];
    for(int i =1; i<=T; i++)
        {
        int auxa =v[i][1];
        int auxb = v[i][2];
        int a = max(auxa,auxb);
        int b = min(auxa,auxb);
        //cout << a << " " <<b;
        a = a-b;
        while(true)
        {
            if(a%b == 0)
            {
                out << b << endl;
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
