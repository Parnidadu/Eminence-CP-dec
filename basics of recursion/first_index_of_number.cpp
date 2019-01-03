/*Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array.
Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
*/
int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  if(size==0 || (size==1 && *input!=x)){
    return -1;
  }
  if(*input==x){
    return 0; 
  }
  int ans=firstIndex(input+1,size-1,x);
  if(ans==-1){
    return -1;
  }
  else
    return ans+1;
}
