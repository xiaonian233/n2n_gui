
// n2n_gui.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "n2n_gui.h"
#include "n2n_guiDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


char ProPath[MAX_PATH];


char *Itoa(int n, char *str)
{
	sprintf_s(str,12,"%d",n);
	return str;
}

char *MaskBitToStr(int Mask, char *str)
{
	unsigned int val = 0;
	if (Mask > 32) return "";

	for (int j = 0; j < Mask; j++)
		val |= (1 << (31 - j));
	sprintf_s(str, 16,"%d.%d.%d.%d", (UCHAR)(val >> 24), (UCHAR)((val >> 16) & 0xff), (UCHAR)((val >> 8) & 0xff), (UCHAR)(val & 0xff));
	return str;
}


// Cn2n_guiApp

BEGIN_MESSAGE_MAP(Cn2n_guiApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Cn2n_guiApp ����
Cn2n_guiApp::Cn2n_guiApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� Cn2n_guiApp ����

Cn2n_guiApp theApp;


// Cn2n_guiApp ��ʼ��

BOOL Cn2n_guiApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	//ע���ѯ
	//isReg = CheckReg(ReadSN(ProPath));
	//��ȡ���·��
	DWORD n=GetModuleFileName(NULL,ProPath,sizeof(ProPath));
	char *p=strrchr(ProPath,'\\');
	if (p) *p=0;

	Cn2n_guiDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

