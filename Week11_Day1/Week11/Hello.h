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

	//���� �ڵ鷯 �߰��غ���
	void OnLButtonDown(UINT flagas, CPoint point);

    DECLARE_MESSAGE_MAP ()
};

