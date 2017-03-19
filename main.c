//
//  main.c
//  CopyFile
//
//  Created by Toby on 2017/3/19.
//  Copyright © 2017年 Toby. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define NUM 200 //可以拷贝多少行代码
int main(int argc, const char * argv[]) {
    // insert code here...
    if(argc!=2){
        printf("输入的格式不对哦\n");
        return 1;
    }
    //char filename[16];
    char name[80];
    char str[NUM][80];
    int i,j;
    sprintf(name,"/Users/toby/Documents/code/Test/Test/%s.c",argv[1]); //这样可以的！！
    FILE *fp1,*fp2;
    if((fp1=fopen("/Users/toby/Documents/code/Exam/Exam/main.c","r"))==NULL){
        printf("error1\n");
        return 1;
    }
    if((fp2=fopen(name,"w"))==NULL){
        printf("error2");
        return 1;
    }
    for(i=0;!feof(fp1)&&i<NUM;i++){
        fgets(&str[i][0], 80, fp1);
    }
    
    for(j=0;j<i;j++)
        fputs(&str[j][0], fp2);
    printf("Well down\n");
    return 0;
}
