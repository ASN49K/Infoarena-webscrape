/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package celmailungsubsircomun;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author DenisaS
 */
class CelMaiLungSubsirComun {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        int n1, n2;
        Scanner sc = new Scanner(new BufferedReader(new FileReader("cmlsc.in")));
        Writer writer = new BufferedWriter(new FileWriter("cmlsc.out"));
        n1 = sc.nextInt();
        n2 = sc.nextInt();
        byte[] a1 = new byte[n1];
        byte[] a2 = new byte[n2];
        for(int i=0; i<n1; i++)
            a1[i] = sc.nextByte();
        for(int i=0; i<n2; i++)
            a2[i] = sc.nextByte();
        ArrayList<Byte> elemComune = new ArrayList<>();
        ArrayList<Short> index = new ArrayList<>();
        for(int i=0; i<n2; i++)
            for(int j=0; j<n1; j++)
                if(a2[i] == a1[j])
                {
                    elemComune.add(a1[j]);
                    index.add(new Short((short)j));
                }
        int max = 0;
        ArrayList<Byte> sol = new ArrayList<>();
        ArrayList<Byte> incercare = new ArrayList<>();
        incercare.add(elemComune.get(0));
        int i = 0;
        while(i<index.size()-1)
        {
            while(i < index.size()-1 && index.get(i) < index.get(i+1))
            {
                incercare.add(elemComune.get(i+1));
                i++;
            }
            if(incercare.size() > max)
            {
                sol = incercare;
                max = incercare.size();
            }
            if(i<index.size()-1)
            {
                incercare.clear();
                incercare.add(elemComune.get(++i));
            }   
        }
        writer.write(new Integer(sol.size()).toString());
        writer.write('\n');
        for(i=0; i<sol.size(); i++)
        {
            writer.write(sol.get(i).toString());
            writer.write(' ');
        }
        sc.close();
        writer.close();
    }
    
}
