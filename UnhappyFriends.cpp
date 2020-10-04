#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Mutual(vector<vector<int>> &preferences,int i,int a,int b,int n)
    {
        for(int j=0;j<n-1;j++){
            if(preferences[a][j]==i)
                return true;
            else if(preferences[a][j]==b)
                return false;
        }
        return false;
    }
    
    int unhappyFriends(int n, vector<vector<int>  >&preferences, vector<vector<int>>& pairs) {
        vector<int> ezpairs(n);
        vector<char> unhappy(n,'\0');
        for(auto i:pairs)
        {
            ezpairs[i[0]]=i[1];
            ezpairs[i[1]]=i[0];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!unhappy[i]){
            for(int j=0;j<n-1;j++){
                if(preferences[i][j]==ezpairs[i])break;
                else if(Mutual(preferences,i,preferences[i][j],ezpairs[preferences[i][j]],n)){
                    unhappy[i]=unhappy[preferences[i][j]]=1;
                }
            }
            }
        }
        for(auto i:unhappy)if(i)ans++;
        return ans;
    }
};