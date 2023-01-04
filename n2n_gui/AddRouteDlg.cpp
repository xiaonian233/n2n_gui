// AddRouteDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "n2n_gui.h"
#include "AddRouteDlg.h"
#include "afxdialogex.h"


// CAddRouteDlg �Ի���

IMPLEMENT_DYNAMIC(CAddRouteDlg, CDialogEx)

CAddRouteDlg::CAddRouteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddRouteDlg::IDD, pParent)
	, m_Note(_T(""))
	, bEditFlag(false)
{

}

CAddRouteDlg::CAddRouteDlg(char const *_NetAddr, UCHAR const *_Gate, char const *_Note, CWnd* pParent)
	: CDialogEx(CAddRouteDlg::IDD, pParent)
{
	m_Note=_Note;
	strncpy_s(NetAddr,sizeof(NetAddr),_NetAddr,sizeof(NetAddr));
	memcpy(GATE,_Gate,4);
	bEditFlag=true;
}

CAddRouteDlg::~CAddRouteDlg()
{
}

void CAddRouteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddRouteDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddRouteDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddRouteDlg ��Ϣ�������


BOOL CAddRouteDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if (bEditFlag)
	{
		SetDlgItemText(IDC_EDIT_NOTE,m_Note);
		SetDlgItemText(IDC_EDIT_NETADDR,NetAddr);
		CIPAddressCtrl *p=(CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS_GATE);
		p->SetAddress(GATE[0],GATE[1],GATE[2],GATE[3]);
		SetWindowText("�༭·��");
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CAddRouteDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT_NOTE,m_Note);
	if (m_Note.GetLength()>15)
	{
		MessageBox("��ע���ȳ����涨ֵ");
		return;
	}

	GetDlgItemText(IDC_EDIT_NETADDR,NetAddr,sizeof(NetAddr));
	if (!StrNetaddrToIp(NetAddr,IP,&Mask))
	{
		MessageBox("���θ�ʽ����");
		return;
	}

	CIPAddressCtrl *p=(CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS_GATE);
	p->GetAddress(GATE[0],GATE[1],GATE[2],GATE[3]);

	CDialogEx::OnOK();
}
