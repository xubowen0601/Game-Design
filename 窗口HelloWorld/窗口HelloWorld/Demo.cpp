#include<Windows.h>				//һ��WindowsӦ�ó���Ӧ�ð�����ͷ�ļ�
#include<stdio.h>				//��׼���������
LRESULT CALLBACK WinSunProc		/*����һ���ص�����*/
(
	HWND hwnd,      			/*���ڵľ��*/
	UINT uMsg,      			/*���ڵ���Ϣ*/
	WPARAM wParam,
	LPARAM lParam
);
/*
WinMain:Windows�������ں���
����һ�������Ĵ�����Ҫ���������ĸ��������裺���һ�������ࣻע�ᴰ���ࣻ�������ڣ���ʾ�����´���
*/
int WINAPI WinMain
(
	HINSTANCE hInstance,     			//ʵ����� ��ǰӦ�ó����ʵ�����
	HINSTANCE hPrevInstance, 			//Ĭ���������ΪNULL
	LPSTR lpCmdLine,          			//����һ�������в���
	int nCmdShow)
{
	WNDCLASS wndcls;				//����һ�����ڶ���
	wndcls.cbClsExtra = 0;			//ָ�������ڴ�ռ�
	wndcls.cbWndExtra = 0;			//ָ�������ڴ�ռ�
	//ָ�����ڱ���ɫ
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//���ù����ʽ
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);
	//����ͼ����ʽ
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = hInstance;		//ָ������ʵ�����
	wndcls.lpfnWndProc = WinSunProc;	//ָ�����ں�������������������
	//����������
	wndcls.lpszClassName = "Visual C++ Game";
	wndcls.lpszMenuName = NULL;		//�˵�
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls); 			//ע�ᴰ���� 
	HWND hwnd;					//�������ھ��
	hwnd = CreateWindow(			/*�������ڣ�������Ĵ����ǲ�����ʾ��*/
		"Visual C++ Game", 				/*��ע�ᴰ���������*/
		"Visual C++ ��Ϸ����",			/*���ڱ���*/
		WS_OVERLAPPEDWINDOW,			/*���ڷ��*/
		200,							/*����λ�õĺ�����*/
		200,							/*����λ�õ�������*/
		600,							/*���ڵĿ��*/
		400,							/*���ڵĸ߶�*/
		NULL,
		NULL,
		hInstance,						/*ʵ�����*/
		NULL);
	//������������ʾ����
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	/*
		��ʼ��������ɺ�WinMain������ν����Ϣѭ��
	*/
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
/*
	���ں��������ں���ͨ������switch/case��ʽ�ж���Ϣ�����࣬
	�Ծ�������ʽ���������Ǳ�Windowsϵͳ�����õģ���������һ��call back����
*/
LRESULT CALLBACK WinSunProc(
	HWND hwnd,							/*���ھ��*/
	UINT uMsg,							/*��Ϣ*/
	WPARAM wParam,						/*����1*/
	LPARAM lParam						/*����2*/
)
{
	switch (uMsg)						/*�ж���Ϣ����*/
	{
	case WM_PAINT:						/*���´�����Ϣ*/
		HDC hDC;						/*����DC�豸*/
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd, &ps);	/*�õ��豸hDC*/
		TextOut(hDC, 200, 0, "Visual C++ ��Ϸ����", strlen("Visual C++ ��Ϸ����"));
		EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:					/*d�������رհ�ťʱ�������ر���Ϣ*/
		if (IDYES == MessageBox(hwnd, "�Ƿ���Ľ�����", "��Ϸ����", MB_YESNO))
		{
			DestroyWindow(hwnd);	/*������ȷ������ť�����ٴ���*/
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		//��default�����������DefWindowProc������Windows�ڲ�Ĭ�ϵ���Ϣ������	
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}