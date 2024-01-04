#include "pch.h"
#include "framework.h"
#include "MFC_memo.h"
#include "MFC_memoDlg.h"
#include "afxdialogex.h"
#include "CMFCFindDlg.h"

BEGIN_MESSAGE_MAP(CMFCFindDlg, CDialogEx)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

CMFCFindDlg::CMFCFindDlg() : CDialogEx(IDD_FIND_DIALOG)
{
}

void CMFCFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX); // �ַ� �����Ϳ� ��Ʈ�ѵ� ���� ���� ��ȯ�� ����ϴ� ����
}

void CMFCFindDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RETURN:
		GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
		break;
	case VK_ESCAPE:
		mStr = "";
		break;
	default:
		break;
	}

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CMFCFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	mStr = "";

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BOOL CMFCFindDlg::PreTranslateMessage(MSG* pMsg) // Ŭ������ ��� �̺�Ʈ�� ���� �޽����� �� ������ ����
{
	switch (pMsg->message) 
	{
	case WM_KEYDOWN: // Ű�� �������� Ȯ��
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
			EndDialog(IDOK); // 
			break;
		case VK_ESCAPE:
			mStr = "";
			EndDialog(IDCANCEL);
			break;
		default:
			break;
		}
	default:
		break;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
