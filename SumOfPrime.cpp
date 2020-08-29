#include <bits/stdc++.h>
using namespace std;

int sz = 1000000;
vector <bool> is_prime(sz+1,true);
void Sieves()
{
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=sz;i++)
        if(is_prime[i])
        for(int j=i*i;j<=sz;j++)
            if(j%i==0)
                is_prime[j]=false;
}

pair<int,int> Solve(int inp)
{
    for(int i=2;i<inp-1;i++)
    {
        if(is_prime[i] && is_prime[inp-i])
            return make_pair(i,inp-i);
    }
    return make_pair(-1,0);
}

int main()
{
    Sieves();
    int T;cin>>T;
    pair<int,int> ans[T];
    for(int i=0;i<T;i++)
    {
        int inp;cin>>inp;
        ans[i]=Solve(inp);
    }
    for(int i=0;i<T;i++)
    {
        if(ans[i].first==-1)
        cout<<"-1\n";
        else
        cout<<ans[i].first<<' '<<ans[i].second<<"\n";
    }
}