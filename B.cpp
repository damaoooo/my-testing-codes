#include <stdio.h>
#include <string.h>
int check[1000000];
int prime[1000000];
int qianzhui[1000000];
int res_check[1000000][2];
int index=0;
int tot;
int pickPrime(int m,int n){
	tot=0;
	memset(check, 0, sizeof(check));
	memset(prime, 0, sizeof(prime));
	check[1]=1;
	check[0]=1;
	for (int i=2;i<=m;i++){
		if (!check[i]) prime[tot++]=i;
		for (int j=0;j<tot;j++){
	    	if (i*prime[j]>m) break;
	    	check[i*prime[j]]=1;
	    	if (i%prime[j]==0) break;
	  	}
	}
	int temp=1;
	qianzhui[0]=0;
	while(temp<=m){
		qianzhui[temp]=qianzhui[temp-1]+!check[temp];
		temp++;
	}
}
int isPrime(int n){
	if(check[n]==1) return 0;
	return 1;
}
int isTrangle(int a,int b,int c){
	if(a+b<=c || a+c<=b||b+c<=a) return 0;
	return 1;
}
int isExsit(int a,int b){
	for(int cnt=0;cnt<index;cnt++){
		if(res_check[cnt][0]==b&&res_check[cnt][1]==a) return 1;
	}
	return 0;
}
int main(){
	int m,n;
	int count=0;
	scanf("%d%d",&n,&m);
	pickPrime(m,n);
	int prime_cnt=0;
	if(isPrime(n)) prime_cnt++;
	if(prime_cnt==1){
		for(int i=1;i<=m;i++){
			int he = n+i>m?m:n+i;
			int cha = i;
			count+=qianzhui[he]-qianzhui[cha];
		}
	}
	else{
		for(int i=0;i<tot;i++){
			for(int j=0;j<tot;j++){
				if(isTrangle(n,prime[i],prime[j])){
					count++;
				}
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
