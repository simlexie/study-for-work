//Ԥ���û���Ծ�������ڲ��Լ��л�Ծ����ΪTP��
//Ԥ���û���Ծ�����ڲ��Լ��в���Ծ����ΪFP;
//Ԥ���û�δ��Ծ���ڲ��Լ��л�Ծ��ΪFN��
//Ԥ���û�δ��Ծ���ڲ��Լ���Ҳδ��Ծ��ΪTN

#include "data.h"
#include "init.h"
#include "readtest.h"
void test()
{
	//printf("tst");
	EdgeNode *p= NULL;
	readtest();
	int nnode = 0;
	int j = 0,m = 0 ,r = 0;
	
	int test_id = 0;
//	memset(hash_table,0,sizeof(hash_table));

	for(int i=0;i<test_action_num;i++)
	{
		while(!result_table.empty())
		{
			result_table.pop();
		}

		if(action_log.empty())
		{
			action_log.push(TEST[i]);
		}
		test_id = action_log.front().action_id;
		printf("id:%d ",test_id);
		int actual_num = 0;
		for(int k = i+1;k<test_action_num;k++)
		{
			if(TEST[k].action_id == action_log.front().action_id)
			{
				action_log.push(TEST[k]);
				i++;
			}
			else break;
		}
		int ac = 0;
		while(!action_log.empty())
		{
			++ actual_num;
			actual_user[ac] = action_log.front().node;
			action_log.pop();		
		}
		printf("num:%d\n",actual_num);
		ac = 0;
		int pr = 0;
		if(test_id == USERPRO[pr].aid)//????????
		{
			//printf("same");
			if(actual_user[ac] == USERPRO[pr].userid) //Ԥ���Ծ��ʵ��Ҳ��Ծ
			{
				ac++;pr++;
				TP++;
			}
			if(actual_user[ac] > USERPRO[pr].userid) //Ԥ��û��Ծ��ʵ�ʻ�Ծ
			{
				pr++;
				FN++;
			}
			if(actual_user[ac] < USERPRO[pr].userid)//Ԥ���Ծ��ʵ��û��Ծ
			{
				ac++;
				FP++;
			}
			//TNԤ��δ��Ծ��ʵ��δ��Ծ
			if(pr == predict_num[test_id])//���Ԥ����ɨ���������ôʣ�µ���ʵ��Ծ��㶼Ϊ��FN
			{
				FN += (actual_num - ac);
			}
			if(ac == actual_num) //���ʵ�ʽ��ɨ����ϣ���ôʣ�µ�Ԥ���Ծ��㶼Ϊ��FP
			{
				FP += (predict_num[test_id] - pr);
			}

		}
		

	}
}