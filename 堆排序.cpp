#include <stdio.h>
#define N 1000
#define INF 999999999
int shuchu=1;
int h[N];

//������(������)
//n����ģ i�������ӶѵĶѶ�
void heapAdjust(int n, int par)
{
	int tmp, pos, lc, rc;

	while (par <= n/2) {
		tmp = h[par]; //��¼��ĸ����ֵ
		lc = par<<1;
		rc = lc+1;
		pos = par;
		//��ĸ����������2��
		if (h[par] < h[lc]) {
			h[par] = h[lc];
			pos = lc;
		}
		if (rc <= n && h[par] < h[rc]) {
			h[par] = h[rc];
			pos = rc;
		}
		if (pos == par) //�޸��¼��������
			break;
		else
			h[pos] = tmp;
		par = pos; //�������λ�õĽ���ǡ���ĸ��㡱
	}
}

//������
//��ģΪn�Ķѣ����丸ĸ��㣬�Ե�������������ص�����
void createHeap(int n)
{
	int i;

	for (i = n/2; i != 0; i--) {
		heapAdjust(n, i);
	}
}

void heapSort(int n)
{
	int ntimes = n;
	for(int i=1;i<=ntimes;i++)
		printf("%d ",h[i]);
	printf("\n");
	while (ntimes--) {
//		printf("%d\n", h[1]);
		h[1] = h[n];
		h[n--] = 0; //������
		heapAdjust(n, 1);
		if(shuchu<3)
		{
			for(int i=1;i<=ntimes;i++)
			printf("%d ",h[i]);
			printf("\n");
			shuchu++;
		}

	}
}

int main(void)
{	
	int n, i;
	
	scanf("%d", &n);
	h[0] = INF;
	for (i = 1; i != n+1; i++) {
		scanf("%d", &h[i]);
	}
	createHeap(n);
	heapSort(n);
	return 0;
}

/*
  �ο���������
6
342 31 52 626 12 124
10
43 525 14 21 52 3 52 45 319 15155
*/

