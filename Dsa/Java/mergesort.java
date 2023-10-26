public class Mergesort {

//    conquer work start from here
    public static void conquer(int arr[] , int start , int mid , int end)
    {
        int []arr2=new int[end-start +1];
        int index1=start;
        int index2= mid+1;
        int x=0;

        while(index1<= mid && index2<=end)
        {
            if(arr[index1]<=arr[index2])
            {
                arr2[x]=arr[index1];
                x++;
                index1++;           //arr2[x++]=arr[index1++]
            }
            else
            {
                arr2[x++]=arr[index2++];
            }

        }

//        if some array is not ending and other is empty then

        while(index1<=mid)
        {
            arr2[x++]=arr[index1++];
        }
        while (index2<=end)
        {
            arr2[x++]=arr[index2++];
        }

        for (int i=0,j=start;i< arr2.length;i++,j++)
        {
            arr[j]=arr2[i];
        }
    }


//here the divide work is start -----
    public static void divide(int arr[], int start , int end)
    {

        if(start>=end)
        {
            return;
        }
        int mid= start + ((end-start)/2);
//        int mid=(start+end)/2;
        //  end+star/2 this is done but when we solve some code then ther the value of end or start  is bigger then the ans is going
//        out of int

        divide(arr, start, mid);
        divide(arr, mid+1, end);
        conquer(arr,start,mid,end);

    }
    public static void main(String[] args) {
        int [] arr={5,3,7,4,2,1};

        int a= arr.length;
        System.out.println(a);

        divide(arr ,0,a-1);

        for (int i=0;i<a;i++)
        {
            System.out.print(arr[i]+ " ");
        }
        System.out.println(" ");
    }
}
