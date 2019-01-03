/*Given the code to find out and return the number of digits present in a number recursively. 
But it contains few bugs, that you need to rectify such that all the test cases should pass.
*/
int count(int n){
    if(n == 0){
        return 0;
    }
    int smallAns = 1+count(n / 10);
    return smallAns;
}
