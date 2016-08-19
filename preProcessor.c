#include<stdio.h>
#include<string.h>
void expandHeader(FILE *fp1,char *p,int flag)
{
    char dir[4][50]={"/usr/include/"},buf1[300];
    FILE *fph;
    strcat(dir[0],p);
    if(flag==2)
    {
        fph=fopen(p,"r");
    
    if (fph==NULL)
    {
    fph=fopen(dir[0],"r");
    }
    }
    else if(flag==1)
    fph=fopen(dir[0],"r");
    while(fgets(buf1,300,fph))
    {
        fputs(buf1,fp1);
    }
}
void remCmnt(FILE *fp,FILE *fp1)
{
    char buff[200],buff1[200],*in,*inf;
    int i,pos;
    //expandHeader(fp1,"stdio.h");
    while(fgets(buff,200,fp))
    {
        //l=strlen(buff);
        in=buff;
        if(strstr(buff,"#include"))
        {
            char *pos,*intial;
            char he[20];
            int flag,index1,index2,i;
            intial=buff;
           // printf("inloop");
            if(pos=strchr(buff,'<'))
            {   
                //printf("inloop1");
                index1=pos-intial;
                if(pos=strchr(buff,'>'))
                {
                   // printf("inloop2\n");
                    index2=pos-intial;
                    flag=1;
                    //printf("%d,%d",index1,index2);
                    if((index1==(index2-1)))
                    continue;
                    for(i=0,index1++;index1<index2;index1++,i++)
                   {
                        he[i]=buff[index1];
                    }
                    he[i]=0;
                   // printf("%s\n",he);
                    expandHeader(fp1,he,flag);
                }
                 else{
                        printf("\nend tag not found for hearfile\n ");
                        return;
                }
                
            }
              if(pos=strchr(buff,'"'))
            {   
              
                index1=pos-intial;
                if(pos=strrchr(buff,'"'))
                {
                  
                    index2=pos-intial;
                    flag=2;
                    //printf("%d,%d",index1,index2);
                    if((index1==(index2-1)))
                    continue;
                    for(i=0,index1++;index1<index2;index1++,i++)
                   {
                        he[i]=buff[index1];
                    }
                    he[i]=0;
                   // printf("%s\n",he);
                    expandHeader(fp1,he,flag);
                }
                 else{
                        printf("\nend tag not found for hearfile \n");
                        return;
                }
                
            }
            continue;
        }
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