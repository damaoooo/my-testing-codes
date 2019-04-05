#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int m,n,k;
	int point[50][2];
	scanf("%d%d%d",&m,&n,&k);
	for(int cnt=0;cnt<k*k;cnt++){
		scanf("%d%d",&point[cnt][0],&point[cnt][1]);
	}
	int count=0;
	int knife = 0;
	for(int i=1;i<=m,knife<k-1;i++){
		for(int j=0;j<k*k;j++){
			if(point[j][0]==i) count++;
		}
		if(count==k){
			knife++;
			printf("%d ",i);
			count=0;
		}
	}
	printf("\n");
	for(int i=1,knife=0;i<=n,knife<k-1;i++){
		for(int j=0;j<k*k;j++){
			if(point[j][1]==i) count++;
		}
		if(count==k){
			knife++;
			printf("%d ",i);
			count=0;
		}
	}
	return 0;
 } 
