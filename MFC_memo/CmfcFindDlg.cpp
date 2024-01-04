#include "pch.h"
#include "framework.h"
#include "mfcMemo.h"
#include "mfcMemoDlg.h"
#include "afxdialogex.h"
#include "CmfcFindDlg.h"
BEGIN_MESSAGE_MAP(CmfcFindDlg, CDialogEx)
	ON_WM_KEYDOWN()
	ON_EN_CHANGE(ID_EDIT_FIND, &CmfcFindDlg::OnEnChangeEditFind)
END_MESSAGE_MAP()

CmfcFindDlg::CmfcFindDlg() : CDialogEx(IDD_FIND_DIALOG)
{
}

void CmfcFindDlg::DoDataExchange(CDataExchange* pDX)    // DDX/DDV 지원입니다.
{
	CDialogEx::DoDataExchange(pDX); // 주로 데이터와 컨트롤들 간의 정보 교환을 담당하는 역할
}

void CmfcFindDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
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


BOOL CmfcFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	mStr = "";

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CmfcFindDlg::PreTranslateMessage(MSG* pMsg) // 클래스의 모든 이벤트에 대한 메시지가 다 들어오는 관문
{
	switch (pMsg->message)
	{
	case WM_KEYDOWN: // 키가 눌렀는지 확인
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
			EndDialog(IDOK);
			break;
		case VK_ESCAPE:
			mStr = "";
			EndDialog(IDCANCEL);
			break;
		default:
			break;
		}
		break;
	default: 
		break;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CmfcFindDlg::OnEnChangeEditFind()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
