#include <stdio.h>
#include <string.h>
int matix[50][50];
int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	for(int cnt=0;cnt<k*k;cnt++){
		int a,b;
		scanf("%d%d",&a,&b);
		matix[a-1][b-1]=1;
	}
	int count=0,knife=0;
	for(int i=0;i<m,knife<k-1;i++){//i->Êú×ø±ê£¬j->ºá×ø±ê 
		for(int j=0;j<n;j++){
 			if(matix[i][j]==1) count++;
		}
		if(count==k){
			printf("%d ",i+1);
			count=0;
			knife++;
		}
	}
	printf("\n");
	for(int j=0,knife=0;j<n,knife<k-1;j++){
		for(int i=0;i<m;i++){
			if(matix[i][j]==1) count++;
		}
		if(count==k){
			count=0;
			printf("%d ",j+1);
			knife++;
		}
	}
	return 0;
 } 
