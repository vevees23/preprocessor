#include<stdio.h>
#include<string.h>
void expandHeader(FILE *fp1,char *p)
{
    char dir[4][50]={"/usr/include/"},buf1[300];
    FILE *fph;
    strcat(dir[0],p);
    fph=fopen(dir[0],"r");
    while(fgets(buf1,200,fph))
    {
        fputs(buf1,fp1);
    }
}
void remCmnt(FILE *fp,FILE *fp1)
{
    char buff[200],buff1[200],*in,*inf;
    int i,pos;
    expandHeader(fp1,"stdio.h");
    while(fgets(buff,200,fp))
    {
        //l=strlen(buff);
        in=buff;
        if(inf=strstr(buff,"//"))
        {
            pos=inf-in;
            buff[pos]='\n';
            buff[pos+1]='\0';
        }
        in=buff;
        if(inf=strstr(buff,"/*"))
        {
            pos=inf-in;  
            if(strstr(buff,"*/"));
            else
            while(1)
            {   
               if(fgets(buff1,200,fp))
               {
                    if(strstr(buff1,"*/"))
                    break;
               }
              else
                  break;
            }
            buff[pos]='\n';
            buff[pos+1]='\0';
        }
        fputs(buff,fp1); 
    }
    return;
}

main(int argc ,char **argv)
{
    FILE *fp,*fp1;
    char d[20];
    int i;
    for(i=0;i<strlen(argv[1]) && argv[1][i]!='.';i++)
    {
        d[i]=argv[1][i];
    }
    d[i++]='.';
    d[i++]='i';
    d[i]='\0';
    fp=fopen(argv[1],"r");
    if(fp==NULL)
    {
        printf("no file found\n");
        return;
    }
    fp1=fopen(d,"w");
    remCmnt(fp,fp1);

fclose(fp1);
fclose(fp);
}