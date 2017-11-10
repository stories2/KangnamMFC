#include "stdafx.h"
#include "LogManager.h"

LogManager::LogManager()
{
}

void LogManager::PrintMessage(CString className, CString methodName, CString message, int logLevel)
{
	switch (logLevel)
	{
	case LOG_LEVEL_VERBOSE:
		wcout << "V: { " << className.GetString() << " } [ " << methodName.GetString() << " ] ( " << message.GetString() << " )" << endl;
		break;
	case LOG_LEVEL_INFO:
		wcout << "I: { " << className.GetString() << " } [ " << methodName.GetString() << " ] ( " << message.GetString() << " )" << endl;
		break;
	case LOG_LEVEL_DEBUG:
		wcout << "D: { " << className.GetString() << " } [ " << methodName.GetString() << " ] ( " << message.GetString() << " )" << endl;
		break;
	case LOG_LEVEL_WARN:
		wcout << "W: { " << className.GetString() << " } [ " << methodName.GetString() << " ] ( " << message.GetString() << " )" << endl;
		break;
	case LOG_LEVEL_ERROR:
		wcout << "E: { " << className.GetString() << " } [ " << methodName.GetString() << " ] ( " << message.GetString() << " )" << endl;
		break;
	default:
		break;
	}
}


LogManager::~LogManager()
{
}
