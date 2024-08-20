#include <registers.h>
int read_six_number(){
    rsp -= 18;
    rdx = arg2;
    rcx = arg2+4;
    rax = arg2+14;
    *(rsp+8) = rax;
    rax = arg2+10;
    *rsp = rax;
    r9 = arg2+12;
    r8 = arg2+8;
    esi = 0x4025c3;//char* at 0x4025c3:"%d %d %d %d %d %d\0"
    eax = 0;
    eax = scanf("%d %d %d %d %d %d"); //scanf return读取成功值个数,rsi保存最后读取的数据
    if(eax>5){
        goto L1;//explode if input less than 5 numbers
    }
    explode_bomb();
    L1:rsp += 18;
    return eax;
}