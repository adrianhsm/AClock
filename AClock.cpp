// AClock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <Windows.h>
using namespace std;
using namespace std::chrono;

const std::string getCurrentSystemTime()
{
	auto t = system_clock::now();
	auto m = duration_cast<milliseconds>(t.time_since_epoch()).count();
	auto mp = m % 1000;
	auto tt = std::chrono::system_clock::to_time_t(t);
	struct tm ptm;
	localtime_s(&ptm,&tt);
	char date[60] = { 0 };
	sprintf_s(date, "%d-%02d-%02d %02d:%02d:%02d %03d",
		(int)ptm.tm_year + 1900, (int)ptm.tm_mon + 1, (int)ptm.tm_mday,
		(int)ptm.tm_hour, (int)ptm.tm_min, (int)ptm.tm_sec, mp);
	return std::string(date);
}

int _tmain(int argc, _TCHAR* argv[])
{
	while (true){
		cout << getCurrentSystemTime().c_str() << '\r';
		Sleep(10);
	}

	return 0;
}

