
/*Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.*/



int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    if(size==0){
      return 0;
    }
  else{
  int ans = allIndexes(input+1,size-1,x,output);
    for(int i=0;i<ans;i++){
      output[i]+=1;
    }
    if(input[0]==x){
      int temp=ans;
		for(int i=temp;i>0;i--){
          output[i]=output[i-1];
        }
      output[0]=0;
      return ans+1;
    }else
    	return ans;
  }
}
  
 //this line of code prints the output in reverse order
 /* if(size==0 || size==1){
    return 0;
  }
  else if(input[size-1]==x){
  allIndexes(input,size-1,x,output+1);
    output[0]=size-1;
    }
  else 
    allIndexes(input,size-1,x,output);

  return *output;
}*/
