#include"stdio.h"
main()
{
	int n,m,sum=0;
	m=3;
	while(m<100)                //取3~100内所有奇数逐个判断 
	{
		for(n=2;n<=m/2;n++)     //判断n是否为素数 
		   if(m%n==0) break;
		if(n>m/2)
		   sum+=m;
		m+=2;
	}
	printf("sum=%ld\n",sum);
}

