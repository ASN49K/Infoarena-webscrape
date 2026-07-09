#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <list>
#include <map>
#include <math.h>
#define NMAX 100001
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int main() {
    int n;
    f>>n;
    while(n--)
    {
        int x;
        f>>x;
        int suma = 0 ;
        for(int i=1;i<=x;i++)
        {
            int nr;
            f>>nr;
            suma= suma ^ nr;
        }
        if(suma)g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
