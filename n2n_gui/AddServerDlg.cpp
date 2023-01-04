// AddServerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "n2n_gui.h"
#include "AddServerDlg.h"
#include "afxdialogex.h"


// CAddServerDlg �Ի���

IMPLEMENT_DYNAMIC(CAddServerDlg, CDialogEx)

CAddServerDlg::CAddServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddServerDlg::IDD, pParent)
	, m_Edit(_T(""))
	, m_Ver(0)
{
}

CAddServerDlg::CAddServerDlg(char const *_ServerAddr, int ver, CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddServerDlg::IDD, pParent)
{
	m_Edit=_ServerAddr;
	m_Ver = ver;
}

CAddServerDlg::~CAddServerDlg()
{
}

void CAddServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDX_CBIndex(pDX, IDC_COMBO1, m_Ver);
}


BEGIN_MESSAGE_MAP(CAddServerDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddServerDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddServerDlg ��Ϣ�������


void CAddServerDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int n=m_Edit.ReverseFind(':');
	if (n>2)
	{
		CString numberstr=m_Edit.Right(m_Edit.GetLength()-n-1);
		if (atoi(numberstr)>0)
		{
			CDialogEx::OnOK();
			return;
		}
	}
	MessageBox("��ʽ����");
}


BOOL CAddServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if (m_Edit != "")
	{
		SetWindowText("�༭������");
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
