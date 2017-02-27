#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
typedef struct marcoList
{
    marcoList *p;   
    char *name;
    char type;
    val value;
    marcoList *n;  
}marcoList;

typedef union val
{
    char valc;
    double vald;
    int vali;
    char *p;
}val;
