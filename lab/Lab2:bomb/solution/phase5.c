#include "registers.h"
int phase5(){
    stackPush(rbx);
    rsp-=20;
    rbx = rdi;
    ?rax = %fs:0x28;
    *(rsp+18) = rax;
    eax = 0;
    string_length();
    if(eax!=6){
        explode_bomb();
    }
    else{
        goto L1;
    }
    goto L1;
    L2:ecx = rbx+rax;
    *(rsp) = cl;
    rdx = *rsp;
    edx &= 0xf;
    edx = *(rdx+0x4024b0);
    *(rsp+rax+16) = dl;
    rax++;
    if(rax!=6){
        goto L2;
    }
    *(rsp+16) = 0;//byte;
    esi = 0x40245e;
    rdi = rsp+10;
    strings_not_equal();
    if(eax==0){
        goto L3;
    }
    else{
        explode_bomb();
    }
    goto L3;
    L1:eax = 0;
    goto L2;
    L3:rax = *(rsp+18);
    ?rax = rax ^ %fs:0x28;
    if(rax != 0){
        __stack_chk_fail@plt();
    }
    rsp -= 0x20;
    stackPop(rbx);
    return eax;
}