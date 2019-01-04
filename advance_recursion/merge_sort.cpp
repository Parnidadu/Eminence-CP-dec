/*Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.*/

void mergeSort(int input[], int size){
	// Write your code here
  if(size==0 || size==1){
    return;
  }
  else{
    int mid=size/2;
    mergeSort(input,mid);
    mergeSort(input+mid,size-mid);
    
    //merging the two sorted arrays
    int i=0,j=mid,k=0;
    int temp[size];
    while(i<mid && j<size){
      if(input[i]<input[j]){
        temp[k++]=input[i++];
      }
      else{
        temp[k++]=input[j++];
      }
    }
    while(i<mid){
      temp[k++]=input[i++];
    }
    while(j<size){
      temp[k++]=input[j++];
    }
    //copying arrays to original array
    for(int z=0;z<size;z++){
      input[z]=temp[z];
    }
  }
        
}
