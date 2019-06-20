import java.util.ArrayList;

public class ValToBin {

	public static void valToBin(int value) {
		ArrayList<Integer> remainders = new ArrayList();
		ArrayList<Integer> binValue = new ArrayList();
		if (value < 0) {
			System.out.println("Error invalid input value");
			return;
		} else {
			while(value != 0) {
				int quotient = value % 2;
				remainders.add(quotient);
				value = value/2;
			}
			for(int i = remainders.size()-1; i >=0; i-- ) {
				binValue.add(remainders.get(i));
			}
		}
		for(int i = 0; i < binValue.size(); i++) {
			System.out.print(binValue.get(i));
		}
	}
	
	public static void printValToBin(int value) {
		if (value < 0) {
			System.out.println("Error");
			return;
		}
		ArrayList<Integer> bString = new ArrayList();
		while(value > 0) {
			int abit = value % 2;
			bString.add(0, abit);
			//update val for next iteration
			value = value/2; // quotient
		}
		if(bString.size() > 0 ) {
			for(int i : bString) {
				System.out.printf("%d", i);
			}
		} else {
			// val prob 0
			System.out.println("0");
		}
		// if bstring length is 0 the print 0
		// else reverse the list print from start to end
	}
	
	public static void printValToBin2(int val) {
		if(val < 0) {
			System.out.println("Error");
			return;
		}
		int rembits[] = new int[32];
		for(int i = 0; i < rembits.length; i++) {
			rembits[i] = 0;
		}
		int countOfBits = 0;
		while(val > 0) {
			int abit = val % 2;
			//add to rembits, increment countofbits
			rembits[countOfBits] = abit;
			++countOfBits;
			val = val / 2;
		}
		if(countOfBits > 0) {
			for(int i = countOfBits - 1; i >= 0; --i)  {
				System.out.printf("%d %n", rembits[i]);
			}
		} else {
			System.out.print("0");
		}
	}
	
	public static void printBitSet(int val) {
		//check bits 0 through 31
		for(int i = 31; i >= 0; i++) {
			if((val & (1 << i)) != 0) { //use bitwise and and left shift operator
				//result is not zero bit but is set
				System.out.printf("%d", 1);
			} else {
				// result is zero but and not set
				System.out.printf("%d", 0);
			}
		}
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		valToBin(-1);
		printValToBin(-1);
		printValToBin2(5);
		printBitSet(-1);
	}

}
