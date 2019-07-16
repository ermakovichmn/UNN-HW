// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static HPEN hpen1;
	static HBRUSH hb1;
	HBRUSH hbс = CreateSolidBrush(RGB(169, 169, 169));
	static const int n = 2;
	static double m[3], M, ax[3], ay[3], vx[3], vy[3], x[3], y[3], R, G, w, r, t, dt, GM, r1,r2,r3, d;
	static int  xscr[3], yscr[3], xscr_0, yscr_0, coef, rad, rad1;




    switch (message)
    {
    case WM_COMMAND:
        {




	case WM_CREATE:
		d = 2;
		M =10* M_PI*M_PI;
		m[0] = 0.5;
		m[1] = 0.5 ;
		m[2] = 0.5 ;


		x[0] =1;
		y[0] =0;

		x[1] = 0;
		y[1] = 2;

		x[2] = 2;
		y[2] = 2;

		vx[0] = 0;
		vy[0] = -4 * M_PI;

		vx[1] = 2 * M_PI;
		vy[1] = 0;

		vx[2] = M_PI;
		vy[2] =  -M_PI;
		t = 0;

		dt = 0.005;
		xscr_0 = 400;
		yscr_0 = 400;
		coef = 100;
		rad = 10;
		rad1 = 5;
		SetTimer(hWnd, 1, 2, NULL);
		std::cout << ax[1];
		break;
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, TRUE);
		break;





            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
		hdc = BeginPaint(hWnd, &ps);


		
		
		
		
			r = sqrt(x[0] * x[0] + y[0] * y[0]);
			r1 = sqrt((x[0] - x[1])*(x[0] - x[1])+ (y[0] - y[1])*(y[0] - y[1]));
			r2 = sqrt((x[0] - x[2])*(x[0] - x[2]) + (y[0] - y[2])*(y[0] - y[2]));
			

			ax[0] = -(M*x[0]) / (r*r*r)-(m[1]*(x[0]-x[1])/(r1*r1*r1)) - (m[2] * (x[0] - x[2]) / (r2*r2*r2));
			ay[0] = -(M*y[0]) / (r*r*r)-(m[1] * (y[0] - y[1]) / (r1*r1*r1)) - (m[2] * (y[0] - y[2]) / (r2*r2*r2));
			vx[0] += ax[0] * dt;
			vy[0] += ay[0] * dt;
			x[0] += vx[0] * dt;
			y[0] += vy[0] * dt;

			xscr[0] = xscr_0 + x[0] * coef;
			yscr[0] = yscr_0 + y[0] * coef;

			r = sqrt(x[1] * x[1] + y[1] * y[1]);
			r1 = sqrt((x[1] - x[0])*(x[1] - x[0]) + (y[1] - y[0])*(y[1] - y[0]));
			r2 = sqrt((x[1] - x[2])*(x[1] - x[2]) + (y[1] - y[2])*(y[1] - y[2]));

			ax[1] = -(M*x[1]) / (r*r*r) - (m[0] * (x[1] - x[0]) / (r1*r1*r1)) - (m[2] * (x[1] - x[2]) / (r2*r2*r2));
			ay[1] = -(M*y[1]) / (r*r*r) - (m[0] * (y[1] - y[0]) / (r1*r1*r1)) - (m[2] * (y[1] - y[2]) / (r2*r2*r2));
			vx[1] += ax[1] * dt;
			vy[1] += ay[1] * dt;
			x[1] += vx[1] * dt;
			y[1] += vy[1] * dt;

			xscr[1] = xscr_0 + x[1] * coef;
			yscr[1] = yscr_0 + y[1] * coef;

			r = sqrt(x[2] * x[2] + y[2] * y[2]);
			r1 = sqrt((x[2] - x[0])*(x[2] - x[0]) + (y[2] - y[0])*(y[2] - y[0]));
			r2 = sqrt((x[2] - x[1])*(x[2] - x[1]) + (y[2] - y[1])*(y[2] - y[1]));

			ax[2] = -(M*x[2]) / (r*r*r) - (m[1] * (x[2] - x[0]) / (r1*r1*r1)) - (m[2] * (x[2] - x[1]) / (r2*r2*r2));;
			ay[2] = -(M*y[2]) / (r*r*r)-(m[1] * (y[2] - y[0]) / (r1*r1*r1)) - (m[2] * (y[2] - y[1]) / (r2*r2*r2));;
			vx[2] += ax[2] * dt;
			vy[2] += ay[2] * dt;
			x[2] += vx[2] * dt;
			y[2] += vy[2] * dt;

			xscr[2] = xscr_0 + x[2] * coef;
			yscr[2] = yscr_0 + y[2] * coef;



			HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
			HGDIOBJ hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

			Ellipse(hdc, xscr[2] - rad1, yscr[2] - rad1, xscr[2] + rad1, yscr[2] + rad1);
			
			
			Ellipse(hdc, xscr[1] - rad1, yscr[1] - rad1, xscr[1] + rad1, yscr[1] + rad1);

			
			Ellipse(hdc, xscr[0] - rad1, yscr[0] - rad1, xscr[0] + rad1, yscr[0] + rad1);

			
			Ellipse(hdc, xscr_0 - rad, yscr_0 - rad, xscr_0 + rad, yscr_0 + rad);
		
			
			void WINAPI OutputDebugString(
				_In_opt_ LPCTSTR lpOutputString
			);


            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
