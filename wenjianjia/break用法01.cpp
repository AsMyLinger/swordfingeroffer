#include"stdio.h"
main()
{
	int i,j,k,h;
	k=h=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
	    	{
				if(j==3)  break;
	    		k++;                      //�ô���䵱j==3ʱִֹͣ�� 
			} 
		h++;                             //�ô��������Ȼִ�� 
	}
	printf("i=%d j=%d k=%d h=%d\n",i,j,k,h);
}
