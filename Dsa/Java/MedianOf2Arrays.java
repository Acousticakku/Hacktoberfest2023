
import java.util.*;

public class MedianOf2Arrays
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of first array");
        int n1 = sc.nextInt();
        int[] arr1 = new int[n1];
        System.out.println("Enter the values of the first array.");
        for(int i=0; i<n1; i++)
            arr1[i] = sc.nextInt();

        System.out.println("Enter the size of second array");
        int n2 = sc.nextInt();
        int[] arr2 = new int[n2];
        System.out.println("Enter the values of the second array.");
        for(int i=0; i<n2; i++)
            arr2[i] = sc.nextInt();

        Solution sol = new Solution();
        double med = sol.findMedianSortedArrays(arr1, arr2);
        System.out.println("Median is: "+ med);
        sc.close();
    }
}

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) 
    {
        int i;
        double median;
        ArrayList<Integer> al = new ArrayList<>();
        for(i=0; i<(nums1.length); i++)
            al.add(nums1[i]);
        
        
        for(i=0; i<(nums2.length); i++)
            al.add(nums2[i]);
        
        int arr[] = new int[al.size()];

        for(i=0; i<arr.length; i++)
            arr[i] = al.get(i);

        Arrays.sort(arr);

        int len = arr.length;
        if(len%2==0)
            median = (double)(arr[len/2]+arr[len/2 - 1]) / 2;

        else
            median = arr[len/2];
        

        return median;
    }
}
/*
 * Output is:
 * Enter the size of first array
4
Enter the values of the first array.
23
34
46
12
Enter the size of second array
4
Enter the values of the second array.
2
67
33
19
Median is: 28.0

Explanation : Sorted numbers are : 2, 12, 19, 23, 33, 34, 46, 67
              median = (23 + 33) / 2 = 56/2 = 28  
 * 
 */
