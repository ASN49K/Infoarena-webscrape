#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("nim.in");
    ofstream out("nim.out");
    int n, m, rez = 0,x;

    in>>n;
    for(int i=0;i<n;i++){
        in>>m;
        rez = 0;
        for(int j=0;j<m;j++){
            in>>x;
            rez = rez ^ x;
        }
        if(rez==0)
            out<<"NU\n";
        else out<<"DA\n";
    }

    return 0;
}
