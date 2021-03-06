// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

#define  _CRT_SECURE_NO_WARNINGS
#define	 DLL_SOUI
#include <souistd.h>
#include <core/SHostDialog.h>
#include <control/SMessageBox.h>
#include <control/souictrls.h>
#include <res.mgr/sobjdefattr.h>
#include <com-cfg.h>
#include <SouiFactory.h>

#define SCOM_MASK 0xfffffff		//使用SOUI静态库时，可以使用这个mask来指定加载哪些库。
#include <event/SNotifyCenter.h>
#include <helper/SDpiHelper.hpp>

#include <string>
#include <memory>

#include "trayicon/SShellTray.h"
#include "resource.h"
#define R_IN_CPP	//定义这个开关来
#include "res\resource.h"
using namespace SOUI;

