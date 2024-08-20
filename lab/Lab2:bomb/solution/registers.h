int* rdi,rsi,rdx,rcx,r8,r9;//arg
int* rax;//return val
int* rsp;//stack
int* r10,r11;//caller saved
int* rbx,rbp,r12,r13,r14,r15;//callee saved
//QWORD

int* al,bl,cl,dl,
    sil,dil,bpl,spl,
    r8b,r9b,r10b,r11b,
    r12b,r13b,r14b,r15b;//BYTE
int* ax,bx,cx,dx,
    si,di,bp,sp,
    r8w,r9q,r10w,r11w,
    r12w,r13w,r14w,r15w;//WORD
int* eax,ebx,ecx,edx,
    esi,edi,ebp,esp,
    r8d,r9d,r10d,r11d,
    r12d,r13d,r14d,r15d;//DWORD

int* arg1,arg2,arg3,arg4,arg5,arg6;
void stackPush(int*);
void stackPop(int*);
void explode_bomb();
