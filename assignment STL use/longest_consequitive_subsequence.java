    import java.util.ArrayList;
    import java.util.*;
    public class solution {
     
    	public static ArrayList<Integer> longestSubsequence(int[] arr){
    		// Write your code here
     
          ArrayList<Integer> list = new ArrayList<>();
     
            int maxlength = 0;
            int start = 0,end=0;
            HashMap<Integer, Boolean> map = new HashMap<>();
            for (int i = 0; i < arr.length; i++) {
                map.put(arr[i], true);
     
            }
     
     
     
            for (int i = 0; i < arr.length; i++) {
                if (map.get(arr[i]) == true) {
                    int startc = arr[i];
                    //int startc;
                    int lengthc = 1;
                    int k = arr[i]+1;
                    int l = arr[i]-1;
                  	if (map.containsKey(l))
                      continue;
                  	//System.out.println(arr[i]);
                    while (map.containsKey(k )) {
                        lengthc++;
                        map.put(k, false);
                        k++;
                    }
                    while (map.containsKey(l)) {
                        lengthc++;
                        map.put(l, false);
                        startc = l;
                        l--;
     
                    }
                    if (lengthc > maxlength) {
                      //if (lengthc > maxlength) {
                        maxlength = lengthc;
                        start = startc;
                      	end=k;
                    }
     
                }
     
     
            }
            for (int i = start; i <end; i++) {
                list.add(i);
            }
            return list;
    	}
    }
