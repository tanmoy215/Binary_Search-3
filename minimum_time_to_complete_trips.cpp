#include<bits/stdc++.h>
using namespace std;
bool check(int mid,vector<int> &arr,int trip){
    int n = arr.size();
    int count = 1;
    for(int i=0;i<n;i++){
        if(mid>=arr[i]) count++;
        else if(arr[i]%mid==0) count+=arr[i]/mid;
        else count+=(arr[i]/mid+1);
    }
    if(count>trip) return false;
    else return true;
}
int main(){
    int trip;
    cout<<"enter trip Value : ";
    cin>>trip;
    vector<int> arr{1,2,3};
    int n = arr.size();
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(max<=arr[i]){
            max = arr[i];
        }
    }
    int lo = 1;
    int hi = max;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid,arr,trip)==true){
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    cout<<"Final ans is : "<<ans<<endl;
    return 0;
}