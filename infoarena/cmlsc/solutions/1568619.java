/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package subsir.comun.bun;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author Sorin
 */
class SubsirComunBun {

    /**
     * @param args the command line arguments
     */
    static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        //Cealalta are O(n^2)
        File f=new File("f.in");
        Scanner sc=new Scanner(f);
        int dim1=sc.nextInt(),dim2=sc.nextInt();
        int [] a=new int[dim1],b=new int[dim2];
        for (int i=0;i<dim1;i++) a[i]=sc.nextInt();
        for (int i=0;i<dim2;i++) b[i]=sc.nextInt();
        int [][]m=new int[dim1][dim2];
        for (int i=0;i<dim1;i++)
            for (int j=0;j<dim2;j++)
                if (a[i]==b[j])
                {
                    int d=0;
                    if (i>0) d=m[i-1][j];
                    if (j>0 && m[i][j-1]>d) d=m[i][j-1];
                    m[i][j]=d+1;
                }
                else m[i][j]=0;
        int k=0;
        for (int j=0;j<dim2;j++) if (m[dim1-1][j]==k) 
        {
            k++;
            System.out.printf("%d ",b[j]);
        }
    }
    
}
