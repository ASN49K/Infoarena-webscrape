#include <iostream>
#include <fstream>

using namespace std;
fstream f1("cmlsc.in", ios::in);
fstream f2("cmlsc.out", ios::out);
int matrix[1025][1025]; int arr[1025]; int k=0;
int backLCS(int matrix[1025][1025], int rows, int cols)
{
    int i,j;
    i=rows; j=cols;
    if (matrix[i][j]==0)
    {
        return 1;
    }
    //matrix[rows][cols]
    if (matrix[i][j-1]==matrix[i][j])
    {
        j--;
        backLCS(matrix, i, j);
    }
    else if (matrix[i-1][j]==matrix[i][j])
    {
        i--;
        backLCS(matrix,i,j);
    }
    else {
        arr[k]=matrix[0][j];
        k++;
        backLCS(matrix,i-1,j-1);
    }
}
int matrice(int length1, int length2, int s1[], int s2[])
{
    int rows=length1+1;
    //cout << "hyh " << length1;
    int cols=length2+3;
    int i,j,x,y,h;
    for (i=0;i<length1;i++)
    {
        matrix[0][i+2]=s1[i];
    }
    for (i=0;i<length2;i++)
    {
        matrix[i+2][0]=s2[i];
    }
    for (i=2;i<=rows;i++)
    {
        for (j=2;j<=cols;j++)
        {
            if (matrix[i][0]==matrix[0][j])
            {
                matrix[i][j]=matrix[i-1][j-1]+1;
            }
            if (matrix[i][0]!=matrix[0][j])
            {
                x=matrix[i-1][j];
                y=matrix[i][j-1];
                if (x>y)
                {
                    h=x;
                }
                else h=y;
                matrix[i][j]=h;
            }
        }
    }
  /*  cout << "rows " << rows;
    for (i=0;i<=rows;i++)
    {
        for (j=0;j<=cols;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } */
    int t=backLCS(matrix,rows,cols);
   // cout << endl << endl;
  /*  for (i=0;i<=rows;i++)
    {
        for (j=0;j<=cols;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } */
    f2 << k << endl;
    for (i=k-1;i>=0;i--)
    {
        f2 << arr[i] << " ";
    }

}
int main()
{
    //fstream f1("lcs.in", ios::in);
   // fstream f2("lcs.out", ios::out);
    int length1,length2;
    int s1[1025],s2[1025];
    int ok=0;
   // cout << "yay";

    f1 >> length1;
    f1 >> length2;
    int i;
       if (length1 > length2)
    {
        ok=1;
    }
   // cout << "h";
    for (i=0;i<length1;i++)
    {
        f1 >> s1[i];
    }
    for (i=0;i<length2;i++)
    {
        f1 >> s2[i];
    }
    //cout << ok;
    if (ok==1) {
        matrice(length1, length2, s1, s2);
    }
    else matrice(length2, length1, s2, s1);



    return 0;
}
