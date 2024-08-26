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
    read_six_number();//依次保存到*(rsp+4*i) eax返回输入个数;
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
    }//every input ought to be different
    rsi = rsp+0x18;
    rax = r14;
    ecx = 7;
    do{
        edx = ecx;
        edx -= *rax;
        *rax = edx;
        rax += 4;
    }while(rax != rsi);//input[i] = 7-input[i] for i in range(0,6) 
    esi = 0;
    goto L6;
    while(TRUE){
        rdx = *(rdx+8);
        eax++;
        if(eax != ecx){
            continue;
        }
        do{
            edx = 0x6032d0;//0x6032d0:4c 01 00 00
            *(rsp+2*rsi+0x20) = rdx;
            rsi += 4;
            if(rsi == 0x18){
                goto L10;
            }
            L6:ecx = *(rsp+rsi);//traverse every input
        }while(ecx<=1);
        eax = 1;
        edx = 0x6032d0;
    }
    //successively store 6 int64 value addr[i] =  (int32)*(0x6032d0+8*input[i]) at *(rsp+0x20)
    //except when input[i] = 1 , stores 0x006032d0
    /*debug:
    0x7fffffffdc90: 0x00000006      0x00000005      0x00000004      0x00000003
    0x7fffffffdca0: 0x00000002      0x00000001      0x00000000      0x00000000
    0x7fffffffdcb0: 0x00603320      0x00000000      0x00603310      0x00000000
    0x7fffffffdcc0: 0x00603300      0x00000000      0x006032f0      0x00000000
    0x7fffffffdcd0: 0x006032e0      0x00000000      0x006032d0      0x00000000
    */
    L10:rbx = *(rsp+0x20);
    rax = rsp+0x28;
    rsi = rsp+0x50;
    rcx = rbx;
    while (TRUE)
    {
        rdx = *rax;
        *(rcx+8) = rdx;
        rax += 8;
        if(rax == rsi){
            break;
        }
        rcx = rdx;
    }
    *(rdx+8) = 0;
    /*
    * traverse every value(aka an addr) stored at *(rsp+0x20);
    * *(addr[i]+8) = addr[i+1];
    * except:(addr[i]+8) = 0 when i=5
    * 构造链表,0为空指针
    */
    ebp = 5;
    /*
    * now:
    * rax:rsp+0x50
    * rbx:*(rsp+0x20) //rbx = first addr
    */
    do{
        rax = *(rbx+8); //rax = next addr
        eax = *rax; //eax = next elem
        if(*rbx < eax){ //next elem ought to < prve elem
            explode_bomb();
        }
        rbx = *(rbx+8);
        ebp -= 1;
    }while(ebp != 0);
    //require *(addr[i]+8) >= *(addr[i+1]+8);
    rsp += 50;
    stackPop(r14,r13,r12,rbp,rbx);
}

int phase6_c(){
    int input[6];
    scanf("%d %d %d %d %d %d",input);
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(input[i] == input[j]){
                explode_bomb();
            }
        }
    }
    for(int i=0;i<5;i++){
        input[i] = 7-input[i];
    }
    int* addr[6];
    for(int i=0;i<5;i++){
        if(input[i] == 1){
            addr[i] = 0x6032d0;
        }
        else{
            addr[i] = *(0x6032d0+0x10*(input[i]-1)+8);
            /*
            6032d0 4c010000 01000000 e0326000 00000000  L........2`.....
            6032e0 a8000000 02000000 f0326000 00000000  .........2`.....
            6032f0 9c030000 03000000 00336000 00000000  .........3`.....
            603300 b3020000 04000000 10336000 00000000  .........3`.....
            603310 dd010000 05000000 20336000 00000000  ........ 3`.....
            603320 bb010000 06000000 00000000 00000000  ................
            603330 00000000 00000000 00000000 00000000  ................
            */
        }
    }
    for(int i=0;i<5;i++){
        if(i==5){
            *(addr[i]+8) = 0;
        }else{
            *(addr[i]+8) = *addr[i+1];
        }
    }
    for(int i=0;i<5;i++){
        if(*(addr[i]+8) < *(addr[i+1]+8){
            explode_bomb();
        }
        /*
        addr[4] 6032d0 4c010000 0x14c
        addr[5] 6032e0 a8000000 0xa8
        addr[0] 6032f0 9c030000 0x39c
        addr[1] 603300 b3020000 0x2b3
        addr[2] 603310 dd010000 0x1dd
        addr[3] 603320 bb010000 0x1bb
        603330 00000000 00000000 00000000 00000000  ................
        */
    }
    return 0;
}