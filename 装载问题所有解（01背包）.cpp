#include<stdio.h>
int maxvalue;//���ֵ 
int w[1000]={0};
int v[1000]={0};
int c;//��������
int count=1;
int num,N;
int y[1000];//������,y[i]=1��ʾѡȡ��Ʒ��y[i]=0��ʾ��ѡȡ��Ʒ

int find(int n,int contain)
{
    if(n==0 || contain==0){//����Ʒ����Ϊ0�����߱�������Ϊ0ʱ�����Ž�Ϊ0
        return 0;
    }
    else
    {
        //�ӵ�ǰ��ʣ��Ʒ�����һ����Ʒ��ʼ��ǰ������ж��Ƿ�Ҫ��ӵ�������
        for(int i=n-1;i>=0;i--){
            //�����ǰҪ�жϵ���Ʒ�������ڱ�����ǰ��ʣ����������ô�Ͳ�ѡ�������
            //��������������Ž�Ϊf(n-1,C)
            if(w[i]>contain){
                y[i]=0;
                return find(n-1,contain);
            }
            else
            {
                //�����ǰ���жϵ���Ʒ����wi<C,��ô��ѡȡf(n-1,C)��vi+f(n-1,C-wi)�е����ֵ
                int tmp1=find(n-1,contain);//��ѡ����Ʒi������µ����Ž�
                int tmp2=v[i]+find(n-1,contain-w[i]);//ѡ����Ʒi������µ����Ž�
                //����ѡ����Ʒi�Ͳ�ѡ����Ʒi�����Ž���һ��
                if(tmp1>tmp2){
                    y[i]=0;//��������±�ʾ��Ʒiδ��ѡȡ
                    return tmp1;
                }
                else
                {
                    y[i]=1;//��Ʒi��ѡȡ
                    return tmp2;
                }
            }
        }
    }
}

int findroute(int n,int contain,int z[])
{
	int i=n;
	if(n<=N&&contain>=0)
    {
            if(w[i]>contain||v[i]==0)
			{
                z[i]=0;
                findroute(i+1,contain,z);
            }
            else
            {
				int tmp1=0; 
                z[i]=1;
                for(int tmp=0;tmp<=N;tmp++)
					if(z[tmp]==1)
						tmp1+=v[tmp];

				if(tmp1==maxvalue)
				{
					printf("case %d:\n",count++);
					for(int j=0;j<=N;j++)
						if(z[j]==1)
							printf("%d\n",j+1);
				}
                findroute(i+1,contain-w[i],z);
            	z[i]=0;
                findroute(i+1,contain,z);
            }			
    }
}

int main()
{
	int t;int m[1000]={0};
	scanf("%d",&num);
	N=num;
	for(t=0;t<num;t++)
		scanf("%d,%d",&w[t],&v[t]);
	scanf("%d",&c);
    maxvalue=find(num,c);
    findroute(0,c,m);
    return 0;
    
}
