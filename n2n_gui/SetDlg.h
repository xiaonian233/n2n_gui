#pragma once

struct NetAdapters_Struct
{
	int Index;
	char Name[64];
	char Description[64];
};

// CSetDlg �Ի���

class CSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetDlg)

public:
	CSetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	CSetDlg(bool _Hide, bool _Connect, bool _Resend, char const *_Param, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetDlg();

// �Ի�������
	enum { IDD = IDD_SET_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	bool bHide,bConnect;
	bool bReSend;
	CString m_OtherParam;
	int AdaptersCnt;
	NetAdapters_Struct *pAdapters;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
