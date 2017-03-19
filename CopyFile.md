#拷本文件到特定文件夹
最近在准备考研复试时，用Xcode练习c，但是每次写新程序的时候还要重新创建工程，只是写个普通的练习代码就生成这么多文件，实在忍受不了。所以每次完成都是把.c的源文件拷本到一个特定文件夹，然后直接在当前工程重新写代码。不过，懒癌晚期的我同样忍不了打开层层文件夹，拷本文件然后改名字，所以，我就用正在复习的c语言文件章节写了个文件拷本程序，直接通过一个命令完成所有操作。
##代码
	#include <stdio.h>
	int main(int argc, const char * argv[]) {
    // insert code here...
    if(argc!=2){
        printf("输入错误哦\n");
        return 1;
    }
    char name[80],ch;
    FILE *fp1,*fp2;
    sprintf(name,"/Users/toby/Documents/code/Test/Test/%s.c",argv[1]);//目标路径，改成目标文件夹
    if((fp1=fopen("/Users/toby/Documents/code/Exam/Exam/main.c","r"))==NULL)//要考本的文件
    {
        printf("读取错误\n");
        return 1;
    }
    if((fp2=fopen(name,"w"))==NULL){
        printf("写入错误\n");
        return 1;
    }
    ch=fgetc(fp1);//getc函数，一个字符一个字符拷贝
    while (ch!=EOF) {
        fputc(ch,fp2);
        ch=fgetc(fp1);
    }
    printf("拷贝完成！\n");
    return 0
    }
##使用
源码比较简单，想要使用的话改改路径就可以。想要直接在命令行，还要把编译的好的文件路径写到环境变量里![环境变量](/Users/toby/Desktop/HomeFile.png)
环境变量写好后就可以使用了，我的程序名称是cfile，后面直接跟拷本的文件名字就行![使用事例](/Users/toby/Desktop/result.png) 使用很流畅。[github连接](http)
    