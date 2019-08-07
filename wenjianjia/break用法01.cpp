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
	    		k++;                      //该处语句当j==3时停止执行 
			} 
		h++;                             //该处的语句仍然执行 
	}
	printf("i=%d j=%d k=%d h=%d\n",i,j,k,h);
}
