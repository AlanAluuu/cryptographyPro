#include <stdio.h>
#include <math.h>
//�ж� p q�Ƿ�Ϊ����
int Prime(int m){    
	int i, k;
	if (m<2) return 0;
	k = sqrt(m);
	for (i = 2; i <= k; i++)
		if (m%i == 0)
			break;
	 //��������1,���򷵻�0
	if (i>k)   
		return 1;                  
	else
		return 0;                    
}
//�ݵ�ȡ��
int encrypt(int a, int b, int c){
	int r = 1;
	b = b + 1;
	while (b != 1){
		r = r*a;
		r = r%c;
		b--;
	}
	return r;
}
//�ж������Ƿ���
int husu(int x, int y){   
	int t;
	while (y){
		t = x;
		x = y;
		y = t%y;
	}
	//x��y����ʱ����0��x��y������ʱ����1  
	if (x == 1) 
		return 0;           
	else  
		return 1;   
}

int main() {
	//p,qΪ������eΪ��Կ��dΪ˽Կ��mΪ���ģ�nΪģ�� ,cΪ���� 
	int p, q, e, d, m, n, t, c, r, k;
	printf("��������������p,q:");
	while (1){
		scanf("%d%d", &p, &q);
		//�ж��������Ƿ�Ϊ���������ǵĻ���������
		if ((Prime(p) == 1) && (Prime(q) == 1)){  
			n = p*q;
			break;
		}
		else printf("ERROR!\n������������������p,q\n");
	}
	//��ŷ������t
	t = (p - 1)*(q - 1);      
	printf("�������������õĹ�Կe��ע�⣺1<e<��(n)����e��(p - 1)*(q - 1)���ʡ�e:");
	scanf("%d", &e);

	while (e<1 || e>t || husu(e, t)){
		printf("ERROR!e������Ҫ������������e:\n");
		scanf("%d", &e);
	}

	d = 1;
	//�ɹ�Կe���˽Կd
	while (((e*d) % t) != 1)   
		d++;     
	printf("�������˽Կd:%d\n",d);
	printf("��������Ҫ���ܵ�����:");
	scanf("%d", &m);
	c = encrypt(m, e, n);
	printf("����Ϊ: %d\n", c);
	printf("����������:");
	scanf("%d", &c);
	m = encrypt(c, d, n);
	printf("����Ϊ: %d", m);
}



