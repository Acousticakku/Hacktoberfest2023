public class Quicksort {
    public static int partition(int arr[] , int low , int high)
    {
        int pivot= arr[high];
        int i=low-1;

        for(int j=low;j<high;j++)
        {
            if(arr[j]<pivot)
            {
                i++;
//                swap
                int temp=arr[i];
                arr[i]= arr[j];
                arr[j]= temp;
            }
        }
        i++;
        int temp=arr[i];
        arr[i]= pivot;
        arr[high]= temp;


        return i;
    }

    public static void quiksort(int arr[] , int low , int high)
    {
        if(low<high)
        {
            int pivot_ind= partition(arr , low , high);
//

            quiksort(arr , low , pivot_ind-1);
            quiksort(arr , pivot_ind+1 , high);

        }

    }
    public static void main(String[] args) {
        int []arr = {24 ,18 ,38 ,43, 14 ,40, 1, 54};

        quiksort(arr , 0 , arr.length-1);

//        print
        for(int i=0;i< arr.length;i++)
        {
            System.out.println(arr[i]);
        }
    }
}
