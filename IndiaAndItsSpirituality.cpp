#include<bits/stdc++.h>
using namespace std;

bool check(int k,int l,vector<vector<char> > &a,int n, int m)
{
    if(k<0||k>n-1||l<0||l>m-1)
        return false;
    else if(a[k][l]=='.')
        return true;

    return false;
}

bool check_again(int k,int l,int n,int m,vector<vector<int> > &data,vector<vector<int> > &visits)
{
    if(k<0||k>n-1||l<0||l>m-1)
        return false;
    if(data[k][l]==1 && visits[k][l]==0)
        return true;

    return false;
}

dfs(int i, int j,int n,int m,vector<vector<int> > &data,vector<vector<int> > &visits)
{
    int counts=0;
    counts++;
    visits[i][j]=1;
    for(int k=i-1;j<=i+1;++j)
        for(int l=j-1;l<=j+1;l++)
            if(check_again(k,l,n,m,data,visits))
                counts+=dfs(k,l,n,m,data,visits);
    return counts;

}

int maxCities(vector<vector<char> > &a,int n,int m);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char> > a(n,vector<char>(m));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>a[i][j];
        cout<<maxCities(a,n,m)<<"\n";
    }
}

int maxCities(vector<vector<char> > &a,int n,int m)
{
    vector<vector<int> > data(n,vector<int>(m,0)),visits(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='*')
            {
                for(int k=i-1;k<=i+1;++k)
                    for(int l=j-1;l<=j+1;++l)
                        if(check(k,l,a,n,m))
                            data[k][l]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(check_again(i,j,n,m,data,visits))
                ans+=dfs(i,j,n,m,data,visits);
        }
    }
    return ans;
}
