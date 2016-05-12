#ifndef  XIESHENGNAN_111
#define  XIESHENGNAN_111
#include "data.h"
#include <string.h>
#include "time.h"
void init()  //读入图
{
	// clock_t start, finish; 
	// start = clock();
	 int i=0,j;
     int u = 0; //顶点
     int v = 0;
	 int t = 0;
     
	 int ii = 0;
	 int jj = 0;
	 

	 ACC = 0;
	 TP = 0;FN =0 ;FP = 0;TN = 0;
	 fp = fopen("E:\\finaltest.txt", "r");
     if(fp == NULL)
     {
        printf("Cann't open%s\n","E:\\finaltest.txt");
     }
     fgets(buf,100,fp); 
     G->n=0;
     G->e=0;
	 while(buf[i]!=' ')
	 {
		G->n = G->n * 10 +(buf[i]-48);
		i++;
	 }//printf("%d ",G->n);
	 i=i+1;
	 while(buf[i]!='\n')
	 {
		G->e = G->e * 10 +(buf[i]-48);
		i++;
	 }//printf("%d \n",G->e);
	 for(j = 0;j<G->n;j++)       //建立顶点表
	 {
	     G->adjlist[j].vertex=j;
         G->adjlist[j].firstedge=NULL;
	 }
	int k;						//建立边表
    for (k=0;k<G->e;k++)
    {
       i=0,u=0;v=0;
       fgets(buf,100,fp);
       for(i=0;buf[i]!=NULL;i++)
       {
           while(buf[i]!=' ')
           {
              u = u*10 +(buf[i]-'0');
              i++;
           }//printf("%d ",u);
            i=i+1;
            while(buf[i]!='\n')
            {
                v=v*10+(buf[i]-'0');
                i++;
            }//printf("%d \n",v);
        }  
           s=(EdgeNode*)malloc(sizeof(EdgeNode));
           s->adjvex=v;
           s->next=G->adjlist[u].firstedge;  //插入表头
           G->adjlist[u].firstedge=s;
           s=(EdgeNode*)malloc(sizeof(EdgeNode));
           s->adjvex=u;
           s->next=G->adjlist[v].firstedge;
           G->adjlist[v].firstedge=s;
    } 
	//finish = clock();
	//printf("%f seconds",finish-start);
}

void init1()//读入动作日志
{
	FILE* ff = fopen("E:\\actiontest.txt","r");
	if(ff == NULL)
    {
       printf("Cann't open%s\n","E:\\c.txt");
    }
	int i = 0;
	int num=0,bb=0;
	int name = 0;
    fgets(buf,100,ff);
    while(buf[i]!='\n')
	{
		action_num = action_num * 10 +(buf[i]-48);
		i++;
	}//printf("%d \n",action_num);
	
	int k = 0;
	for(k=0;k<action_num;k++)
	{
		fgets(buf,100,ff);
		i=0,num=0,bb=0;
		//memset(name,0,sizeof(name));
		name = 0;
		for(i=0;buf[i]!=NULL;i++)
		{
		   while(buf[i]!=' ')
		   {
			  num = num*10 +(buf[i]-'0');
			  ACTION[k].node = num;
			  //user[num] = 1;
			  i++;
		   }//printf("%d ",num);
			i=i+1;
		   while(buf[i]!=' ')
		   {
			   name = name*10 +(buf[i]-'0');
			   ACTION[k].action_id = name;
			 //  strcpy(name,buf[i]);

			   i++;
		   }//printf("%d ",name);
			i=i+1;
			while(buf[i]!='\n')
			{
				bb = bb*10 +(buf[i]-'0');
				ACTION[k].time = bb;
				i++;
			}//printf("%d\n",bb);
			//action_log.push(ACTION[i-1]);
	   }
	}

	//fclose(ff);
}
void show_Graph(ALGraph* g)
{
   EdgeNode *p;
   
   for (int i=0;i< g->n;i++)
   {
	   p = g->adjlist[i].firstedge;
       printf("%d->",i);
       while(p!=NULL)
       {
            printf("%d->",p->adjvex);
            p=p->next;

       }
       printf("\n");
   }
}


#endif