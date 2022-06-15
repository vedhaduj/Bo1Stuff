BOOL WINAPI DllMain(HINSTANCE hMod, DWORD dwReason, LPVOID lpReserved)
{
	unsigned char* healthhook = (unsigned char*)0x007DADD0;

	DWORD oldprotection;

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		
			//This doesn't work for when your holding grenades
			//for example it basically doesn't a check to see if health is less than or equal to zero
			//so basically it will call the death function
			//Just like in assault cube cause your standing in the middle of a grenade so ofc you are dead..
		VirtualProtect(healthhook, 6, PAGE_EXECUTE_READWRITE, &oldprotection);
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
