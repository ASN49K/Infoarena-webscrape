/**
Я собираюсь выиграть Шумен
**/
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main(){
    int t,n,x,s;
    fin>>t;
    while(t--)
    {
        fin>>n;
        s=0;
        while(n--)
        {
            fin>>x;
            s^=x;
        }
        if(s) fout<<"DA\n"; /// игрок выигрывает
        else fout<<"NU\n"; /// проигрыватель проигрывает
    }
}
