#include <stdio.h>
int main()
{
	long long P,Q;
	scanf("%lld%lld",&P,&Q);
	long long count =0;
	if(P==Q){
		printf("1\n");
		return 0;
	}
	while(P!=Q){
		if(P>Q){
			if(P%Q==0){
				count+=P/Q;
				break;
			}
			else
			{
			count+=P/Q;
			P%=Q;
			} 
		}
		else {
			if(Q%P==0){
				count+=Q/P;
				break;
			}
			else{
			count+=Q/P;
			Q%=P;
			}
			
		}
	}
	
	printf("%lld\n",count);
	return 0;
}
