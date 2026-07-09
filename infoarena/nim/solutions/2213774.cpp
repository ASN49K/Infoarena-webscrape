#include <fstream>

using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int main()
{
    int teste,n,x,i,j,sum;
    cin >> teste;
    for(i = 0;i < teste;i++){
        cin >> n;
        sum = 0;
        for(j = 0;j < n;j++){
            cin >> x;
            sum = sum ^ x;
        }
        if(sum > 0)
            cout << "DA\n";
        else
            cout << "NU\n";
    }
    return 0;
}
