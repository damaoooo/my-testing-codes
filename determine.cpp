#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find_order(int **martix,int order){
	int result = 0;
	for(int i=0;i<order;i++)
	{
		for(int j=0;j<order;j++)
		{
			if(martix[i][j]!= 0 )
			{
				result++;
				break;
			}
		 } 
	} 
	return result;
}

int **find_rest(int **martix,int order,int x){
	int **result_martix;
	result_martix = (int**)malloc((order-1)*sizeof(int*));
	for(int i = 0;i<order-1;i++)
	{
		result_martix[i] = (int*)malloc((order-1)*sizeof(int));
		memset(result_martix[i],0,order-1);
	}
	
	//fill the martix
	for(int i=1;i<order;i++)
	{
		for(int j=0,j_pointer=0;j<order;j++)
		{
			if(j==x) continue;
			int temp = martix[i][j];
			result_martix[i-1][j_pointer++] = temp;
		}
	}
	return result_martix;
}
int determine(int **martix,int initial_order){
	int sum=0,order=find_order(martix,initial_order);
	if(order>2){
		for(int i=0;i<order;i++)
		{
			if(i%2==0) sum += martix[0][i]*determine(find_rest(martix,order,i),order-1);
			else sum -= martix[0][i]*determine(find_rest(martix,order,i),order-1);
		}
	}
	else if (order==2){
		sum = (martix[0][0]*martix[1][1]-martix[1][0]*martix[0][1]);
	}	
	return sum;
}
int main()
{
	int **martix;
	int order = 0;
	printf("please input the order(in the range of 100):");
	scanf("%d",&order);
	printf("please input your martix:\n") ;
	martix = (int **)malloc(order*sizeof(int*));
	for(int cnt=0;cnt<order;cnt++)
	{
		martix[cnt]=(int *)malloc(order*sizeof(int));
	}
	for(int i=0;i<order;i++)
	{
		for(int j=0;j<order;j++)
		{
			scanf("%d",&martix[i][j]);
		}
	}
	printf("the determine is %d\n",determine(martix,order));
	return 0;
 } 
