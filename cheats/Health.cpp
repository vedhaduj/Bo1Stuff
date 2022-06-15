BOOL WINAPI DllMain(HINSTANCE hMod, DWORD dwReason, LPVOID lpReserved)
{
	unsigned char* healthhook = (unsigned char*)0x007DADD0;

	DWORD oldprotection;

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		
		VirtualProtect(ammohook, 3, PAGE_EXECUTE_READWRITE, &oldprotection);
		//health
		*healthhook = 0x90;
		*(healthhook + 1) = 0x90;
		*(healthhook + 2) = 0x90;
		*(healthhook + 3) = 0x90;
		*(healthhook + 4) = 0x90;
		*(healthhook + 5) = 0x90;
		break;	
	}
	return TRUE;
}
