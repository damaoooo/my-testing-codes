#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	int repeat[1000];
	memset(repeat,0,sizeof(repeat));
	for(int cnt=0;cnt<m;cnt++) scanf("%d",&repeat[cnt]);
	sort(repeat,repeat+m,cmp);
	printf("%d\n",repeat[k-1]);
	return 0;
}
