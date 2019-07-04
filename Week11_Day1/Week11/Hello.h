class CMyApp : public CWinApp
{
public:
    virtual BOOL InitInstance ();
};

class CMainWindow : public CFrameWnd
{
public:
    CMainWindow ();

protected:
    afx_msg void OnPaint ();

	//직접 핸들러 추가해보기
	void OnLButtonDown(UINT flagas, CPoint point);

    DECLARE_MESSAGE_MAP ()
};

