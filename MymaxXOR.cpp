
#include<bits/stdc++.h>
using namespace std;
//
//bool sortbysec(const pair<string,int> &a,const pair<string,int> &b)
//{
//    return (a.second>b.second);
//}
//
//void TeamMarks(vector<pair<string,int> > &data,int sz,string ans,int start)
//{
//    for(int i=start;i<sz;i++)
//    {
//        if(data[i].second==data[i+1].second)
//        {
//            TeamMarks(data,sz,ans,i+1);
//            ans=ans+data[i].first;
//            i++;
//        }
//        else
//            ans=ans+data[i].first;
//    }
//    cout<<ans<<"\n";
//}
//
//int main()
//{
//    vector <pair<string, int> > data;
//    int sz;
//    cin>>sz;
//    for(int i=0;i<sz;i++)
//    {
//        string temp1;
//        int temp2;
//        cin>>temp1>>temp2;
//        data.push_back(make_pair(temp1,temp2));
//    }
//    sort(data.begin(),data.end(),sortbysec);
//    TeamMarks(data,sz,"",0);
//}
//
//


//
//bool check(int k,int l,vector<vector<char> > &a,int n, int m)
//{
//    if(k<0||k>n-1||l<0||l>m-1)
//        return false;
//    else if(a[k][l]=='.')
//        return true;
//
//    return false;
//}
//
//bool check_again(int k,int l,int n,int m,vector<vector<int> > &data,vector<vector<int> > &visits)
//{
//    if(k<0||k>n-1||l<0||l>m-1)
//        return false;
//    if(data[k][l]==1 && visits[k][l]==0)
//        return true;
//
//    return false;
//}
//
//dfs(int i, int j,int n,int m,vector<vector<int> > &data,vector<vector<int> > &visits)
//{
//    int counts=0;
//    counts++;
//    visits[i][j]=1;
//    for(int k=i-1;j<=i+1;++j)
//        for(int l=j-1;l<=j+1;l++)
//            if(check_again(k,l,n,m,data,visits))
//                counts+=dfs(k,l,n,m,data,visits);
//    return counts;
//
//}
//
//int maxCities(vector<vector<char> > &a,int n,int m);
//
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int n,m;
//        cin>>n>>m;
//        vector<vector<char> > a(n,vector<char>(m));
//        for(int i=0;i<n;++i)
//            for(int j=0;j<m;++j)
//                cin>>a[i][j];
//        cout<<maxCities(a,n,m)<<"\n";
//    }
//}
//
//int maxCities(vector<vector<char> > &a,int n,int m)
//{
//    vector<vector<int> > data(n,vector<int>(m,0)),visits(n,vector<int>(m,0));
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            if(a[i][j]=='*')
//            {
//                for(int k=i-1;k<=i+1;++k)
//                    for(int l=j-1;l<=j+1;++l)
//                        if(check(k,l,a,n,m))
//                            data[k][l]=1;
//            }
//        }
//    }
//    int ans=0;
//    for(int i=0;i<n;++i)
//    {
//        for(int j=0;j<m;++j)
//        {
//            if(check_again(i,j,n,m,data,visits))
//                ans+=dfs(i,j,n,m,data,visits);
//        }
//    }
//    return ans;
//}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//void solve(int data[],int student_count)
//{
//    for(int i=0;i<student_count;i++)
//    {
//        for(int j=i+1;j<student_count;++j)
//        {
//            if (data[i]>data[j])
//            {
//                printf("%d ",data[j]);
//                break;
//            }
//            else if(j==student_count-1&&data[i]<data[j])
//                cout<<"-1 ";
//        }
//    }
//    cout<<"-1";
//}
//
//int main()
//{
//    int T;scanf("%d",&T);
//    while(T--)
//    {
//        int student_count;scanf("%d",&student_count);
//        int data[student_count];
//        for(int i=0;i<student_count;++i)
//            scanf("%d",&data[i]);
//        solve(data,student_count);
//    }
//}



int MyXORmax(int data[],int sz)
{
    int maxtemp=0;
    for(int i=0;i<sz;i++)
        for(int j=i+1;j<sz;j++)
            if((data[i]^data[j])>(maxtemp))
                maxtemp=data[i]^data[j];
    return maxtemp;

}

int BetterXORmax(int data[],int sz)
{
    int maxtemp=0,scrap=0;
    vector<int> pairs;
    for(int i=30;i>=0;--i)
    {
        // set the i'th bit in mask
		// like 100000, 110000, 111000..
        scrap|=(1<<i);

        for(int k=0;k<sz;++k)
            
            // Just keep the prefix till
			// i'th bit neglecting all
			// the bit's after i'th bit
            pairs.push_back(data[i]&scrap);
        
        int chngmax = maxtemp|(1<<i);
        
        for(int j=0;j<pairs.size();j++)
           
            // find two pair in set
			// such that a^b = newMaxx
			// which is the highest
			// possible bit can be obtained
            if(find(pairs.begin(),pairs.end(),pairs[j]^chngmax)!=pairs.end())
                maxtemp=chngmax;
        
        // clear the set for next
		// iteration
        pairs.clear();
    }
    return maxtemp;
}

int main()
{
   int T;cin>>T;
   while(T--)
   {
       int sz,ans;
       cin>>sz;int data[sz];
       for(int i=0;i<sz;++i)
        cin>>data[i];
       ans = BetterXORmax(data,sz);
       cout<<ans;
   }
}



