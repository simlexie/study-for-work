#include"data.h"
#include"init.h"
#include "random.h"
void ui()
{
	int visited[MaxVertexNum] = {0};//�����ģ������б�����Ĵ���
	int flag[MaxVertexNum] = {0}; //����Ƿ��Ծ�ı�־λ
	double pro[MaxVertexNum] = {0}; //������յĻ�Ծ����
	int i;
	int j = 0;
	//int predict_num = 0;
	EdgeNode *p ;
	int num = 0;
	int q;
	for(i = 0;i<action_num;i++)
	{
		int r = 0;
		if(action_log.empty())
		{
			action_log.push(ACTION[i]);
		}
		//printf("%d \n",ACTION[i].action_id);
		for(int k = i+1;k<action_num;k++)
		{
			if(ACTION[k].action_id == action_log.front().action_id)
			{
				action_log.push(ACTION[k]);
				i++;
			}else break;
		}
		//printf("idid:%d",action_log.front().action_id);
		int id_pra = action_log.front().action_id;
		while(!action_log.empty())
		{
			//printf("%d %d %d\n",action_log.front().node,action_log.front().action_id,action_log.front().time);
			id.push(action_log.front().node);//��Ϊ��ʱ���д���м��Ծ�Ľ��
			flag[action_log.front().node] = 1;
		    id_array[j] = action_log.front().node;
			j++;

			action_log.pop();
	
		}
		//getchar();
	    memset(visited,0,sizeof(visited));
		while(r < R)
		{
			//printf("\nhello\n");
			while(!id.empty())
			//while(!id.empty())
			{
				//for(i = 0 ; i < G->n; i++)
				//{
					
						q = id.front();
						p = G -> adjlist[q].firstedge;
						while(p != NULL)
						{
							q = p->adjvex;
							if(flag[q] == 0)
							{								
								float rannum = 0.01*random();
								if(rannum < Prob)
								{
									flag[q] = 1;
									visited[q] ++;
								//	printf("%d ",q);
							    	id.push(q);
								   // printf("singleӰ�췶Χ:%f\n",spread);
								}
							}
							p=p->next;
						}	 
					
				//}//fori = 0 i< i++
				id.pop();
			}//whileid!empty
			//ÿ��ģ��֮���ٽ�idtemp�еĽ���Ϊ��ʼ���
			memset(flag,0,sizeof(flag));
			/*for(i = 0 ;i < MaxVertexNum;i++)
			{
				printf("%d ",flag[i]);
			}*/
			//getchar();
			for(i = 0 ;i < j ; i++)
			{
				id.push(id_array[i]);
			}
			r++;
	}//r
		memset(predict_num,0,sizeof(predict_num));
		for(int mm = 0;mm < MaxVertexNum; mm++)
		{
			if(visited[mm] > 0)
			{ 
				++ predict_num[id_pra];
				pro[mm] = (float) visited[mm]/R;
				
				USERPRO[mm].aid =  id_pra;
				USERPRO[mm].userid = mm;
				USERPRO[mm].userpro = pro[mm];
				//++ USERPRO[mm].anum;
			//	acti_user.push(mm);
				//printf("%d ",acti_user[mm]);
				
				//printf("%d %d %f %d\n",USERPRO[mm].aid,USERPRO[mm].userid,USERPRO[mm].userpro,USERPRO[mm].anum);
			//	printf("%d %d %f\n",USERPRO[mm].aid,USERPRO[mm].userid,USERPRO[mm].userpro);

			}
			
		}
		//printf("%d\n", predict_num[id_pra]);//���ÿ��ģ�������һ�����Լ���Ľڵ���Ŀ
		//printf("id:%d \n",id_pra);
		//test();
	}
}
