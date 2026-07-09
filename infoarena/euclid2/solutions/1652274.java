/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author DelOvi
 */
public class Main{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

    
        try {
            BufferedReader br = new BufferedReader(new FileReader("euclid2.in"));
            BufferedWriter bw = new BufferedWriter( new FileWriter("euclid2.out"));
            String line;
            int a=0,b=0,total=Integer.parseInt(br.readLine());
            int aux, space;
            for(int i=0;i<total;i++){
            line = br.readLine();
            space = line.indexOf(" ");
            a=Integer.parseInt(line.substring(0, space));
            b=Integer.parseInt(line.substring(space+1,line.length()));

            if(a<b){
            aux=a;
            a=b;
            b=aux;
            }
            
            while(b!=0){
            aux = b;
            b=a%b;
            a=aux;
            }
                bw.write(a);
                bw.newLine();
            }
            br.close();
            bw.close();
        }
        catch (IOException ex) {
            Logger.getLogger(Euclid2.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
    }
    
}
