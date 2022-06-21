#include <iostream>
#include <Windows.h>

//this is if you want to repatch the bytes
/*
if (!ammo)
	{
		*hook = 0x89;
		*(hook + 1) = 0x50;
		*(hook + 2) = 0x04;
	
	//or just
	//int ammorepatched[3] = {0x89, 0x50, 0x04};
	// for (int i = 0; i < sizeof(ammorepatched); i++) {
        //*(hook + i) = hook[i];
	}
*/

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
