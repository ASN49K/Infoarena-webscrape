#include <iostream>

using namespace std;

int CMMDC(int a,int b);

int main()
{
    int N;
    cout << "N=";cin >> N;
    int A[2*N];
    cout << "Perechile de numere:" << endl;
    for(int i=0;i<2*N;i+=2)
        cin >> A[i] >> A[i+1];
    cout << "CMMDC dintre:" << endl;
    for(int i=0;i<2*N;i+=2)
        cout << A[i] << " si " << A[i+1] << " = " << CMMDC(A[i],A[i+1]) << endl;
    return 0;
}

int CMMDC(int a,int b)
{
    if(a>b)
        return CMMDC(a-b,b);
    else if(b>a)
        return CMMDC(b-a,a);
    else if(a == b)
        return a;
    else return a;
}
