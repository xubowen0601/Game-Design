#include<Windows.h>				//一个Windows应用程序应该包含的头文件
#include<stdio.h>				//标准输入输出流
LRESULT CALLBACK WinSunProc		/*声明一个回调函数*/
(
	HWND hwnd,      			/*窗口的句柄*/
	UINT uMsg,      			/*窗口的消息*/
	WPARAM wParam,
	LPARAM lParam
);
/*
WinMain:Windows程序的入口函数
创建一个完整的窗口需要经过下面四个操作步骤：设计一个窗口类；注册窗口类；创建窗口；显示及更新窗口
*/
int WINAPI WinMain
(
	HINSTANCE hInstance,     			//实例句柄 当前应用程序的实例句柄
	HINSTANCE hPrevInstance, 			//默认这个参数为NULL
	LPSTR lpCmdLine,          			//储存一个命令行参数
	int nCmdShow)
{
	WNDCLASS wndcls;				//定义一个窗口对象
	wndcls.cbClsExtra = 0;			//指定额外内存空间
	wndcls.cbWndExtra = 0;			//指定额外内存空间
	//指定窗口背景色
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//设置光标样式
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);
	//设置图标样式
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = hInstance;		//指定窗口实例句柄
	wndcls.lpfnWndProc = WinSunProc;	//指定窗口函数，即窗口主处理函数
	//窗口类名称
	wndcls.lpszClassName = "Visual C++ Game";
	wndcls.lpszMenuName = NULL;		//菜单
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls); 			//注册窗口类 
	HWND hwnd;					//声明窗口句柄
	hwnd = CreateWindow(			/*创建窗口，但这里的窗口是不会显示的*/
		"Visual C++ Game", 				/*已注册窗口类的名称*/
		"Visual C++ 游戏开发",			/*窗口标题*/
		WS_OVERLAPPEDWINDOW,			/*窗口风格*/
		200,							/*窗口位置的横坐标*/
		200,							/*窗口位置的纵坐标*/
		600,							/*窗口的宽度*/
		400,							/*窗口的高度*/
		NULL,
		NULL,
		hInstance,						/*实例句柄*/
		NULL);
	//在这里真正显示窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	/*
		初始化工作完成后，WinMain进入所谓的消息循环
	*/
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
/*
	窗口函数。窗口函数通常利用switch/case方式判断消息的种类，
	以决定处理方式，由于其是被Windows系统所调用的，所以这是一个call back函数
*/
LRESULT CALLBACK WinSunProc(
	HWND hwnd,							/*窗口句柄*/
	UINT uMsg,							/*消息*/
	WPARAM wParam,						/*参数1*/
	LPARAM lParam						/*参数2*/
)
{
	switch (uMsg)						/*判断消息类型*/
	{
	case WM_PAINT:						/*更新窗口信息*/
		HDC hDC;						/*定义DC设备*/
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd, &ps);	/*得到设备hDC*/
		TextOut(hDC, 200, 0, "Visual C++ 游戏开发", strlen("Visual C++ 游戏开发"));
		EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:					/*d当单击关闭按钮时，产生关闭消息*/
		if (IDYES == MessageBox(hwnd, "是否真的结束？", "游戏开发", MB_YESNO))
		{
			DestroyWindow(hwnd);	/*单击“确定”按钮，销毁窗口*/
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		//在default：处必须调用DefWindowProc，这是Windows内部默认的消息处理函数	
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}