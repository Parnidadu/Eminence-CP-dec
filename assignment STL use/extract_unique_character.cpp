#include<set>
char* uniqueChar(char *str){
  std::set<char> s;
  char c[50000];
  char* p=c;
  int i=0,j=0;
    // Write your code here
  while(str[i]!='\0'){
    if(s.find(str[i])==s.end()){
    	s.insert(str[i]);
      	c[j++]=str[i];
    }
    i++;
  }
  c[j]='\0';
return p;
}
