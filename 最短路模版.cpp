#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define INFINITY 65535//�ޱ�ʱ��Ȩֵ
#define MAX_VERTEX_NUM 10//��󶥵���

typedef struct MGraph{
	string vexs[10];//������Ϣ
	int arcs[10][10];//�ڽӾ���
	int vexnum, arcnum;//�������ͱ���
}MGraph;

int LocateVex(MGraph G, string u)//���ض���u��ͼ�е�λ��
{
	for(int i=0; i<G.vexnum; i++)
		if(G.vexs[i]==u)
			return i;
	return -1;
}

void CreateDN(MGraph &G)//����������
{
	string v1, v2;
	int w;
	int i, j, k;
	cout<<"�����붥�����ͱ�����";
	cin>>G.vexnum>>G.arcnum;

	cout<<"�����붥�㣺";
	for(i=0; i<G.vexnum; i++)
		cin>>G.vexs[i];

	for(i=0; i<G.vexnum; i++)
		for(j=0; j<G.vexnum; j++)
			G.arcs[i][j]=INFINITY;

	cout<<"������ߺ�Ȩֵ��"<<endl;
	for(k=0; k<G.arcnum; k++)
	{
		cin>>v1>>v2>>w;
		i=LocateVex(G, v1);
		j=LocateVex(G, v2);
		G.arcs[i][j]=w;
	}
}

//�Ͻ�˹�����㷨��������G��v0���㵽���ඥ��v�����·��p[v]����Ȩ����D[v]
//p[][]=-1��ʾû��·����p[v][i]����Ǵ�v0��v��ǰ��õ����·�������ĵ�i+1������(���Ǵ�ӡ���·���Ĺؼ�)����v0��v�����·����Ϊp[v][0]��p[v][j]ֱ��p[v][j]=-1,·����ӡ��ϡ�
//final[v]Ϊtrue���ҽ���v��S,���Ѿ���ô�v0��v�����·����
void ShortestPath_DIJ(MGraph G, int v0, int p[][MAX_VERTEX_NUM], int D[])
{
	int v, w, i, j, min;
	bool final[10];
	
	for(v=0; v<G.vexnum; v++)
	{
		final[v]=false;//���ֵ
		D[v]=G.arcs[v0][v];//D[]���v0��v����̾��룬��ֵΪv0��v��ֱ�Ӿ���
		for(w=0; w<G.vexnum; w++)
			p[v][w]=-1;//��p[][]��ֵΪ-1����û��·��
		if(D[v]<INFINITY)//v0��v��ֱ��·��
		{
			p[v][0]=v0;//v0��v���·�������ĵ�һ������
			p[v][1]=v;//v0��v���·�������ĵڶ�������
		}
	}
	
	D[v0]=0;//v0��v0����Ϊ0
	final[v0]=true;//v0���㲢��S��
	
	for(i=1; i<G.vexnum; i++)//����G.vexnum-1������
	{//��ʼ��ѭ����ÿ�����v0��ĳ������v�����·��������v����S����Ȼ�����p��D
		min=INFINITY;
		for(w=0; w<G.vexnum; w++)//�����ж�����
			if(!final[w] && D[w]<min)//��S��֮��(��final[]=false)�Ķ���������v0����Ķ��㣬���丳��v,���븳��min
			{
				v=w;
				min=D[w];
			}
			final[v]=true;//v����S��
			for(w=0; w<G.vexnum; w++)//�����²���Ķ��㣬���²���S���Ķ��㵽v0�ľ����·������
			{
				if(!final[w] && min<INFINITY && G.arcs[v][w]<INFINITY && (min+G.arcs[v][w]<D[w]))
				{//w������S����v0->v->w�ľ���<Ŀǰv0->w�ľ���
					D[w]=min+G.arcs[v][w];//����D[w]
					for(j=0; j<G.vexnum; j++)//�޸�p[w]��v0��w�����Ķ������v0��v���������ж����ټ��϶���w
					{
						p[w][j]=p[v][j];
						if(p[w][j]==-1)//��p[w][]��һ������-1�ĵط����϶���w
						{
							p[w][j]=w;
							break;
						}
					}					
					
				}
			}
	}	
}

void main()
{
	int i, j;
	MGraph g;
	CreateDN(g);
	int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//���·������p
	int D[MAX_VERTEX_NUM];//��̾�������D
	ShortestPath_DIJ(g, 0, p, D);
	
	cout<<"���·������p[i][j]���£�"<<endl;
	for(i=0; i<g.vexnum; i++)
	{
		for(j=0; j<g.vexnum; j++)
			cout<<setw(3)<<p[i][j]<<" ";
		cout<<endl;
	}

	cout<<g.vexs[0]<<"������������·��������Ϊ��"<<endl;
	for(i=0; i<g.vexnum; i++)
	{
		if(i!=0 && D[i]!=INFINITY)
		{
			cout<<g.vexs[0]<<"-"<<g.vexs[i]<<"�����·������Ϊ:"<<D[i];
			cout<<"  ���·��Ϊ��";
			for(j=0; j<g.vexnum; j++)
			{
				if(p[i][j]>-1)
					cout<<g.vexs[p[i][j]]<<" ";
			}
			cout<<endl;			
		}
		else if(D[i]==INFINITY)
			cout<<g.vexs[0]<<"-"<<g.vexs[i]<<":"<<"���ɴ�"<<endl;
	}

}


