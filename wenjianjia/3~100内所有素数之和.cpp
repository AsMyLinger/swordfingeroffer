#include"stdio.h"
main()
{
	int n,m,sum=0;
	m=3;
	while(m<100)                //ȡ3~100��������������ж� 
	{
		for(n=2;n<=m/2;n++)     //�ж�n�Ƿ�Ϊ���� 
		   if(m%n==0) break;
		if(n>m/2)
		   sum+=m;
		m+=2;
	}
	printf("sum=%ld\n",sum);
}

