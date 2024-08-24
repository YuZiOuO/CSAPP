#include "registers.h"
int strings_not_equal(char* arg1,char* arg2){
    rbx = arg1; //char*
    rbp = arg2; //char*
    eax = strlen(arg1);
    r12d = eax;
    rdi = arg2;
    eax = strlen(arg2);
    edx = 1;
    if(eax != r12d){
        goto L5;
    }

    eax = *rbx;
    if(al == 0){
        goto L3; //*arg1=='\0' return 0
    }

    if(*rbp==al){
        goto L2;//字符相同，开始循环
    } 
    goto .L4;//字符不同 return 1；

    L1:if(*rbp != al){
        goto L6;//字符不同 return 1;
    }
    L2:rbx++;
    rbp++;
    eax = *rbx;
    if(al != 0){
        goto L1;
    } 
    edx = 0;
    goto L5;
    L3:edx = 0;
    goto L5;
    L4:edx = 1;
    goto L5;
    L6:edx = 1;
    L5:eax = edx;

    return eax
}

int strings_not_equal_readable(char* arg1,char* arg2){
    if(strlen(arg1) != strlen(arg2)){
        return 1;
    }
    while(arg1 != '\0'){
        if(*arg1 != *arg2){
            return 1;
        }
        arg1++;
        arg2++;
    }
    return 0;
}