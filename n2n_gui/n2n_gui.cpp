
// n2n_gui.cpp : 定义应用程序的类行为。
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


// Cn2n_guiApp 构造
Cn2n_guiApp::Cn2n_guiApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 Cn2n_guiApp 对象

Cn2n_guiApp theApp;


// Cn2n_guiApp 初始化

BOOL Cn2n_guiApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	//注册查询
	//isReg = CheckReg(ReadSN(ProPath));
	//获取软件路径
	DWORD n=GetModuleFileName(NULL,ProPath,sizeof(ProPath));
	char *p=strrchr(ProPath,'\\');
	if (p) *p=0;

	Cn2n_guiDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

