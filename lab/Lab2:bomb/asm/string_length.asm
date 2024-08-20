000000000040131b <string_length>:
  40131b:	80 3f 00             	cmpb   $0x0,(%rdi) ;检查首字符是否为\0
  40131e:	74 12                	je     401332 <string_length+0x17> ;return 0
  401320:	48 89 fa             	mov    %rdi,%rdx ;%rdx = arg1
  401323:	48 83 c2 01          	add    $0x1,%rdx ;%rdx++ for()
  401327:	89 d0                	mov    %edx,%eax ;%eax = %edx 
  401329:	29 f8                	sub    %edi,%eax ;%eax -= arg1 长度为末指针与基指针的差
  40132b:	80 3a 00             	cmpb   $0x0,(%rdx) ;检查该字符是否为\0
  40132e:	75 f3                	jne    401323 <string_length+0x8> ;continue
  401330:	f3 c3                	repz ret 
  401332:	b8 00 00 00 00       	mov    $0x0,%eax
  401337:	c3                   	ret    

  ;rdx 字符指针
  int string_length(char*p)
  return 字符串长度,不计算\0