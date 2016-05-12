#ifndef  XIESHENGNAN
#define  XIESHENGNAN
#include <queue>
using namespace std;

#define  MaxEdgeNum  7000       //边数上限
#define  MaxVertexNum 1000
#define  Prob  0.3  //活动阈值
#define R 10
typedef int VertexType;

//读文件时要用到的数据
FILE *fp =NULL;
FILE *fr = NULL;
FILE *fw = NULL;
char buf[105];
char set[100];
char *buf_p = buf;
char *set_p = set;
char *temp_p = buf_p;

//存图时需要用的数据
typedef struct node   //边表节点
{
   int adjvex;
   int time;          //边建立的时间
   node* next;
}EdgeNode;

typedef struct     //顶点表节点
{
   VertexType vertex;
   EdgeNode* firstedge;
}VertexNode;

typedef VertexNode AdjList[MaxVertexNum];

typedef struct
{
    AdjList adjlist;
    int n,e;  //n为顶点，e为边
}ALGraph;

ALGraph* G= (ALGraph*)malloc(sizeof(ALGraph));

EdgeNode* s;

//int Gra[MaxVertexNum][MaxVertexNum];
int action_num =0; //用来存储训练action个数
int test_action_num = 0; //用来存储测试action个数
struct graph
{
	int start;
	int end;
	//int timestamp;
}Graph[MaxEdgeNum];
//int graph[MaxVertexNum][MaxVertexNum];
struct action
{
	int node;
	int action_id;
	int time;
}ACTION[MaxVertexNum];
struct action TEST[MaxVertexNum];
queue<action>action_log;
queue<action>action_temp;
queue<action>current_table;
queue<action>temp;
//struct action current_table[MaxVertexNum];
int Au[MaxVertexNum];   //表示20个结点中的每个用户的action个数
int  Av2u[MaxVertexNum][MaxVertexNum];
int  Avau[MaxVertexNum][MaxVertexNum];
int  Avou[MaxVertexNum][MaxVertexNum];
int Tvu[MaxVertexNum][MaxVertexNum];  
int tvu[MaxVertexNum][MaxVertexNum];   //表示的是两个结点之间动作传播的平均时延
double ct[6]={0,20,40,60,80,100};     //用来表示CT模型时间步增长
queue<int>parents;
float p_joint[MaxVertexNum];                        //每个结点的联合概率
float p_single[MaxVertexNum][MaxVertexNum];        //单个结点之间的影响概率

//int parents[MaxVertexNum];
struct result             
{
	int user;
	float p_user;
	int perform_u;
};
queue<result>result_table;
queue<result>results;
struct result result_temp[MaxVertexNum];
struct result id_temp[MaxVertexNum];
float temp_sum [MaxVertexNum]; //用在求解每个结点的联合概率时用的中间值。
float c_sum[MaxVertexNum];
float d_sum[MaxVertexNum];
float s_sum[MaxVertexNum];
queue<int>id;        //作为临时队列，来存放已激活结点
int id_result[100];     //作为在result_table中存在的结点
int id_state[100];         //用来标识result_table中的perform
float ACC;               //模型准确度的评估
int TP,FN,FP,TN;
struct test_result     //用来在评估算法中存储result_table
{
	int test_u;
	float test_p;
	int test_perform;
	int test_time;
};
queue<test_result>test_result_table;
queue<test_result>test_temp;
struct test_result testresult[MaxVertexNum];
queue<int>sorted_parents;

int id_array[MaxVertexNum];

struct user_pro_aid
{
	int userid;
	int aid;
	float userpro;
	//int anum;
}USERPRO[MaxVertexNum];

//queue<int>acti_user;
//int hash_table[MaxVertexNum];
int actual_user[MaxVertexNum] = {0};
int predict_num[MaxVertexNum] = {0};
#endif