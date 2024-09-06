#include<bits/stdc++.h>
using namespace std;
int check(int mid, vector<int> &arr,int h){
    int n = arr.size();
   int count = 0;
    for(int i=0;i<n;i++){
        if(mid>=arr[i]) count++;
        else if(arr[i]%mid) count+=arr[i]/mid;
        else count+=(arr[i]/mid + 1); 
    }
    if(count>h) return false;
    else return true;
}
int main(){
    int h = 8;
    vector<int> arr{3,6,7,11};
    int n = arr.size();
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(max<=arr[i]){
            max = arr[i];
        }
    }
    int lo =1;
    int hi = max;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid,arr,h)==true){
            ans = mid;
            hi = mid-1;
    }
    else{
       lo = mid+1;
     }

    }
    cout<<"Final ans is : "<<ans<<endl;
    return 0;
}