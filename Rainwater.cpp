#include<bits\stdc++.h>
using namespace std;

int Rainwater(int data[],int sz,int n)
{
	int ans=0;
	int max_left=INT_MIN;
	int max_right=INT_MIN;
	for(int i=n;i<sz;i++)
		max_right=max(data[i],max_right);
	for(int i=n;i>=0;i--)
		max_left=max(data[i],max_left);
	ans = max((min(max_left,max_right)-data[n]),0);
	n++;
	if(n<sz)
		ans += Rainwater(data,sz,n);
	return ans;
}


int main()
{
	int T;cin>>T;
	while(T--)
	{
		int sz;cin>>sz;int data[sz];
		for(int i=0;i<sz;++i)
			cin>>data[i];
		cout<<Rainwater(data,sz,1)<<" \n";
	}
}
