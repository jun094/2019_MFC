#include <windows.h> // 헤더파일이 다름

LONG WINAPI WndProc (HWND, UINT, WPARAM, LPARAM);

// WinMain 메인함수이름이 변경
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	//여기서부터
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;

	wc.style = 0;                                   
	wc.lpfnWndProc = (WNDPROC) WndProc;             
	wc.cbClsExtra = 0;                              
	wc.cbWndExtra = 0;                              
	wc.hInstance = hInstance;                       
	wc.hIcon = LoadIcon (NULL, IDI_WINLOGO);        
	wc.hCursor = LoadCursor (NULL, IDC_ARROW);      
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1); 
	wc.lpszMenuName = NULL;                         
	wc.lpszClassName = "MyWndClass";                

	RegisterClass (&wc);	
	//여기까지 무시

	hwnd = CreateWindow (
		"MyWndClass",               // WNDCLASS name
		"SDK Application",          // Window title
		WS_OVERLAPPEDWINDOW,        // Window style
		CW_USEDEFAULT,              // Horizontal position
		CW_USEDEFAULT,              // Vertical position        
		CW_USEDEFAULT,              // Initial width
		CW_USEDEFAULT,              // Initial height
		HWND_DESKTOP,               // Handle of parent window
		NULL,                       // Menu handle
		hInstance,                  // Application's instance handle
		NULL                        // Window-creation data
		);

	ShowWindow (hwnd, nCmdShow);
	UpdateWindow (hwnd);

	// 결과적으로 보이는건 while문 하나
	while (GetMessage (&msg, NULL, 0, 0)) { //GetMessage 은 cin같은것 -> msg를 받음
		TranslateMessage (&msg); // 
		DispatchMessage (&msg); //밑에 WndProc를 부르는 함수 
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, // 여기가 이벤트 헨들러 부분
	LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {

	case WM_LBUTTONDOWN: // 마우스 왼쪽 클릭하면
		MessageBox(hwnd, "haha!","Test!",MB_OK); // 창을 띄울꺼야
		break;

	case WM_KEYDOWN: // 키보드 클릭하면
		MessageBox(hwnd, "haha!","Test!",MB_OK); // 창을 띄울꺼야
		break;

	case WM_PAINT: // WM(Window Message) , 그리라는 메세지가 오면 -> 우리가 바꿀부분은 여기!!!!
		hdc = BeginPaint (hwnd, &ps);
		Ellipse (hdc, 0, 0, 200, 100); // 타원(Ellipse)을 그려

		RECT rect;
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "hello, Windows", -1, &rect,
			DT_SINGLELINE|DT_CENTER|DT_VCENTER); // 항상 가운데에  hello, Windows 를 출력하는 함수

		EndPaint (hwnd, &ps);

		return 0;

	case WM_DESTROY: // 프로그램 종료하라는 메세지가 오면
		PostQuitMessage (0);
		return 0;
	}
	return DefWindowProc (hwnd, message, wParam, lParam);
}
