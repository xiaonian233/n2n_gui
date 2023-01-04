
// n2n_guiDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
//#include "SetDlg.h"
#include "colorstatic.h"
#include "resource.h"
#include <windows.h>

#define ON_SHOWLOG_MSG			(WM_USER+1)
#define ON_NOTIFY_ICON_MSG		(WM_USER+2)
//#define ON_REGOK_MSG			(WM_USER+3)


//struct SERVER_ROUTE_Struct
//{
//	bool	Enable;
//	char	Net[19];
//	char	Gate[16];
//	char	Note[16];
//};
struct NetAdapters_Struct
{
	int Index;
	char Name[64];
	char Description[64];
	char IpAddr[16];
};
struct SERVER_Struct 
{
	//char	CName[32];
	char	Server[128];
	char	NetName[64];
	char	NetPasswd[32];
	char	IpAddr[20];
	//int		RouteCnts;
	enum    N2NVER_ENUM{N2N_V2=0,N2N_V3}N2N_Ver;
	//SERVER_ROUTE_Struct *pRouteList;
};


// Cn2n_guiDlg �Ի���
class Cn2n_guiDlg : public CDialogEx
{
// ����
public:
	Cn2n_guiDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_N2N_GUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CListCtrl m_List;
	afx_msg void OnBnClickedBtnStartStop();
	void ShowSelServer(SERVER_Struct const * pServer);
	afx_msg void OnCbnSelchangeComboServerlist();
	afx_msg void OnBnClickedBtnDelServer();
	afx_msg void OnBnClickedBtnAddServer();
	afx_msg void OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult);

	CArray<SERVER_Struct,SERVER_Struct&>	ServerArray;
	//void SetRoute(bool bEnable);
	virtual void OnCancel();

	afx_msg void OnBnClickedBtnSave();

	HANDLE hClientProcess, hClientRead;
	//WinIPBoard
	HANDLE hWinIPBoard;
	//WinIPBoard
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CColorStatic m_ConnectStatus;

	HICON m_Icon_Connected, m_Icon_NoConnect, m_Icon_ConnectErr;

	NOTIFYICONDATA	m_Nid;
	LRESULT OnNotifyIconMsg(WPARAM w, LPARAM l);
	void OnMenuClickedShow(void);
	int SystemBits,SystemVersion;
	afx_msg void OnBnClickedBtnEditServer();
	//void OnMenuClickedAddRoute(void);
	//void OnMenuClickedDelRoute(void);
	//void OnMenuClickedEditRoute(void);
	UINT ConnectTick;
	//afx_msg void OnBnClickedBtnSet();
	//bool bAutoHide, bAutoConnect;
	bool bAutoGet;
	int N2nVerSel;
	//BOOL bReSend;
	//CString m_OtherParam;
	CEdit m_Log;
	LRESULT OnShowLogMsg(WPARAM w, LPARAM l);
	afx_msg void OnBnClickedBtnClrLog();
	void InstallWintap();
	bool StartEdge();
	void StopN2n();
	afx_msg void OnStnClickedIpadd();
};
