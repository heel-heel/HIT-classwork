#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

typedef struct S
{
 int id;
 char str[100];
 float s1;
 float s2;
 float s3;
 int s4;
}Peo;
int main(int _argc, char* _argv[])
{
 FILE* fp = fopen(_argv[2],"r+");
 if(fp==NULL)
 {
	 printf("Can't open file\n");
	 exit(0);
 }
 FILE* pf = fopen(_argv[3], "wb+");
 if(pf==NULL)
 {
	 printf("Can't open file\n");
	 exit(0);
 }
 Peo p[4];
 for(int i=0;i<4;i++)
  {
        if(*_argv[1]=='1') 
	{	
		fscanf(fp,"%d %s %f %f %f %d\n",&p[i].id,p[i].str,&p[i].s1,&p[i].s2,&p[i].s3,&p[i].s4);
		printf("%d, %s, %f, %f, %f, %d\n",p[i].id,p[i].str,p[i].s1,p[i].s2,p[i].s3,p[i].s4);
	}
	if(*_argv[1]=='2')
	{
		 fscanf(fp,"%d %s %f %f %f %d\n",&p[i].id,p[i].str,&p[i].s1,&p[i].s2,&p[i].s3,&p[i].s4);
	       	fwrite(&p[i],sizeof(Peo),1,pf);
	}
  }
 fclose(fp);
  fclose(pf);
  pf=NULL;
  fp=NULL;
 return 0;
}


