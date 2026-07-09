package cmmd;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.Scanner;

public class Main{
	
	Scanner in;
	
	static int poz = 1;
	
	static int a,b;
	
	public static void main(String[] args) throws Exception {
		
		Main object = new Main();
		
		String fname = "C:\\\\Users\\\\Raul\\\\Desktop\\\\euclid2.in";
		
		Formatter f = new Formatter("C:\\\\\\\\Users\\\\\\\\Raul\\\\\\\\Desktop\\\\\\\\euclid2.out");
		
		object.in = new Scanner(new File(fname));
		
		ArrayList<String> lista = new ArrayList<String>();
		
		while(object.in.hasNext()) {
			lista.add(object.in.next());
			poz++;
		}
		
		poz = 1;
		
		int n = Integer.parseInt(lista.get(0));
		
		for(int j = 0; j < n;j++) {
			a = Integer.parseInt(lista.get(poz));
			poz++;
			b = Integer.parseInt(lista.get(poz));
			poz++;
			for(int i = Main.min(a,b); i > 0 ;--i) {
				if(a % i == 0 && b % i == 0) {
					f.format("%s", i);
					System.out.println(i);
					break;
				}
			}
		}
		
	}
	
	public static int min(int a,int b) {
		
		if(a<b) return a;
		else return b;
		
	}
	
}
