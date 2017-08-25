#include<stdio.h>  
#include<assert.h>  
int my_strlen(const char*p)//const 修饰p 不可修改的字符串  
{  
    int count=0;//计数器  
    assert(p！=NULL);//断言，如果p==NULL，则报错  
    while(*p!='\0')//判断空字符停止  
    {  
        p++;  
        count++;  
    }  
    return count;  
  
}  
int main()  
{  
    char*p="abcdef";  
    int ret=0;  
    ret=my_strlen(p);  
    printf("%d\n",ret);  
    return 0;  
}  
递归版：
[objc] view plain copy
#include<stdio.h>  
#include<assert.h>  
int my_strlen(const char*p)//const 修饰p 不可修改的字符串  
{  
    assert(p!=NULL);//断言，如果p==NULL，则报错  
    if(*p == '\0')  
        return 0;  
    else  
        return (1 + my_strlen(p+1));   
}  
int main()  
{  
    char*p="abcdef";  
    int ret=0;  
    ret=my_strlen(p);  
    printf("%d\n",ret);  
    return 0;  
}  
