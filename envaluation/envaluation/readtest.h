#ifndef  XIESHENGNAN_222
#define  XIESHENGNAN_222
#include "data.h"
void readtest()
{
	int i = 0;
	int num = 0; int bb = 0; int name = 0;
	fr=fopen("E:\\test.txt", "r");
	if(fr==NULL)
	{
		printf("Cann't open%s\n","E:\\test.txt");
	}
     fgets(buf,100,fr);
	 test_action_num = 0;
	 while(buf[i]!='\n')
	 {
		test_action_num = test_action_num * 10 +(buf[i]-48);
		i++;
	 }
	 int k = 0;
	 for(k=0;k<test_action_num;k++)
	 {
		fgets(buf,100,fr);
		i=0,num=0,bb=0;
		name = 0;
		for(i=0;buf[i]!=NULL;i++)
		{
		   while(buf[i]!=' ')
		   {
			  num = num*10 +(buf[i]-'0');
			  TEST[k].node = num;
			  result_temp[k].user = num;
			  testresult[k].test_u=num;
			  i++;
		   }//printf("%d ",TEST[k].node);
			i=i+1;
		   while(buf[i]!=' ')
		   {
			   name = name*10 +(buf[i]-'0');
			   TEST[k].action_id = name;
			   i++;
		   }//printf("%d ",TEST[k].action_id);
			i=i+1;
			while(buf[i]!='\n')
			{
				bb = bb*10 +(buf[i]-'0');
				TEST[k].time = bb;
				testresult[k].test_time = bb;
				i++;
			}//printf("%d\n",TEST[k].time);
	   }
	}
	for(k = 0; k<test_action_num;k++)
	{
		result_temp[k].perform_u = 0;
		result_temp[k].p_user = 0;
		testresult[k].test_perform=0;
		testresult[k].test_p=0;
		//results.push(result_temp[k]);
		//printf("%d %f %d \n",result_temp[k].user,result_temp[k].perform_u,result_temp[k].p_user);
		//printf("%d %f %d %d \n",testresult[k].test_u,testresult[k].test_p,testresult[k].test_perform,testresult[k].test_time);

	}
	//fclose(fr);	
}
#endif