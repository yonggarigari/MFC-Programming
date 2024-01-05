// CmfcReplace.cpp: 구현 파일
//

#include "pch.h"
#include "mfcMemo.h"
#include "afxdialogex.h"
#include "CmfcReplace.h"


// CmfcReplace 대화 상자

IMPLEMENT_DYNAMIC(CmfcReplace, CDialogEx)

CmfcReplace::CmfcReplace(CWnd* pParent /*=nullptr*/) // 클래스의 생성자는 객체화만 실시. 객체화와 콘트롤들을 다른 것. 객체에 콘트롤을 설정해줘야 함.
	: CDialogEx(IDD_REPLACE_DIALOG, pParent)
{
	mStrFind = "";	 // 생성자 실행시 맴버변수 초기화
	mStrReplace = "";
}

BOOL CmfcReplace::OnInitDialog() // 생성자에서 초기화 와의 차이: 다이얼로그와 관련된 각종 콘트롤들을 해당 함수에서 초기화 진행.
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


CmfcReplace::~CmfcReplace()
{
}

void CmfcReplace::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CmfcReplace, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_END, &CmfcReplace::OnBnClickedButtonEnd)
END_MESSAGE_MAP()


BOOL CmfcReplace::PreTranslateMessage(MSG* pMsg)
{
	switch (pMsg->message) { // 다이얼로그-> 메시지
	case WM_KEYDOWN:
		switch (pMsg->wParam) { // 메시지 -> 매개변수
		case VK_ESCAPE:
			EndDialog(IDCANCEL); // EndDialog의 시점에서 종료가 되는 것은 아니고 '종료예약' 같은 개념. 실제로 종료가 되는 시점은 함수가 종료될 때 종료된다. 그래서 'break' 사용해야 함.
			// 메시지라든지 함수 내에서 여러가지 동작을 했다고 가정(출력 = 컨트롤에 텍스트를 대입)하면 바로 실행되는게 아님.
			break;
		case VK_RETURN:
			OnBnClickedButtonEnd(); // 처리기를 함수처럼 사용 가능.
			//GetDlgItem(IDC_EDIT_FIND1)->GetWindowText(mStrfind);
			//GetDlgItem(IDC_EDIT_REPLACE1)->GetWindowText(mStrReplace);
			//EndDialog(IDOK);
			break;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CmfcReplace::OnBnClickedButtonEnd() // 해당함수는 OS에서 출력됨.
{
	GetDlgItem(IDC_EDIT_FIND1)->GetWindowText(mStrFind);
	GetDlgItem(IDC_EDIT_REPLACE1)->GetWindowText(mStrReplace);
	EndDialog(IDOK);
}



