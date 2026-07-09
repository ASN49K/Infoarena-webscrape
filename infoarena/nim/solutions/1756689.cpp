#include <iostream>
#include <fstream>
using namespace std;

int T,el,all,n;

int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    f >> T;
    while(T--){
        all = 0;
        f >> n;
        for(int i=0;i<n;i++){
            f >> el;
            all = all ^ el;
        }
        if(all) g << "DA\n";
        else g << "NU\n";
    }
    f.close();
    g.close();
    return 0;
}
