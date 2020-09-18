#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string inp;
	    cin>>inp;
	    stack<int>s;
	    int i;
	    int n=inp.size();
	    for(i=0;i<n;i++)
	    {
	        if(inp[i]=='(')
	            s.push(i);

	        else if(inp[i]==')'&!s.empty())
	            s.pop();
	    }
	    while(!s.empty())
	    {
	        inp[s.top()]='-';
	        s.pop();
	    }
        // for(char i:inp)
        //     printf("%c",i);
        // printf("\n");
        int ans=0,k=0;
        for(i=0;i<n;i++)
        {
            if(inp[i]=='(')
                s.push('(');

            else if(s.empty()||inp[i]=='-')
            {
                ans=max(ans,k);
                k=0;
                continue;
            }

            else if(inp[i]==')')
            {
                s.pop();
                k+=2;
            }
        }
        ans=max(ans,k);
	    cout<<ans<<endl;
	}
	return 0;
}