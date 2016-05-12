#include<stdio.h>
#include<time.h>
#include"init.h"
#include"ui.h"
#include "test.h"
int main()
{
	srand((float)time(NULL));
	init();
	init1();
	/*for(int i = 0;i<=MaxVertexNum;i++)
	{
		//for(int j = 0;j<20;j++)
		//{
		    if(user[i]==0)
			printf("%d ",i);
		///}
	}*/
	ui();
	test();
	return 0;
}