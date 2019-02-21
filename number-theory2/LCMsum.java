import java.util.*;
public class Solution {


	public static void func(long n)
	{

		// Write your code here
       long sum = n;
        for (long i = 2; i <= n; i++) {
            long product = i * n;
            sum += product / gcd(n, i);
        }
        System.out.println(sum);
    }

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
        
		}
}
