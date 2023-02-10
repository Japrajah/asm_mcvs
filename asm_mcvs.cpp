#include <iostream>
__int64 dataptr = 0x00100023;
int dummy() { std::cout << "Hello World!\n"; return 1;}
int dummy2() {std::cout << "Hello dummy2!\n";  return 1;}


#pragma region JmpToDataShell
#pragma section(".text")
__declspec(allocate(".text"))  void* DATA_jmp[3] = { (void*)0xA148909090909090,&dataptr  ,(void*)0xE0FFE0FFE0FFE0FF };
// nop *6 ← 909090909090
// mov rax, ← A148
// [dataptr]   
// jmp rax (x4) ←  E0FF
#pragma endregion JmpToDataShell

int main()
{
    dataptr = (__int64)&dummy;
    reinterpret_cast<void(*)()>(&DATA_jmp[0])();
    dataptr = (__int64)&dummy2;
    reinterpret_cast<void(*)()>(&DATA_jmp[0])();
}
