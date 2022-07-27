#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>


MODULEENTRY32 GetModule(const char* moduleName, unsigned long ProcessID)
{
	MODULEENTRY32 modEntry = { 0 };

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, ProcessID);

	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 curr = { 0 };

		curr.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &curr))
		{
			do
			{
				if (!strcmp(curr.szModule, moduleName))
				{
					modEntry = curr;
					break;
				}
			} while (Module32Next(hSnapshot, &curr));
		}
		CloseHandle(hSnapshot);
	}
	return modEntry;
}
//Call of Duty®
int main()
{
	DWORD pid;
	DWORD* test{};
	DWORD entitystart = 0x00;
	int health{};
	int healthchange = 0;
	int currentzombies{};
	HWND ac = FindWindowA(0, "Call of Duty®: BlackOps");
	if (!ac)
	{
		std::cout << "Couldn't find window\n";
		return 0;
	}
	GetWindowThreadProcessId(ac, &pid);
	MODULEENTRY32 module = GetModule("BlackOps.exe", pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (module.modBaseAddr == nullptr || module.modBaseAddr == NULL)
	{
		std::cout << "BASE ADDRESS IS NULL\n";
		return 0;
	}
	else
	{
	
		ReadProcessMemory(phandle, (void*)((unsigned long long)module.modBaseAddr + 0x17FBC20), &currentzombies, sizeof(currentzombies), 0);

		for (int i = 0; i < currentzombies; i++) //300 = zombies 
		{
			ReadProcessMemory(phandle, (void*)((unsigned long long)module.modBaseAddr + 0x017FBC84 + entitystart), &test, sizeof(test), 0);
			ReadProcessMemory(phandle, (void*)((unsigned long long)test + 0x184), &health, sizeof(health), 0);
			WriteProcessMemory(phandle, (void*)((unsigned long long)test + 0x184), &healthchange, sizeof(healthchange), 0);
			std::cout << health << std::endl;

			entitystart = entitystart + 0x8C;
		}
	}

}
