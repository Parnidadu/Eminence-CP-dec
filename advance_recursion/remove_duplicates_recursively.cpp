/*Given a string S, remove consecutive duplicates from it recursively.*/


void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
 
 /* if (input[0] == '\0') 
        return; 
  
     
    if (input[0] == input[1]) { 
          
        int i = 0;  
        while (input[i] != '\0') { 
            input[i] = input[i + 1]; 
            i++; 
        } 

        removeConsecutiveDuplicates(input); 
    }  
    removeConsecutiveDuplicates(input + 1); 
} */
  
  
  
  // above program cause TLE;
  //cout<<input<<" "<<endl;
  //start from here...
  
  
 if(input[0]=='\0'){
    return;
  }
    if(input[0]!=input[1]){
      removeConsecutiveDuplicates(input+1); 
    }else{
    	int i=0;
        while (input[i] != '\0') { 
            input[i] = input[i + 1]; 
            i++; 
        } 
      removeConsecutiveDuplicates(input); 
    }
}
  
  
  
  
  
  
  
