#include <bits/stdc++.h>
using namespace std;

// Efficient C++ program to find maximum number 
// of characters between two occurrences of 
// same character 
#include <bits/stdc++.h> 
using namespace std; 

int Solve(string &inp)
{
    int sz=256;
    int n = inp.length();
    int ans=0;
    int starts[sz];
    memset(starts,-1,sizeof(starts));
    for (int i = 0; i < n; i++)
    {
        int start = starts[inp[i]];
        if(start == -1)
            starts[inp[i]]=i;
        else
        {
            ans = max(ans,abs(i-start-1));
        }
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    int t;cin>>t;
    while(t--)
    {
        string inp;
        cin>>inp;
        cout<<Solve(inp)<<"\n";
    }
}