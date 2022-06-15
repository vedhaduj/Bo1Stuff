#include <iostream>
#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE hMod, DWORD dwReason, LPVOID lpReserved)
{
	//mov dword ptr ds:[eax+4], edx
	unsigned char* hook = (unsigned char*)0x00697A10;

	DWORD oldprotection;

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		VirtualProtect(hook, 3, PAGE_EXECUTE_READWRITE, &oldprotection);
		*hook = 0x90;
		*(hook + 1) = 0x90;
		*(hook + 2) = 0x90;
		break;	
	}
	return TRUE;
}
