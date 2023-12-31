#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int  len=nums1.size();
    vector<int>temp(len);
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(nums1[i]<=nums2[j]){
            temp[k]=nums1[i];
            i++;
        }else{
            temp[k]=nums2[j];
            j++;
        }
        k++;
    }
    while(i<m){
        temp[k]=nums1[i];
        i++;
        k++;
    }
    while(j<n){
        temp[k]=nums2[j];
        j++;
        k++;
    }
    nums1=temp;
    }
};