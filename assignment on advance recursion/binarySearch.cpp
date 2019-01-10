#include <iostream>
using namespace std;
int binarySearching(int input[], int element, int start, int end) {

        int mid = (end + start) / 2;
        if (start >= end) {
            return -1;
        }
        if (input[mid] == element) {
            return mid;

        }
        if (element > input[mid]) {
            return binarySearching(input, element, mid + 1, end);
        }
        return binarySearching(input, element, start, mid - 1);

}

int binarySearch(int input[], int size, int element) {
    // Write your code here
  return binarySearching(input, element, 0, size);

    }
    int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
