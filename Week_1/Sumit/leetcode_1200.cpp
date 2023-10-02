#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diffrence=INT_MAX;
        vector<vector<int>>absolutepairArray;
        for(int i=0;i<arr.size()-1;i++){
            min_diffrence=min(arr[i+1]-arr[i],min_diffrence);

        }
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==min_diffrence){
                absolutepairArray.push_back({arr[i],arr[i+1]});
            }
        }
        return absolutepairArray;
    }
};