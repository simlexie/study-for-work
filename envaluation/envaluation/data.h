#ifndef  XIESHENGNAN
#define  XIESHENGNAN
#include <queue>
using namespace std;

#define  MaxEdgeNum  7000       //��������
#define  MaxVertexNum 1000
#define  Prob  0.3  //���ֵ
#define R 10
typedef int VertexType;

//���ļ�ʱҪ�õ�������
FILE *fp =NULL;
FILE *fr = NULL;
FILE *fw = NULL;
char buf[105];
char set[100];
char *buf_p = buf;
char *set_p = set;
char *temp_p = buf_p;

//��ͼʱ��Ҫ�õ�����
typedef struct node   //�߱�ڵ�
{
   int adjvex;
   int time;          //�߽�����ʱ��
   node* next;
}EdgeNode;

typedef struct     //�����ڵ�
{
   VertexType vertex;
   EdgeNode* firstedge;
}VertexNode;

typedef VertexNode AdjList[MaxVertexNum];

typedef struct
{
    AdjList adjlist;
    int n,e;  //nΪ���㣬eΪ��
}ALGraph;

ALGraph* G= (ALGraph*)malloc(sizeof(ALGraph));

EdgeNode* s;

//int Gra[MaxVertexNum][MaxVertexNum];
int action_num =0; //�����洢ѵ��action����
int test_action_num = 0; //�����洢����action����
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
int Au[MaxVertexNum];   //��ʾ20������е�ÿ���û���action����
int  Av2u[MaxVertexNum][MaxVertexNum];
int  Avau[MaxVertexNum][MaxVertexNum];
int  Avou[MaxVertexNum][MaxVertexNum];
int Tvu[MaxVertexNum][MaxVertexNum];  
int tvu[MaxVertexNum][MaxVertexNum];   //��ʾ�����������֮�䶯��������ƽ��ʱ��
double ct[6]={0,20,40,60,80,100};     //������ʾCTģ��ʱ�䲽����
queue<int>parents;
float p_joint[MaxVertexNum];                        //ÿ���������ϸ���
float p_single[MaxVertexNum][MaxVertexNum];        //�������֮���Ӱ�����

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
float temp_sum [MaxVertexNum]; //�������ÿ���������ϸ���ʱ�õ��м�ֵ��
float c_sum[MaxVertexNum];
float d_sum[MaxVertexNum];
float s_sum[MaxVertexNum];
queue<int>id;        //��Ϊ��ʱ���У�������Ѽ�����
int id_result[100];     //��Ϊ��result_table�д��ڵĽ��
int id_state[100];         //������ʶresult_table�е�perform
float ACC;               //ģ��׼ȷ�ȵ�����
int TP,FN,FP,TN;
struct test_result     //�����������㷨�д洢result_table
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