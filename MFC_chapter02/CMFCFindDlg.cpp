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
	CDialogEx::DoDataExchange(pDX); // 주로 데이터와 컨트롤들 간의 정보 교환을 담당하는 역할
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
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CMFCFindDlg::PreTranslateMessage(MSG* pMsg) // 클래스의 모든 이벤트에 대한 메시지가 다 들어오는 관문
{
	switch (pMsg->message) 
	{
	case WM_KEYDOWN: // 키가 눌렀는지 확인
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
