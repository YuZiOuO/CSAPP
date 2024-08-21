#include "registers.h"
int phase4(){
    rsp -= 24;
    rcx = *(rsp+12);
    esi = 0x4025cf;//"%d %d"
    eax = 0;
    __isoc99_sscanf@plt(); //*(rsp+8) = input1 ; *(rsp+12) = input2
    if(eax!=2){
        explode_bomb();
    }
    if(*(rsp+8)>15){//input1 <= 15
        explode_bomb();
    }
    edx = 14;
    esi = 0;
    edi = *(rsp+8);
    func4();//0x400fce
    if(eax!=0){
        explode_bomb();
    }
    if(*(rsp+12)==0){
        rsp+=24;
    }
    else{
        explode_bomb();
    }
    return eax;//Defuse: input2 == 0 && func4(input1,0,14) == 0;
}
int func4(int edi = *(rsp+8),int esi=0,int edx = 14){
    rsp -= 8;
    eax = edx;
    eax -= esi;
    ecx = eax;
    ecx >> 31;//logical
    eax += ecx;
    eax >> 1;//arthmetic
    ecx = rax + rsi;
    if(ecx<=edi){
        goto L1;
    }
    edx = rcx-1;
    func4();
    eax *= 2;
    goto L2;
    L1:eax = 0;
    if(ecx >= edi){
        goto L2;
    }
    esi = rcx+1;
    func4();
    eax = 2*rax+1;
    L2:rsp+=8;
    return eax;
}

int func4_readable(int edi,int esi=0,int edx=14){
    malloc(8);
    int var0 = arg3-arg2;
    int var1 = var0+(var0>>31);
    var0 = arg2+(var1>>1);
    if(var0<=arg1){
        if(var0!=arg1){
            return 2*fun4(arg1,var0+1,arg3)+1;
        }
        return 0;
    }
    else{
        return 2*fun4(arg1,arg2,var0-1);
    }

/* fun4_less_readable()
    ecx = (edx-esi)>>31;
    eax = ((edx-esi)+(edx-esi)>>31)>>1;//logical
    ecx = rax+rsi;
    if(ecx <= edi){
        if(ecx!=edi){
            esi = rcx+1;
            return 2*fun4()+1;
        }
        return 0;
    }
    else{
        edx = rcx-1;
        return 2*fun4();
    }
*/

}