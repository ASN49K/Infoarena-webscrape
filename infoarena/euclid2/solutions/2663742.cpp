#include <fstream>

using namespace std;

int cmmdc(int a, int b){
    int rest = 0;
  while(b!=0){
    rest = a%b;
    a=b;
    b=rest;
    }

    return a;
}
int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n , a, b, r;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a >> b;
       cout << cmmdc(a, b) << endl;
    }
    return 0;
}
