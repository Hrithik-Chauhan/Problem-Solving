    #include<bits/stdc++.h>
    using namespace std;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m=nums1.size();
       int n=nums2.size();
       float a[2000];
       int i;
       float med;
       for(i=0;i<m||i<n;i++){
           if(i<m)
           a[i]=nums1[i];
           if(i<n)
           a[m+i]=nums2[i];
       } 
       sort(a,a+(m+n));
       if((m+n)%2==0)
        med=(a[(m+n)/2]+a[((m+n)/2)-1])/2;
        else if((m+n)%2!=0)
        med=a[(m+n)/2];
        return med;
    }
    int main(){
        vector<int> num1={3,4,5,6,7,8,9,10};
        vector<int> num2={23,24,51,76,98};
        double ans=findMedianSortedArrays(num1,num2);
        cout<<ans;
    }
