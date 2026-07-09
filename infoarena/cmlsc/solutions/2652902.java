import java.util.Scanner;
import java.io.*;
import java.io.FileNotFoundException;
import java.lang.Exception;



public class Main{

    public static int max(int a, int b){
        if (a > b)
            return a;
        return b;
    }
    
    public static int min(int a, int b){
        if (a < b)
            return a;
        return b;
    }

    public static void main(String args[]) throws FileNotFoundException{
        File file = new File("cmlsc.in");
        Scanner sc;
        try{
            sc = new Scanner(file);
        }
        catch (FileNotFoundException e){
            System.out.println("File not found");
            return;
        }  
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] v = new int[n];
        int[] w = new int[m];
        
        for(int i = 0;i < n;i++)
            v[i] = sc.nextInt();
        for(int i = 0;i < m;i++)
            w[i] = sc.nextInt();       
        
        int[][] mat = new int[n + 1][m + 1];
        for (int i = 1;i <= n;i++){
            for(int j = 1; j <= m;j++){
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
                if (v[i-1] == w[j-1]){
                    mat[i][j]++;
                }
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
        int bst = 0;
        int[] sir = new int[min(n,m)];
        int i = n-1;
        int j = m-1;
        while (j >= 0 && i >= 0){
            // System.out.print(v[i] + " " );
            // System.out.println(w[j]);

            if (v[i] == w[j]){
                sir[bst] = v[i];
                bst++;
                i--;
                j--;
            }
            else if (mat[i + 1][j] > mat[i][j + 1])
                j--;
            else
                i--;
        }
        
        try{
            Writer wr = new FileWriter("cmlsc.out");
            wr.write(String.valueOf(mat[n][m]) + "\n");

            for (i = bst - 1;i >= 0;i--){
                wr.write(sir[i] + " ");
            }
            wr.close();
        }
        catch(Exception e){
            System.out.println("Exceptie");
        }

    }
}