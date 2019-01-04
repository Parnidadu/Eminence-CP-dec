/* Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything. */


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
  if(size==0 || size==1){
    return;
  }
  int count = 0;
  int first=input[0];
  for(int i=0;i<size;i++){
    if(input[i]<first){
      count++;
    }
  }
  input[0]=input[count];
  input[count]=first;
  int j=size-1;
  int i=0;
  while(i<count && j>count){
    if(input[i]<first){
     i++;
    }
    else if(input[j]>=first){
      j--;
    }
    else{
       int temp;
      temp=input[i];
      input[i]=input[j];
      input[j]=temp;
      i++;
      j--;
    }
    
  }
  quickSort(input,count);
  quickSort(input+count+1,size-count-1);
}
