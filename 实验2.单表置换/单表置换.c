#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void encrypt(char *k){
    FILE *fp1 = fopen("p.txt","r");
    FILE *fp2 = fopen("c.txt","w");
    if(fp1==NULL)
    {
        printf("error!\n");
        exit;
    }
    int i=0,len=0;
    char a[10000],ch;
    while(fscanf(fp1,"%c",&ch)!=EOF){
        if(ch>='a'&&ch<='z')
            a[i] = toupper(ch);
        else
            a[i] = ch;
        i++;
        len++;
    }
    for(i=0;i<len;i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
            a[i] = k[a[i] -'A'];
    }
    // printf("%s\n",a);
    fputs(a,fp2);
    fclose(fp1);
    fclose(fp2);
}
void decrypt(char *k)
{
    FILE *fp1 = fopen("c.txt","r");
    FILE *fp2 = fopen("d.txt","w");
    if(fp1==NULL)
    {
        printf("error!\n");
        exit;
    }
    char b[10000]={0},ch;
    int i = 0,len = 0, j = 0;
    while(fscanf(fp1,"%c",&ch)!=EOF)
    {
        b[i] = ch;
        i++;
        len++;
    }
    for(i=0;i<len;i++)
    {
        if(b[i]>='A'&&b[i]<='Z')
        {
            for(j=0;j<26;j++)
            {
                if(k[j]==b[i])
                    b[i] = 'a' + j;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        b[i] = b[i] - 32;
    }
    fputs(b,fp2);
    fclose(fp1);
    fclose(fp2);
}
int main(){
    FILE *fp1,*fp2;
    int m;
    do{
	    printf("����������1\n����������2\n�˳�������0\n");
	    scanf("%d",&m);
	    if(m==0)
			break;
		else if(m!=0&&m!=1&&m!=2)
			printf("�����ʽ�������������룡\n");
		else
		{
			char k[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
	    	*c,*s;
	    	c = (char*)malloc(sizeof(char));
	    	s = (char*)malloc(sizeof(char));
			getchar();
		    printf("��������Կ��\n");    
		    scanf("%[^\n]",c);
		    int len = strlen(c);
		    int i,j;
		    for(i=0,j=0;i<len;i++,j++){
		        if(isupper(c[i]))
		            s[j] = c[i];
		        else if(islower(c[i]))
		            s[j] = toupper(c[i]);
		        else
		            j--;
		    }
		    len = strlen(s);
		    int flag = 0;
		    int min = 26;
		    for(i=0;i<len;i++){
		        int temp = 1;
		        for(j=0;j<flag;j++){
		            if(s[i]==k[j]){
		                temp = 0;
		                break;
		            }
		        }
		        if(temp){
		            if(s[i]!=k[flag]){ 
		                int n = (s[i]-'A'>min)?s[i]-'A':flag+s[i]-'A';
		                for(n;n>flag;n--){
		                    k[n] = k[n-1];
		                }
		                k[flag] = s[i];       
		            }
		            flag++;
		            if(s[i]-'A'<min)
		                min = s[i]-'A';
		        }
		    }
		
		    if(m==1)
		    {
		        encrypt(k);
		        printf("���ܷ��ɹ����м��ܣ�\n"); 
		    }
		    else if(m==2)
		    {
		        decrypt(k);
		        printf("���ܷ��ɹ����н��ܣ�\n");
		    }
		}
	    
	}while(m!=0);
   
    return 0;
}

