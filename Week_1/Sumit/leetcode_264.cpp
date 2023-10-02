#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int>dp(n);
       int i=0,j=0,k=0;
       dp[0]=1;
       for(int it=1;it<n;it++){
           int twomultiple=dp[i]*2;
           int threemultiple=dp[j]*3;
           int fivemultiple=dp[k]*5;
           dp[it]=min(twomultiple,min(threemultiple,fivemultiple));
           if(dp[it]==twomultiple)
           i++;
           if(dp[it]==threemultiple)
           j++;
           if(dp[it]==fivemultiple)
           k++;
       }
       return dp[n-1];
    }
};