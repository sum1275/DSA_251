#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void merge(vector<int>&count,vector<pair<int,int>>&vect,int left,int mid,int right){
    vector<pair<int,int>>temp(right-left+1);
    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=right){
        if(vect[i].first <=vect[j].first){
            temp[k++]=vect[j++];
        }else{
            count[vect[i].second]+=right-j+1;
            temp[k++]=vect[i++];
        }

    }
    while(i<=mid){
        temp[k++]=vect[i++];
    }
    while(j<=right){
        temp[k++]=vect[j++];
    }
    for(int i=left;i<=right;i++){
        vect[i]=temp[i-left];
    }
}
  void mergeSort(vector<int> &count, vector<pair<int,int>> &vect, int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(count,vect,left,mid);
        mergeSort(count,vect,mid+1,right);
        merge(count,vect,left,mid,right);
    }
}

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>vect(n);
        for(int i=0;i<n;i++){
            pair<int,int>p;
            p.first=nums[i];
            p.second=i;
            vect[i]=p;
        }
        vector<int>count(n,0);
        mergeSort(count,vect,0,n-1);
        return count;

    }
};