
// n2n_gui.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


extern char ProPath[];
char *Itoa(int n, char *str);
//char *IpToStrip(UCHAR const *ip, char *str);
//bool StripToIp(char const *str, UCHAR *ip);
//bool StrNetaddrToIp(char const *str, UCHAR *ip, UCHAR *mask);
char *MaskBitToStr(int Mask, char *str);

//BOOL RegSN(char const *sn);
//extern BOOL isReg;

// Cn2n_guiApp:
// �йش����ʵ�֣������ n2n_gui.cpp
//

class Cn2n_guiApp : public CWinApp
{
public:
	Cn2n_guiApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cn2n_guiApp theApp;