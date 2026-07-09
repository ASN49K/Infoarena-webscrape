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
    long long int v[T][2];
    for(int i = 1; i<=T; i++)
        for(int j=1; j<=2; j++){
            cin >> v[i][j];
            long long int nr;
            if(j==2)
            {
                for(long long int x=2;true;x++)
                    if(v[i][1]%x==0 && v[i][2]%x==0 && x <= min(v[i][1],v[i][2]))
                        nr = x;
                    else if(x > min(v[i][1],v[i][2]))
                        break;
            }
            out << nr;
        }
            return 0;
}
