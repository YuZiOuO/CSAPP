#include "registers.h"
int phase5(){
    stackPush(rbx);
    rsp-=20;
    rbx = rdi;
    ?rax = %fs:0x28;
    *(rsp+0x18) = rax;
    eax = 0;
    string_length();
    if(eax!=6){
        explode_bomb();
    }
    else{
        goto L1;
    }
    goto L1;
    L2:ecx = *
    (rbx+rax);
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

int phase5_readable(){
    stackPush(rbx);
    rsp -= 20;
    rbx = rdi;
    ?rax = %fs:0x28;
    *(rsp+18) = rax;
    if(string_length(rdi)!= 6){ //六位字符指针
        explode_bomb();
    }
    for(eax=0;rax!=6;rax++){
        ecx = *(rbx+rax);
        *(rsp) = cl;
        rdx = *rsp;
        edx &= 0xf;
        edx = *(rdx+0x4024b0);
        //0x4024b0: 6d616475 69657273 6e666f74 7662796c  maduiersnfotvbyl
        //"flyers" = 66 6C 79 65 72 73
        //edx: 0x9 0xf 0xe 0x5 0x6 0x7
        //对照ASCII表找16进制数第二位为上述的字符
        //ionuvw
        *(rsp+rax+16) = dl;
    }
    *(rsp+0x16) = 0;//byte;
    esi = 0x40245e;//"flyers"
    rdi = rsp+16;
    if(strings_not_equal(edi,esi)!=0){
        explode_bomb();
    }
    rax = *(rsp+0x18);
    ?rax = rax ^ %fs:0x28;
    if(rax != 0){
        __stack_chk_fail@plt();
    }
    rsp -= 0x20;
    stackPop(rbx);
    return eax;
}