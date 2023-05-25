#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//����a��ģm�µĳ˷���Ԫ��
//ͨ������1��m-1���������ҵ�����(i * a) % m = 1����i��������i��
//����������򷵻�0�� 
int getinverse(int a,int m){
	int i; 
    for(i=1;i<m;i++){
        if( (i*a) % m == 1)
            return i;
    }
}
//��a��b�����Լ����
//ʹ��շת�������ŷ������㷨������a��b�����Լ����ֱ��bΪ0������a��ֵ��
int gcd(int a,int b){
    while(b!=0){
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
//�ж�a��b�Ƿ���
//ԭ������gcd��������a��b�����Լ��
//������Լ��Ϊ1���򷵻�1�����򷵻�0��
int ifisPrime(int a,int b){
    if(gcd(a,b)==1)
        return 1;
    else 
        return 0;
}

//�����Ľ��м��ܡ����ȴ��ļ�"plaintext.txt"�ж�ȡ���ģ�
//Ȼ���ÿ����ĸ���м��ܲ������������д���ļ�"ciphertext.txt"�С�
void encrypt(int a,int b){
    int m = 26,i=0,len=0;
    char c[10000] = {0},ch;
    FILE *fp1,*fp2;
    fp1 = fopen("p.txt","r");
    fp2 = fopen("c.txt","w");
    if(fp1==NULL){
        printf("open file error!\n");
        exit;
    }
    while(fscanf(fp1,"%c",&ch)!=EOF){
        c[i] = ch;
        i++;
    }
    len = strlen(c);
    for(i=0;i<len;i++){
    	if(islower(c[i]))
            c[i] = 'a' + ( (a * (c[i] - 'a') + b) % 26);
        if(isupper(c[i]))
            c[i] = 'A' + ( (a * (c[i] - 'A') + b) % 26);
    }
    fputs(c,fp2);
    
    fclose(fp1);
    fclose(fp2);
    printf("��������Ϊ��%s\n",c);
	printf("���ܷ��ɹ����м��ܣ�\n");
}

//�����Ľ��н��ܡ����ȴ��ļ�"ciphertext.txt"�ж�ȡ���ģ�
//Ȼ���ÿ����ĸ���н��ܲ�����
//�������д���ļ�"devrypted_plaintext.txt"��
void decrypt(int a,int b){
    FILE *fp1,*fp2;
    fp1 = fopen("c.txt","r");
    fp2 = fopen("d.txt","w");
    if(fp1==NULL){
        printf("open file error!\n");
        exit;
    }
    char c[10000] = {0},ch;
    int i=0,len=0,inva = getinverse(a,26);
    while(fscanf(fp1,"%c",&ch)!=EOF){
        c[i] = ch;
        i++;
    }
    len = strlen(c);
    for(i=0;i<len;i++){
        if(islower(c[i])){
            if((c[i] - 'a') < b)
                c[i] = ( inva * (c[i] - 'a' - b + 26) % 26) + 'a'; 
            else
                c[i] = ( inva * (c[i] - 'a' - b)  % 26) + 'a'; 
        }
        if(isupper(c[i])){
            if((c[i] - 'A') < b)
                c[i] = ( inva * (c[i] - 'A' - b + 26) % 26) + 'A'; 
            else
                c[i] = ( inva * (c[i] - 'A' - b)  % 26) + 'A'; 
        }
    }
    fputs(c,fp2);
    fclose(fp1);
    fclose(fp2); 
    printf("������������Ϊ��%s\n",c);
	printf("���ܷ��ɹ����н��ܣ�\n");
}
int main(){
    int a,b,m;
    do{
		printf("����������1\n����������2\n�˳�������0\n");
    	scanf("%d",&m);
    	if(m==0)
    		break;
    	else if(m!=0&&m!=1&&m!=2)
    		printf("�����������������룡\n");
    	else{
		    printf("��������Կa��b������a��26����\n");
		    scanf("%d %d",&a,&b);
		    if(!(ifisPrime(a,26))){
		        while(!(ifisPrime(a,26))){
		            printf("����⣬����aֵ��26�����㻥����������������26���ص�a!\n");
		            scanf("%d",&a);
		        }
		    }
		    if(m==1)
		        encrypt(a,b);
		    else if(m==2)
		        decrypt(a,b);
		}
	}while(m!=3); 
    return 0;
}

