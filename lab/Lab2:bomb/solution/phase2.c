#include <registers.h>
int phase2(char* edi){ //edi=input
    stackPush(rbp);
    stackPush(rbx);
    rsp -= 28;
    rsi = rsp;
    read_six_number();
    //debug:该函数返回后,*rsp保存读取到的第一个元素,*(rsp+4)保存第二个
    if(*rsp == 1){
        goto L1;
    }
    explode_bomb();
    goto L1;
    L3:eax = *(rbx-4);
    eax *= 2;
    if(*rbx == eax){
        goto L2;
    }
    explode_bomb();
    L2:rbx+=4;
    if(rbx != rbp){
        goto L3;
    }
    goto L4;
    L1:rbx = *(rsp+4);
    rbp = *(rsp+18);
    goto L3;
    L4:rsp += 28;
    stackPop(rbx);
    stackPop(rbp);
}
int phase2_readable(char* edi){
    stackPush(rbp);
    stackPush(rbx);
    rsp -= 28;
    rsi = rsp;
    read_six_number();
    if(*rsp != 1){
        explode_bomb();//第一个输入必须为1;
    }
    rbx = *(rsp+4);//rbx = 第二个输入
    rbp = *(rsp+24);
    do{
        eax = *(rbx-4);
        eax *= 2;
        if(*rbx == eax){
            rbx+=4;
        }
        else{
            explode_bomb();
        }
    }while(rbx != rbp);
    rsp += 28;
    stackPop(rbx);
    stackPop(rbp);
}