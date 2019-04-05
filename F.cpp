#include <stdio.h>
int month[12] ={31,28,31,30,31,30,31,31,30,31,30,31}; 
long long ans[100]; 
int run_nian(int year){
	return ((year%400==0 || (year%4==0 && year%100!=0))?1:0);
}
long long func(){
	int a,b,y,m,d;
	scanf("%d",&y);
	scanf("%d",&m);
	scanf("%d",&d);
	scanf("%d",&a);
	scanf("%d",&b);
	long long day1 = 0,day2 = 0;
	for(int cnt=1;cnt<m;cnt++){
		if(cnt!=2) day1+=month[cnt-1];
		else day1+=month[cnt-1]+run_nian(y);
	}
	day1+=d;
	if(a<m ||(a==m&&b<d)){
		for(int cnt = 1;cnt<a;cnt++){
			if(cnt!=2) day2+=month[cnt-1];
			else day2+=month[cnt-1]+run_nian(y+1);
		}
		day2+=b;
		return (day2+365+run_nian(y)-day1);
	}
	else{
		for(int cnt=1;cnt<a;cnt++){
			if(cnt!=2) day2+=month[cnt-1];
			else day2+=month[cnt-1]+run_nian(y);
		}
		day2+=b;
		return (day2-day1);
	}
}
int main()
{
	int T=0;
	scanf("%d",&T);
	for(int cnt=0;cnt<T;cnt++){
		ans[cnt]=func();
	}
	for(int cnt = 0;cnt<T;cnt++){
		printf("%lld\n",ans[cnt]);
	}
	return 0;
}
