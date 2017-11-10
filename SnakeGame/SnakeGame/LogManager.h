#pragma once

#include "DefineManager.h"
#include <iostream>
#include <cstring>
using namespace std;

static class LogManager
{
public:
	LogManager();
	static void PrintMessage(CString className, CString methodName, CString message, int logLevel);
	~LogManager();
};

