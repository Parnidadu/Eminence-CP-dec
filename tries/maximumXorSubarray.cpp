#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
class TrieNode{
    
public:
    TrieNode* left;
    TrieNode* right;
    
};

void insert(int n, TrieNode* head){
    // every integer if 4 bytes-->>   32 bits
    // so we have to insert at max 0 to 31 bits
    TrieNode* curr=head;
    
    for(int i=31;i>=0;i--){
        int thisbit=(n>>i)&1; // notice
        
        
        if(thisbit==0){
            if(!curr->left){
                curr->left=new TrieNode();
            }
            curr=curr->left;
        }else{
            if(!curr->right){
                curr->right=new TrieNode();
            }
            curr=curr->right;
        }
    }
}




int findMaxXorPair(TrieNode* head,int* arr,int n,int value){
    int max_xor=INT_MIN;
    
    
    TrieNode* curr=head;
    int curr_xor=0;         //  CONTAINS DECIMAL EQUIVALENT VALUE OF MAX ACHEIVEABLE XOR
    for(int j=31;j>=0;j--){// seeing every bit of this value
        int thisbit=(value>>j)&1;
        if(thisbit==0){
            // Move towards 1 (right)to maximise xor if possible
            if(curr->right){
                curr_xor+=pow(2, j);
                curr=curr->right;
            }else{
                curr=curr->left;
            }
        }else{
            // Move towards 0(left) to maximise xor
            if(curr->left){
                curr_xor+=pow(2, j);
                curr=curr->left;
            }else{
                curr=curr->right;
            }
            
        }
        // YAHN UPAR YE TENSION LENE KI ZAROORAT NAI H KI CURR NULL PAHUCH JAEGA
        // BCOZ WORST CASE ME TUM USI NUMBER ITSELF PE TRAVERSE KAR JAOGE
    }
    
    
    return curr_xor;
    
}

int main(){
    int n;
    cin>>n;
    
    //int arr[6]={8,1,2,15,10,5};
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int* xorarr = new int[n];
    for(int i=0;i<n;i++){
        if(i==0){
            xorarr[i]=arr[i];
            continue;
        }
        xorarr[i]=arr[i]^xorarr[i-1];
    }
    
    
    int maxXor=INT_MIN;
    TrieNode* head=new TrieNode();
    for(int i=0;i<n;i++){
        insert(xorarr[i],head);
        int tempXor=findMaxXorPair(head, arr, n,xorarr[i]);
        if(tempXor>maxXor)
            maxXor=tempXor;
    }
    cout<<maxXor<<endl;
    
    
    return 0;
}
