#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
int main()
{
	int bit=7;
	bool temp[12] = { 0, };
	bool a[12] = { 0, };
	bool syndrome[4] = { 0,};
	int e=0;
	int cal = 0;
	printf("������ ��Ʈ���� �����ּ��� :");
	//scanf("%d\n", &bit);
	printf("%d\n",bit);
	srand(time(NULL));
	/*for (int i = 1; i <= bit; i++)
	{
		scanf("%1d", &temp[i]);
	}*/
	memset(temp,1,11);
	a[1] = temp[1];
	a[2] = temp[2];
	a[3] = temp[3];
	a[5] = temp[4];
	a[6] = temp[5];
	a[7] = temp[6];
	a[9] = temp[7];
	printf("������ ��Ʈ\n");
	for (int i = 1; i <= bit + 4; i++)
	{
		
		printf("%d ", a[i]);
	}
	printf("\n");
	a[4] = a[1]^a[2]^a[3]^ a[4];
	a[8] = a[5]^a[6]^a[7]^ a[8];
	a[10] = a[10]^a[9]^a[6]^a[5]^a[2]^a[1];
	a[11] = a[11]^a[9]^a[7]^a[6]^a[3]^a[1];
	printf("������ ��Ʈ + �и�Ƽ��Ʈ ���\n");
	for (int i = 1; i <= bit + 4; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
		e = rand()%11;
		scanf("%d",&e);
		printf("������ ���� �ڸ����� %d �Դϴ�.\n", e);

		printf("%d\n", ~e);
		if (e > 0)
		{
			e = ~e + 13;
		}
		else
		{
			printf("������ �����ϴ�.\n");
			return 0;
		}
			printf("%d\n", e);
			//e = 0;
		if (a[e] == 1)
			a[e] = 0;
		else
			a[e] = 1;
		
		syndrome[0] = a[1] ^ a[3] ^ a[5] ^ a[7] ^ a[9] ^ a[11];
		syndrome[1] = a[1] ^ a[2] ^ a[5] ^ a[6] ^ a[9] ^ a[10];
		syndrome[2] = a[5] ^ a[6] ^ a[7] ^ a[8];
		syndrome[3] = a[1] ^ a[2] ^ a[3] ^ a[4];
		
			for (int i = 3; i >= 0; i--)
			{
				printf("%d ", syndrome[i]);
				cal += (int)pow(2,i)*syndrome[i];
			}
			printf("\n");
			if (a[cal] == 1)
				a[cal] = 0;
			else
				a[cal] = 1;
			printf("%d",cal);

		
		return 0;
}
