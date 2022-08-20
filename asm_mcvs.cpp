#include <iostream>
#pragma region Shell
int dummy()
{
    std::cout << "Hello World!\n";
    return 1;
}

#pragma section(".text")
__declspec(allocate(".text"))
__int8 shelld[] = { 0x90 ,0x90 ,0x90, 0x90 , 0x49, 0x89, 0xC6 ,  0xC3 };
__declspec(allocate(".text"))
void* testptr[] = { &dummy };
__declspec(allocate(".text"))
__int8 shell[] = {  0xFF ,0x15 ,0x02, 0x00 ,0x00, 0x00, 0xEB, 0x08 }; //call 0xFF ,0x15 ,0x02, 0x00 ,0x00, 0x00, 0xEB, 0x08   
#pragma endregion Shell
int main()
{
    reinterpret_cast<void(*)()>(&shell[0])(); // for test only
}
