import java.util.*;

/*
	- You are given a sorted integer array that can contain duplicate entries, i.e., same value might appear more than once.

	- Your task is to create a new sorted array that will not contain any duplicates, i.e., the repeating elements should appear only once.

*/

public class solution 
{
	public static int[] removeDuplicates(int arr[])
	{
		//	write your code here.
      HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < arr.length; i++) {
            set.add(arr[i]);
        }

        // Integer[] arr1 = new Integer[set.size()];

        // arr1 = set.toArray(arr1);
        int[] arr1 = new int[set.size()];
        int j=0;
        for (Integer i : set) {
            arr1[j] = i.intValue();
            j++;
        }
        

        Arrays.sort(arr1);
		return arr1;
	}
}
/*this is a complete code for the problem of coding ninjas*/
