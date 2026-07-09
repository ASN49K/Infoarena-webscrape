#include<fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int countquiz,number1,number2;
int gcd(int number1,int number2)
{
    //caut cel mai mare divizor comun
    //input: number1,number2
    //reprezinta cele 2 numere ale caror care cmmdc trebuie sa il afluu
    //output: number1
    //o sa aiba o valoare egala cu cmmdc al celul 2 valori primite in input
    if(number2==0)
      return number1;
    else
      return gcd(number2,number1%number2);
}
int main()
{
    cin>>countquiz;//numarul de interogatii
    while(countquiz--)
    {
        cin>>number1>>number2;
        cout<<gcd(number1,number2)<<"\n";
    }
    return 0;
}
