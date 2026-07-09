#include <fstream>
using namespace std;
ifstream f("submultimi.in");
ofstream g("submultimi.out");

void rezolv(int n){
    for(int i=1; i<= (1<<n) -1; i++)
    {
        for(int j=0; j<=15; j++)
            if( ( (i>>j) &1 ) == 1)
                g << j+1 << ' ';
        g << '\n';
    }
}

int main()
{
    int n;
    f>>n;
    rezolv(n);
    f.close();
    g.close();
    return 0;
}
