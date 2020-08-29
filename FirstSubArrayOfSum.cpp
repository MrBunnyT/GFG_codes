//Code for calculating minimum subset for maximum OR using method 1
#include<bits/stdc++.h> 
using namespace std;

/*
// Recursively calculating the maxOR of any given array
int maxOR(int data[],int sz,int i)
{
	int mOR=data[i];i++;
	if(i<sz)
		mOR|=maxOR(data,sz,i);
	return mOR;
}

void minSubset(int data[],int sz,int pos, int len, int subset[],int req,int &ans) 
{
  	if(pos == sz && maxOR(subset,len,0)==req && len>0) 
  	{
	  //checking the conditions for maxOR in the resultant subset and setting len strictly above 0
	  ans = min(len,ans);
	}
	 else if(pos<sz)
	{
		// Try the current element in the subset.
  		subset[len] = data[pos];
  		minSubset(data,sz,pos+1,len+1,subset,req,ans);
  
  		// Skip the current element.
  		minSubset(data,sz,pos+1,len,subset,req,ans);
	}
}


// driver code 
int main()
{
	int data[]={91,29,58,45,51,74,70};
  	int sz = sizeof(data)/sizeof(0);
	int req = maxOR(data,sz,0);
  	int ans=sz;
  	
  	//creating a temporary subset with all elements 0
  	int subset[sz];
	
  	minSubset(data,sz,0,0,subset,req,ans);
    cout<<ans;
}

// Code contibuted by Adhiraj Singh */

typedef long long int ll;
#define loop(x,n) for(ll x = 0; x < n; ++x)

pair<ll,ll> solve()
{
    ll n, sum;
    cin >> n >> sum;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        v[i] = num;
    }

    ll left{0};
    ll curSum = v[0];
    ll right{0};
    while( !(left > n-1 && right > n-1))
    {
        if( curSum == sum)
        {
            return make_pair(left + 1 , right + 1);
        }
        else if( curSum < sum)
        {
            if( right == n -1)
            {
                break;
            }

            right++;
            curSum += v.at(right);
        }
        else
        {
            curSum -= v.at(left);
            left++;
            if( right < left)
            {
                right = left;
                curSum = v.at(right);
            }

        }
    }

    return make_pair(-1, 0);
}

int main() 
{
    int t;
    cin >> t;
    vector < pair <ll,ll> > op;
    for(int i = 0; i < t; i++)
    {
        op.push_back(solve());
    }

    for( auto p : op)
    {
        if (p.first == -1)
            cout << -1 << endl;
        else
        {
            cout << p.first << " " << p.second << endl;
        }
    }

}
