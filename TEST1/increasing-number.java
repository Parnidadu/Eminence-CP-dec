import java.util.*;
public class Solution {
	
	public static void printIncreasingNumber(int n) {
		/* Your class should be named Solution.
		 * Don't write main() function.
	 	* Don't read input, it is passed as function argument.
	 	* Print output as specified in the question
		*/
        printincnumber(n, "");
   		 }
        public static void printincnumber(int n, String str) {
        if (n <= 0) {
            System.out.print(str + " ");
            return;
        }

        if (str.length() == 0) {
            for (int i = 1; i <= 9; i++) {
                String x = Integer.toString(i);
                printincnumber(n - 1, str + x);
            }
        } else {
            for (int i = str.charAt(str.length() - 1) - '0' + 1; i <= 9; i++) {
                String x = Integer.toString(i);
                printincnumber(n - 1, str + x);
		}

	}
  }
}
