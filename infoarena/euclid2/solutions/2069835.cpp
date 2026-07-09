#include <iostream>


using namespace std;

int main()
{
   int T,i,a,b,r,cmmdc;
   cout << "Numarul de perechi: ";
   cin >> T;
   for(i=1;i<=T;i++){
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;
    r=a%b;
    while(r)
        {
    a=b;
    b=r;
    r=a%b;
    }
     cout << "CMMDC al acestei perechi este " << b << endl;
    }

    return 0;

}