#include<bits\stdc++.h>

using namespace std;

//#define ll long long int

// void maxOR(int data[],int sz)
// {
// 	int ans=0;
// 	int visit[sz];
// 	int *temp_data = new int[sz];
// 	memset(visit,0,sizeof(visit));
// 	for(int i=INT_BITS;i>=0;--i)
// 	{
// 		int max = INT_MIN;
// 		int maxIndex=0;
// 		for(int j=0;j<sz;++j)
// 		{
// 			if(data[j]>max)
// 			{	
// 				max=data[j];
// 				maxIndex=j;
// 			}
// 			if(data[j]&(1<<i))
// 				data[j]^=(1<<i);
// 		}
// 	if (visit[maxIndex]==0)
// 	{
// 		ans++;
// 		visit[maxIndex]=1;
// 	}
// 	}
// 	cout<<ans<<"\n";
// }

// int maxOR(int data[],int sz)
// {
// 	sort(data,data+sz,greater<int>());
// 	int max=data[0];
// 	int count=1;
// 	for(int i=1;i<sz;i++)
// 	{
// 		if((max|data[i]>max))
// 		{
// 			max = max|data[i];
// 			count++;
// 		}
// 	}
// 	return count;
// }

// // Calculating the minimum subset size required for the given req or maxOR of the whole array
// int minSubset(int data[],int sz,int req)
// {
// 	int ans=sz;
// 	ll subsets = pow(2,sz);
// 	//Run from i=000..0 to 111..1(in binary)
// 	for(ll i=0;i<subsets;i++)
// 	{
// 		int temp[sz];
// 		int counter=0;
// 		//setting all values of temp as 0
// 		memset(temp,0,sizeof(temp));
// 		for(int j=0;j<sz;j++)
// 		{	
			
// 			// Check if jth bit in the index is set
//             // If set then add jth element to the subset
// 			if(i&(1<<j))
// 			{	
// 				temp[j]=data[j];
// 				counter++;
// 			}		
// 		}
		
// 		// if the value of maxOR of temp subset is equal to required maxOR and ans 
// 		// is greater than its size counter ans is changed
		
// 		if(req==maxOR(temp,sz,0))
// 			ans=min(ans,counter);
// 	}
// 	return ans;
// }

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
	int T;cin>>T;
	while(T--)
	{
		int sz;cin>>sz;int data[sz];
		for(int i=0;i<sz;++i)
			cin>>data[i];
		int req = maxOR(data,sz,0);
		int subset[sz];
		int ans = sz;
		minSubset(data,sz,0,0,subset,req,ans);
		cout<<ans<<"\n";
	}
}