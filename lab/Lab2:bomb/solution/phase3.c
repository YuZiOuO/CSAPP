#include <registers.h>
int phase3(){
    rsp-=18;
    rcx = *(rsp+12);
    rdx = *(rsp+8);
    esi = 0x4025cf;//0x4025cf "%d %d"
    eax = 0;
    __isoc99_sscanf@plt();
    if(eax > 1){
        if(*(rsp+8)>7){ //第一个输入<7 debug:rsp+8存放第一个输入
            explode_bomb();
        }
    }
    else{
        explode_bomb();
    }
    eax = *(rsp+8);
    goto *(0x402470+8*rax);
    /*
    *rax=0 0x400f7c L2
    *rax=1 0x400fb9 L9
    *rax=2 0x400f83 L3
    *rax=3 0x400f8a L4
    *rax=4 0x400f91 L5
    *rax=5 0x400f98 L6
    *rax=6 0x400f9f L7
    *rax=7 0x400fa6 L8
    all possible solutions for phase3:
    0 207
    1 311
    2 707
    3 256
    4 389
    5 206
    6 682
    7 327
    */
    L2:eax = 207; //0xcf
    goto L1;
    L3:eax = 707;//0x2c3
    goto L1;
    L4:eax = 256;//0x100
    goto L1;
    L5:eax = 389;//0x185
    goto L1;
    L6:eax = 206;//0xce
    goto L1;
    L7:eax = 682;//0x2aa
    goto L1;
    L8:eax = 327;//0x147
    goto L1;
    explode_bomb();
    eax = 0;
    goto L1;
    L9:eax = 311;//0x137
    L1:if(eax == *(rsp+12)){
        rsp+=18;
    }
    else{
        explode_bomb();
    }
    return eax;
}