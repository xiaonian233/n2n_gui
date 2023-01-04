#pragma once


// CAddRouteDlg �Ի���

class CAddRouteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddRouteDlg)

public:
	CAddRouteDlg(CWnd* pParent = NULL);   // ��׼���캯��
	CAddRouteDlg(char const *_NetAddr, UCHAR const *_Gate, char const *_Note, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddRouteDlg();

// �Ի�������
	enum { IDD = IDD_ADD_ROUTE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_Note;
	char NetAddr[22];
	UCHAR GATE[4],IP[4],Mask;
	bool bEditFlag;
	afx_msg void OnBnClickedOk();
};
