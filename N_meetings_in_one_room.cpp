#include <bits/stdc++.h>
using namespace std;

struct Meeting{
    int start, finish, index;
};

bool sortByfinish(Meeting a, Meeting b)
{
    return a.finish < b.finish;
}

int main() {
	int t;
    scanf("%d",&t);
	while(t--)
	{
	    int sz;scanf("%d",&sz);
	    Meeting inp[sz];
	    for(int i=0;i<sz;i++)
	    {
	        scanf("%d",&inp[i].start);
	        inp[i].index = i+1;
	    }
	    
	    for(int i=0;i<sz;i++)
	        scanf("%d",&inp[i].finish);
	    sort(inp,inp+sz,sortByfinish);
	    
        int i=0;
        printf("%d ",inp[i].index);
        for (int j = 1; j < sz; j++)
        {
          if (inp[j].start >= inp[i].finish)
          {
              printf("%d ",inp[j].index);
              i = j;
          }
        }
        printf("\n");
	}
	return 0;
}