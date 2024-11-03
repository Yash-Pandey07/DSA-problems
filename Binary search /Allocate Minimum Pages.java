//https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
class Solution 
{
    //Function to find minimum number of pages.
    public static int findPages(int[]A,int N,int M)
    {
        //Your code here
        int start = 0;
      int sum = 0;
      for(int i = 0; i< N ; i++)
      {
          sum+= A[i];
      }
       int end = sum;
      int ans = -1;
       int mid = start +(end-start)/2;
       while(start <= end)
       {
          if(isPoosible(A,N,M,mid))
          {
              ans = mid;
              end = mid-1;
          }
          else{
              start = mid+1;
        }
        mid = start +(end-start)/2;
      }
      return ans;
   }
   static boolean isPoosible(int[]A,int N,int M, int mid){
       int pageSum = 0;
       int studentCount = 1;
       
       for(int i = 0; i< N; i++){
           if(pageSum + A[i] <= mid){
               pageSum+= A[i];
           }
           else{
               studentCount++;
               if(studentCount > M||A[i] > mid){
                   return false;
               }
                   pageSum = 0;
                   pageSum = A[i];
               }
           }
           return true;

    }
