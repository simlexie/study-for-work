//预测用户活跃，并且在测试集中活跃，则为TP；
//预测用户活跃，但在测试集中不活跃，则为FP;
//预测用户未活跃，在测试集中活跃，为FN；
//预测用户未活跃，在测试集中也未活跃，为TN

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
			if(actual_user[ac] == USERPRO[pr].userid) //预测活跃，实际也活跃
			{
				ac++;pr++;
				TP++;
			}
			if(actual_user[ac] > USERPRO[pr].userid) //预测没活跃，实际活跃
			{
				pr++;
				FN++;
			}
			if(actual_user[ac] < USERPRO[pr].userid)//预测活跃，实际没活跃
			{
				ac++;
				FP++;
			}
			//TN预测未活跃，实际未活跃
			if(pr == predict_num[test_id])//如果预测结点扫描结束，那么剩下的真实活跃结点都为，FN
			{
				FN += (actual_num - ac);
			}
			if(ac == actual_num) //如果实际结点扫描完毕，那么剩下的预测活跃结点都为，FP
			{
				FP += (predict_num[test_id] - pr);
			}

		}
		

	}
}