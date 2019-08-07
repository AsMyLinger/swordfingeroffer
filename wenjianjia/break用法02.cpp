#include"stdio.h"
main()
{
	int j;
	for(j=0;j<1;j++)          
		if(1)  break;           //该处循环直接跳出，j的值不发生变化 
	printf("%d",j);
} 
