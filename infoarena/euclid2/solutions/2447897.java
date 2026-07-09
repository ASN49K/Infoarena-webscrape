/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author dakata
 */
 class Main {
    public static void main(String [] args) throws FileNotFoundException{
        Scanner scanner = new Scanner(new FileInputStream("euclid2.in"));
        PrintStream writer = new PrintStream("euclid2.out");
        int T = Integer.parseInt(scanner.nextLine());
        for(int i = 0 ; i < T;i++){
            String line = scanner.nextLine();
            String [] cuv = line.split(" ");
            int res = gcd(Integer.parseInt(cuv[0]),Integer.parseInt(cuv[1]));
            writer.println(res);
            
        }
    }
    
    static int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b,a%b);
    }
}
