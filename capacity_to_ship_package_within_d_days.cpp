#include<bits/stdc++.h>
using namespace std;
bool check(int mid, vector<int> &arr, int day){
    int m = mid;
    int count = 1;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(m>=arr[i]){
            m-=arr[i];
        }
        else{
            count++;
            m = mid;
            m-=arr[i];
        }
    }
    if(count>day) return false;
    else return true;
}
int main(){
    vector<int> arr{3,2,2,4,1,4};
    int day = 3;
    int n = arr.size();
    int max = arr[0];
    int sum=0;
    for(int i=0;i<n;i++){
        if(max<=arr[i]){
            max = arr[i];
        }
        sum+=arr[i];
    }
    int lo = max;
    int hi = sum;
    int capacity = sum;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid,arr,day)){
            capacity = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    cout<<"Final capacity is : "<<capacity<<endl;
    return 0;
}