#pragma once


// CAddServerDlg �Ի���

class CAddServerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddServerDlg)

public:
	CAddServerDlg(CWnd* pParent = NULL);   // ��׼���캯��
	CAddServerDlg(char const *_ServerAddr, int ver, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddServerDlg();

// �Ի�������
	enum { IDD = IDD_ADDSERVER_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CString m_Edit;
	int m_Ver;
};
