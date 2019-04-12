#include<bits/stdc++.h>
using namespace std;
void modify(int* arr,int* tree,int start,int end,int nodeindex,int idx,int value){
    if(start == end){
        arr[idx] = (value+1)%2;
        tree[nodeindex] = (value+1)%2;
        return;
    }
    int mid = (start+end)/2;
    if(idx>mid){
        modify(arr,tree,mid+1,end,nodeindex*2+1,idx,value);
    }
    else
    modify(arr,tree,start,mid,2*nodeindex,idx,value);
    tree[nodeindex] = tree[nodeindex*2] + tree[nodeindex*2+1];
}
int count(int *tree,int start,int end,int nodeindex,int left,int right){
    
    
    //completely outside
    if(left>end || right < start){
        return 0;
    }
    //completely inside
    if(start>=left && end<=right){
        return tree[nodeindex];
    }
    // partially inside and partially outside
    int mid = (start+end)/2;
    int ans1 = count(tree,start,mid,2*nodeindex,left,right);
    int ans2 = count(tree,mid+1,end,2*nodeindex+1,left,right);
    return ans1+ans2;
}

void buildtree(int* arr,int* tree,int start,int end,int nodeindex){
    if(start ==  end){
        tree[nodeindex]=arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildtree(arr,tree,start,mid,2*nodeindex);
    buildtree(arr,tree,mid+1,end,2*nodeindex+1);
    tree[nodeindex]= tree[nodeindex*2] + tree[nodeindex*2+1];
}
int main() {

	// Write your code here
    int n,q;
    cin >> n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]%2 == 0){
            arr[i] = 1;
        }
        else
        arr[i] = 0;
    }
    int *tree = new int[4*n];
    buildtree(arr,tree,0,n-1,1);
   
    cin >> q;
    while(q--){
        int query,x,y;
        cin >> query >> x >> y;
        if(query==0){
            modify(arr,tree,0,n-1,1,x-1,y);
        }
      else if(query == 1){
            cout << count(tree,0,n-1,1,x-1,y-1)<<endl;
        }
        else
              cout<<(y-x+1-count(tree,0,n-1,1,x-1,y-1))<<endl;
        
     }
}
