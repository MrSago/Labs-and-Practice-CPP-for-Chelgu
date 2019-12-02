#ifndef __PROCESS_H
#define __PROCESS_H

#include <vector>
#include <string>

#ifndef _WINDOWS_
typedef unsigned long DWORD;
typedef unsigned long long SIZE_T;
typedef char CHAR;
typedef long LONG;
#endif

struct __ProcessInfo {
	std::string File = "";
	DWORD PID = 0;
	DWORD ParentPID = 0;
	double CPUusage = 0;
	SIZE_T RAMusage = 0;
	DWORD Threads = 0;
	DWORD PriorityBase = 0;
	DWORD PriorityClass = 0;

	__ProcessInfo
	(
		CHAR* _File,
		DWORD _PID,
		DWORD _ParentPID,
		double _CPUusage,
		SIZE_T _RAMusage,
		DWORD _Threads,
		DWORD _PriorityBase,
		DWORD _PriorityClass
	) :
		File(_File),
		PID(_PID),
		ParentPID(_ParentPID),
		CPUusage(_CPUusage),
		RAMusage(_RAMusage),
		Threads(_Threads),
		PriorityBase(_PriorityBase),
		PriorityClass(_PriorityClass)
	{}
};

struct __ModuleInfo {
	std::string Name = "";
	std::string PathFile = "";
	DWORD PID = 0;
	DWORD RefCountG = 0; //=======hex=======
	DWORD RefCountP = 0;
	DWORD BaseAddress = 0;
	DWORD BaseSize = 0;	//------------------

	__ModuleInfo
	(
		CHAR* _Name,
		CHAR* _pathFile,
		DWORD _PID,
		DWORD _RefCountG,
		DWORD _RefCountP,
		DWORD _Address,
		DWORD _Size
	) :
		Name(_Name),
		PathFile(_pathFile),
		PID(_PID),
		RefCountG(_RefCountG),
		RefCountP(_RefCountP),
		BaseAddress(_Address),
		BaseSize(_Size)
	{}
};

struct __ThreadInfo {
	DWORD ID = 0;
	LONG BasePri = 0;
	LONG DeltaPri = 0;

	__ThreadInfo
	(
		DWORD _ID,
		LONG _BasePri,
		LONG _DeltaPri
	) :
		ID(_ID),
		BasePri(_BasePri),
		DeltaPri(_DeltaPri)
	{}
};

struct ProcessList {
	__ProcessInfo pInfo;
	std::vector<__ModuleInfo> mInfo;
	std::vector<__ThreadInfo> thInfo;

	ProcessList
	(
		__ProcessInfo _pInfo
	) :
		pInfo(_pInfo)
	{}

	ProcessList
	(
		__ProcessInfo _pInfo,
		std::vector<__ModuleInfo> _mInfo,
		std::vector<__ThreadInfo> _thInfo
	) : 
		pInfo(_pInfo),
		mInfo(_mInfo),
		thInfo(_thInfo)
	{}
};

class Process {

	public: std::vector<ProcessList> list;
			
	public:	Process() { }
			void GetMainProcessInfo();
			void GetFullProcessInfo();
			
			void PrintMainInfo();
			void PrintFullInfo();


	private: const short TAB = 15;
			 const short STR_TAB = 50;

			 int numProcessors;

	private: std::vector<__ModuleInfo> ListProcessModules(DWORD dwPID);
			 std::vector<__ThreadInfo> ListProcessThreads(DWORD dwOwnerPID);
};

#endif //__PROCESS_H