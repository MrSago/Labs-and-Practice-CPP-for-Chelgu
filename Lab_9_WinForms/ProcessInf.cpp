#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "ProcessInf.h"


void Process::GetMainProcessInfo() {

	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;
	PROCESS_MEMORY_COUNTERS pmc;
	
	if (list.size() > 0) {
		list.clear();
	}

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE) {
		return;
	}

	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(hProcessSnap, &pe32)) {
		CloseHandle(hProcessSnap);
		return;
	}

	do {

		SIZE_T mem = 0;
		double curCPU = 0;

		dwPriorityClass = 0;
		hProcess = OpenProcess(MAXIMUM_ALLOWED, FALSE, pe32.th32ProcessID);
		if (hProcess != NULL) {
			dwPriorityClass = GetPriorityClass(hProcess);
			GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc));
			//curCPU
			mem = pmc.WorkingSetSize;
			CloseHandle(hProcess);
		}

		list.push_back
		(
			ProcessList
			(
				__ProcessInfo(pe32.szExeFile, pe32.th32ProcessID, pe32.th32ParentProcessID, curCPU, mem, pe32.cntThreads, pe32.pcPriClassBase, dwPriorityClass)
			)
		);

	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	return;
}

void Process::GetFullProcessInfo() {
	
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;
	PROCESS_MEMORY_COUNTERS pmc;

	if (list.size() > 0) {
		list.clear();
	}

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE) {
		return;
	}

	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(hProcessSnap, &pe32)) {
		CloseHandle(hProcessSnap);
		return;
	}

	do {

		SIZE_T mem = 0;
		double curCPU = 0;

		dwPriorityClass = 0;
		hProcess = OpenProcess(MAXIMUM_ALLOWED, FALSE, pe32.th32ProcessID);
		if (hProcess != NULL) {
			dwPriorityClass = GetPriorityClass(hProcess);
			GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc));
			//curCPU
			mem = pmc.WorkingSetSize;
			CloseHandle(hProcess);
		}

		list.push_back
		(
			ProcessList
				(
					__ProcessInfo
					(
						pe32.szExeFile,
						pe32.th32ProcessID,
						pe32.th32ParentProcessID,
						curCPU,
						mem,
						pe32.cntThreads,
						pe32.pcPriClassBase,
						dwPriorityClass
					),
					std::vector<__ModuleInfo>
					(
						ListProcessModules(pe32.th32ProcessID)
					),
					std::vector<__ThreadInfo>
					(
						ListProcessThreads(pe32.th32ProcessID)
					)
				)
		);

	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	return;
}

std::vector<__ModuleInfo> Process::ListProcessModules(DWORD dwPID) {

	std::vector<__ModuleInfo> mInfo;
	HANDLE hModuleSnap;
	MODULEENTRY32 me32;

	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);
	if (hModuleSnap == INVALID_HANDLE_VALUE) {
		return mInfo;
	}

	me32.dwSize = sizeof(MODULEENTRY32);

	if (!Module32First(hModuleSnap, &me32)) {
		CloseHandle(hModuleSnap);
		return mInfo;
	}

	do {

		mInfo.push_back
		(
			__ModuleInfo
			(
				me32.szModule,
				me32.szExePath,
				me32.th32ProcessID,
				me32.GlblcntUsage,
				me32.ProccntUsage,
				(DWORD)me32.modBaseAddr,
				me32.modBaseSize
			)
		);

	} while (Module32Next(hModuleSnap, &me32));

	CloseHandle(hModuleSnap);
	return mInfo;
}

std::vector<__ThreadInfo> Process::ListProcessThreads(DWORD dwOwnerPID) {

	std::vector<__ThreadInfo> thInfo;
	HANDLE hThreadSnap;
	THREADENTRY32 te32;

	hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (hThreadSnap == INVALID_HANDLE_VALUE) {
		return thInfo;
	}

	te32.dwSize = sizeof(THREADENTRY32);

	if (!Thread32First(hThreadSnap, &te32)) {
		CloseHandle(hThreadSnap);
		return thInfo;
	}

	do {

		if (te32.th32OwnerProcessID == dwOwnerPID) {

			thInfo.push_back
			(
				__ThreadInfo
				(
					te32.th32ThreadID,
					te32.tpBasePri,
					te32.tpDeltaPri
				)
			);
		}

	} while (Thread32Next(hThreadSnap, &te32));

	CloseHandle(hThreadSnap);
	return thInfo;
}

void Process::KillProcess(DWORD dwPID) {

	HANDLE hwnd = OpenProcess(MAXIMUM_ALLOWED, FALSE, dwPID);

	if (hwnd == NULL)
		return;

	TerminateProcess(hwnd, NULL);

	return;
}

std::string Process::ProcessPriority(DWORD dwPriorityClass) {

	switch (dwPriorityClass)
	{
	case REALTIME_PRIORITY_CLASS:
		return "Real Time";
		
	case HIGH_PRIORITY_CLASS:
		return "High";

	case NORMAL_PRIORITY_CLASS:
		return "Normal";

	case IDLE_PRIORITY_CLASS:
		return "Low";

	default:
		return "High";
	}

	return "";
}


void Process::PrintMainInfo() {

	std::cout
		<< std::setiosflags(std::ios::left)
		<< std::setw(STR_TAB) << "Name:"
		<< std::setw(TAB) << "PID:"
		<< std::setw(TAB) << "ParentPID:"
		<< std::setw(TAB) << "CPU(%):"
		<< std::setw(TAB) << "RAM:" << std::setw(TAB)
		<< "Thread count:" << std::setw(TAB)
		<< "Priority Base:" << "Priority class:" << std::endl;

	for (size_t i = 0; i < list.size(); ++i) {

		std::cout
			<< std::setw(STR_TAB) << list[i].pInfo.File
			<< std::setw(TAB) << list[i].pInfo.PID
			<< std::setw(TAB) << list[i].pInfo.ParentPID
			<< std::setw(TAB) << list[i].pInfo.CPUusage
			<< std::setw(TAB) << list[i].pInfo.RAMusage
			<< std::setw(TAB) << list[i].pInfo.Threads
			<< std::setw(TAB) << list[i].pInfo.PriorityBase
			<< list[i].pInfo.PriorityClass << std::endl;
	}
}

void Process::PrintFullInfo() {

	for (size_t i = 0; i < list.size(); ++i) {

		std::cout << "\n\n=====================================================";
		std::cout << "\nPROCESS NAME:  " << list[i].pInfo.File;
		std::cout << "\n-------------------------------------------------------";

		std::cout << "\n  Process ID        = " << list[i].pInfo.PID;
		std::cout << "\n  Parent process ID = " << list[i].pInfo.ParentPID;
		std::cout << "\n  CPU(%)            = " << list[i].pInfo.CPUusage;
		std::cout << "\n  RAM               = " << list[i].pInfo.RAMusage;
		std::cout << "\n  Thread count      = " << list[i].pInfo.Threads;
		std::cout << "\n  Priority base     = " << list[i].pInfo.PriorityBase;
		std::cout << "\n  Priority class    = " << list[i].pInfo.PriorityClass;


		for (size_t j = 0; j < list[i].mInfo.size(); ++j) {

			std::cout << "\n\n     MODULE NAME:     " << list[i].mInfo[j].Name;
			std::cout << "\n     Executable     = " << list[i].mInfo[j].PathFile;
			std::cout << "\n     Process ID     = " << list[i].mInfo[j].PID;
			std::cout << "\n     Ref count (g)  = 0x" << std::hex << list[i].mInfo[j].RefCountG;
			std::cout << "\n     Ref count (p)  = 0x" << std::hex << list[i].mInfo[j].RefCountP;
			std::cout << "\n     Base address   = 0x" << std::hex << list[i].mInfo[j].BaseAddress;
			std::cout << "\n     Base size      = 0x" << std::hex << list[i].mInfo[j].BaseSize;
		}

		for (size_t j = 0; j < list[i].thInfo.size(); ++j) {

			std::cout << "\n\n     THREAD ID      = " << list[i].thInfo[j].ID;
			std::cout << "\n     Base priority  = " << list[i].thInfo[j].BasePri;
			std::cout << "\n     Delta priority = " << list[i].thInfo[j].DeltaPri;
		}

		std::cout << "\n\nPress any key to next process..." << std::endl;
	}
}