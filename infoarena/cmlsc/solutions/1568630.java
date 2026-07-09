/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package subsir.comun.bun;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Sorin
 */
public class SubsirComunBun {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        //Cealalta are O(n^2)
        Scanner sc=new Scanner(new FileInputStream("cmlsc.in"));
        int dim1=sc.nextInt(),dim2=sc.nextInt();
        int [] a=new int[dim1],b=new int[dim2];
        for (int i=0;i<dim1;i++) a[i]=sc.nextInt();
        for (int i=0;i<dim2;i++) b[i]=sc.nextInt();
        int [][]m=new int[dim1][dim2];
        for (int i=0;i<dim1;i++)
            for (int j=0;j<dim2;j++)
                {
                    int d=0;
                    if (i>0) d=m[i-1][j];
                    if (j>0 && m[i][j-1]>d) d=m[i][j-1];
                    if (a[i]==b[j]) m[i][j]=d+1;
                    else m[i][j]=d;
                }
        int k=1;
        PrintWriter writer = new PrintWriter("cmlsc.out");
        int max=0;
        for (int j=0;j<dim2;j++) if (m[dim1-1][j]>max) max=m[dim1-1][j];
        writer.println(max);
        for (int j=0;j<dim2;j++) if (m[dim1-1][j]==k) 
        {
            k++;
            writer.printf("%d ",b[j]);
        }
          writer.close();
          sc.close();
    }
    
}
