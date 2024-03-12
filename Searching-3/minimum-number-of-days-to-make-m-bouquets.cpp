#include<bits/stdc++.h>
using namespace std;
 int solve(int mid,vector<int>&bloomDay,int k){
       int ct=0;
       int n=bloomDay.size();
       int total=0;
       for(int i=0;i<n;i++){
           if(mid>=bloomDay[i]){
               ct++;
               if(ct==k){
                   total++;ct=0;
               }
           }else ct=0;
       }

       return total;

   }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m>n/k)return -1;

        int i=1,j=INT_MIN;
        for(int k=0;k<n;k++)j=max(j,bloomDay[k]);
        int mid;
        int ans=INT_MAX;
        while(i<=j){
            mid=i+(j-i)/2;
            if(solve(mid,bloomDay,k)>=m){
               ans=min(ans,mid);
               j=mid-1;
            }
            else i=mid+1;
        }
        return i;
    }
    int main(){
        vector<int> a={1,10,3,10,2};
        int m=3,k=1;
        int ans=minDays(a,m,k);
        cout<<"Minimum days: "<<ans;
        return 0;
    }
