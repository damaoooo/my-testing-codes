#include <stdio.h>

int main()
{
	int n=0;
	scanf("%d",&n);
	int count[100000];
	long long sum=0;
	for(int cnt = 0;cnt<n;cnt++){
		int temp=0;
		scanf("%d",&temp);
		sum+=temp;
	}
	printf("%lld\t",sum-n+1);
 } 
