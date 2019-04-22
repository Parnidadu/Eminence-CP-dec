#include<bits/stdc++.h>
using namespace std;
struct Painting{
    int t,c,s;
    //double val;
};

bool comp(Painting p1,Painting p2){
    if(p1.t == p2.t){
        
        if(p1.s == p2.s){
            return p1.c < p2.c;
        }
        
        return p1.s > p2.s;
    }
    return p1.t < p2.t ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long D;
    cin>>n>>D;
    Painting arr[n];
    
    for(int i=0;i<n;i++){
        int t,c,s;
        cin>>t>>c>>s;
        arr[i].t =t;
        arr[i].c = c;
        arr[i].s = s;
    }
    
    sort(arr,arr+n, comp);
    
     //for(int i=0;i<n;i++){
     //   cout<<arr[i].t<<" "<<arr[i].c<<" "<<arr[i].s<<endl;
    //}
    //cout<<endl;
    long cost=0;
    int currTime;
    int currCost;
    int currSer;
    int prevSer=0;
    int prevTime=0;
    
    for(int i=0;i<n;i++){
        if(i == 0){
            currTime = arr[i].t;
            currCost = arr[i].c;
            currSer = arr[i].s;
            cost = cost+currCost;
            D = D - currSer; 
           //cout<<currTime<<" "<<currCost<<" "<<D<<" "<<currSer<<endl;
        }
        else{
            
        if(arr[i].t != currTime ){
            if(prevSer < currSer){
                 prevSer = currSer;
                prevTime = currTime;
             //   cout<<prevSer<<" "<<prevTime<<endl;
            }
            
      if(arr[i].s > prevSer){ 
           int diff = arr[i].t - prevTime-1;
           if(diff > 0){
              D = D - prevSer*diff;
              // cout<<D<<" "<<prevSer<<endl;
           }
           if(D <= 0){
               break;
           }
         
           currTime = arr[i].t;
           currCost = arr[i].c;
            currSer = arr[i].s;
            cost = cost+currCost;
            D = D - currSer;
           // cout<<currTime<<" "<<currCost<<" "<<D<<" "<<currSer<<endl;
         }
            
        }
    }
    }
    
    cout<<cost<<endl;
    return 0;
}
