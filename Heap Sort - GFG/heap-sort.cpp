//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int i, int n)  
    {
      int lar=i;
        int l=2*i+1,r=2*i+2;
        if(l<n&&arr[l]>arr[lar])
        lar=l;
        if(r<n&&arr[r]>arr[lar])
        lar=r;
        if(lar!=i)
        {
            swap(arr[lar],arr[i]);
            heapify(arr,lar,n);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
       for(int i=(n/2)-1;i>=0;i--){
            heapify(arr,i,n);
        }
    }
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        int t = n-1;
       while (t >0)
       {
        int s = 0;
        swap(arr[s], arr[t]);
        heapify(arr, s, t);
        t--;
    }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends