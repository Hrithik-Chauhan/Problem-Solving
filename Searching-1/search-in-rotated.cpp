#include<bits/stdc++.h>
using namespace std;
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
        int m=l+(h-l)/2;
        if(nums[m]==target){
            return m;
        }
        else if(nums[m]>=nums[l]){
               if(nums[l]<=target && target<nums[m]){
                   h=m-1;
               }
               else{
                   l=m+1;
               }
        }
        else{
               if(nums[m]<target && target<=nums[h]){
                  l=m+1;}
               else{
                   h=m-1;
               }
        }
        }
        return -1;
    }
    int main(){
        vector<int> nums = {4,5,6,7,0,1,2};int target = 0;
        int a=search(nums,target);
        if(a==-1){
            cout<<"NOT FOUND !!!";
        }else{
        cout<<"INDEX OF ELEMENT IS: "<<a;}
        return 0;
    }