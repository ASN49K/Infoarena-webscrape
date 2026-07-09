import java.util.Scanner;

public class CelMaiMareDivizorComun {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double r = 0;
		double cmmb;
		
		System.out.print("Cate perechi de numere se introduc: ");
		int rotatie = in.nextInt();
		
		if (rotatie < 1 || rotatie >= 100000) {
			System.out.println("Operatia depaseste numarul maxim de caractere");
		} else {
			for(int i = 0; i < rotatie; i++) {
				System.out.print("Primul numar: ");
				double n1 = in.nextDouble();
				System.out.print("Al doilea numar: ");
				double n2 = in.nextDouble();
				
				while(n1 == 0) {
					n1 = 0;
				} 
				
				while(n1!= 0 && n2 != 0) {
						r = n2;
						n2 = n1%n2;
						n1 = r;
					}
				cmmb = n1 + n2;
				System.out.println ("Cel mai mare divizor comun este: " + cmmb);
				}
			}
		}		 
	}

