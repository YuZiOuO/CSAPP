#include "registers.h"
#define TRUE 1
int phase6(){
    stackPush(r14,r13,r12,rbp,rbx);
    rsp-=50;
    r13,rsi = rsp;
    read_six_number();
    r14 = rsp;
    r12d = 0;
    401114:rbp = r13;
    eax = *r13;
    eax-=1;
    if(eax <= 5){
        goto 401128;
    }
    explode_bomb();
    401128:r12d+=1;
    if(r12d==6){
        goto 401153;
    }
    ebx = r12d;
    401135:rax = ebx;
    eax = *(rsp+4*rax);
    if(eax != *rbp){
        goto 401145;
    }
    explode_bomb();
    401145:ebx++;
    if(ebx<=5){
        goto 401135;
    }
    r13 += 4;
    goto 401114;
    401153:rsi = rsp+0x18;
    rax = r14;
    ecx = 7;
    401160:edx = ecx;
    edx -= *rax;
    *rax = edx;
    rax += 4;
    if(rax != rsi){
        goto 401160;
    }
    esi = 0;
    goto 401197;
    401176:rdx = *(rdx+8);
    eax++;
    if(eax != ecx){
        goto 401176;
    }
    goto 401188;
    401183:edx = 0x6032d0;
    401188:*(rsp+2*rsi+0x20) = rdx;
    rsi += 4;
    if(rsi == 0x18){
        goto 4011ab;
    }
    401197:ecx = *(rsp+rsi);
    if(ecx<=1){
        goto 401183;
    }
    eax = 1;
    edx = 0x6032d0;
    goto 401176;
    4011ab:rbx = *(rsp+0x20);
    rax = rsp+0x28;
    rsi = rax+0x50;
    rcx = rbx;
    4011bd:rdx = *rax;
    *(rcx+8) = rdx;
    rax = 8;
    4011c8:if(rax == rsi){
        goto 4011d2;
    }
    rcx = rdx;
    goto 4011bd;
    4011d2:*(rdx+8) = 0;
    ebp = 5;
    4011df:rax = *(rbx+8);
    4011e3:eax = *rax;
    if(*rbx == eax){
        goto 4011ee;  
    }
    explode_bomb();
    4011ee:rbx = *(rbx+8);
    ebp -= 1;
    if(ebp != 0){
        goto 4011df;
    }
    rsp += 50;
    stackPop(r14,r13,r12,rbp,rbx);
}

int phase6_readable(){
    stackPush(r14,r13,r12,rbp,rbx);
    rsp-=50;
    r13,rsi = rsp;
    read_six_number();
    r14 = rsp;
    r12d = 0;
    while (TRUE)
    {
        rbp = r13;
        eax = *r13;
        eax-=1;
        if(eax <= 5){
            r12d+=1;
        }else{
            explode_bomb();
        }
        if(r12d==6){
            break;
        }
        ebx = r12d;
        do{
            rax = ebx;
            eax = *(rsp+4*rax);
            if(eax != *rbp){
                ebx++;
            }else{
                explode_bomb();
            }
        }while(ebx<=5);
        r13 += 4;
    }
    rsi = rsp+0x18;
    rax = r14;
    ecx = 7;
    do{
        edx = ecx;
        edx -= *rax;
        *rax = edx;
        rax += 4;
    }while(rax != rsi);
    esi = 0;
    goto L6;
    while(TRUE){
        rdx = *(rdx+8);
        eax++;
        if(eax != ecx){
            continue;
        }
        do{
            L9:edx = 0x6032d0;
            L8:*(rsp+2*rsi+0x20) = rdx;
            rsi += 4;
            if(rsi == 0x18){
                goto L10;
            }
            L6:ecx = *(rsp+rsi);
        }while(ecx<=1);
        eax = 1;
        edx = 0x6032d0;
    }
    L10:rbx = *(rsp+0x20);
    rax = rsp+0x28;
    rsi = rax+0x50;
    rcx = rbx;
    while (TRUE)
    {
        rdx = *rax;
        *(rcx+8) = rdx;
        rax = 8;
        if(rax == rsi){
            break;
        }
        rcx = rdx;
    }
    *(rdx+8) = 0;
    ebp = 5;
    do{
        rax = *(rbx+8);
        eax = *rax;
        if(*rbx != eax){
            explode_bomb();
        }
        rbx = *(rbx+8);
        ebp -= 1;
    }while(ebp != 0);
    rsp += 50;
    stackPop(r14,r13,r12,rbp,rbx);
}