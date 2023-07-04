import java.util.* ;
import java.io.*; 
public class Solution {
	public static int firstMissing(int[] arr, int n) {
		// Partition the array to move positives on the left
		// arr = [3, 2, -6, 1, 0]
		int low = 0;
		int high = n-1;

		while (low <= high) {
			if (arr[low] > 0) {
				low++;
			}
			else {
				int t = arr[high];
				arr[high] = arr[low];
				arr[low] = t;
				high --;			}
		} 
    // print(arr, n);
    // System.out.println("low: "+low + " high: "+high);
    // arr = [3, 2, 1, -6, 0] low = 3 high = 0
		for (int i=0; i<low; i++) {
			if(Math.abs(arr[i]) > n) continue;

			arr[Math.abs(arr[i])-1] *= -1;
		}
    // print(arr, n);
    // System.out.println("low: "+low + " high: "+high);
    // arr = [-3, -2, -1, -6, 0] low = 3 high = 0 

		for (int i=0; i<low; i++)
			if (arr[i] > 0) 
				return i+1;

		return low+1;
	}
}

