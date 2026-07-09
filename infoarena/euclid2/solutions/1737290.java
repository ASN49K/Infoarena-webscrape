package main;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class MainClass {
	private static int contorOfNumbers;
	private static int gcd;
	
	public static void setContorOfNumbers(int newContorOfNumbers) {
		contorOfNumbers = newContorOfNumbers;
	}
	
	
	public static void solveProblem() throws IOException {
		Scanner fin = null;
		Writer fout = null;

		try {
			fin = new Scanner( new File("euclid2.in"));
			fout = new FileWriter("euclid2.out");

			int number;
			number = fin.nextInt();
			setContorOfNumbers(number);
			
			int numberOne, numberTwo;
			while (contorOfNumbers > 0 && fin.hasNextInt()) {
				contorOfNumbers--;
				numberOne = fin.nextInt();
				numberTwo = fin.nextInt();

				euclidAlgorithm(numberOne, numberTwo);
				fout.write(new Integer(gcd).toString() + '\n');
			}
		} finally {
			if (fin != null)
				fin.close();
			if (fout != null)
				fout.close();
		}
	}

	private static void euclidAlgorithm(int numberOne, int numberTwo) {
		
		if (numberOne < 0 && numberTwo < 0) {
			numberOne = -numberOne;
			numberTwo = -numberTwo;
		} else {
			if (numberOne < 0)
				numberOne = -numberOne;
			if (numberTwo < 0)
				numberTwo = -numberTwo;
		}
		
		if (numberOne == 1 || numberTwo == 1){
			gcd = 1;	
			return;
		}
			
		if (numberOne == 0 || numberTwo == 0){
			gcd = numberOne > numberTwo ? numberOne : numberTwo; 
			return;	
		}
		
		if (numberOne > numberTwo)
			euclidAlgorithm(numberTwo, numberOne % numberTwo);
		else euclidAlgorithm(numberOne, numberTwo % numberOne);
	
	};
	public static void main(String args[]){
		
		try {
			solveProblem();
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
