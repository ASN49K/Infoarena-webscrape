#include<fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int countquiz,number1,number2;
int gcd(int number1,int number2)
{
    if(number2==0)
      return number1;
    else
      return gcd(number2,number1%number2);
}
int main()
{
    cin>>countquiz;
    while(countquiz--)
    {
        cin>>number1>>number2;
        cout<<gcd(number1,number2)<<"\n";
    }
    return 0;
}
