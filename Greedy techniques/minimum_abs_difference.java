import java.util.*;
public class Solution {

	public static int minAbsoluteDifference(int input[]) {
		/* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
		 * Taking input and printing output is handled automatically.
		 */
    Arrays.sort(input);
        int min=Integer.MAX_VALUE;
        for(int i=0;i<input.length-1;i++){
            int diff=Math.abs(input[i]-input[i+1]);
            if(diff<min){
                min=diff;
            }


        }
    return min;
	}

}
