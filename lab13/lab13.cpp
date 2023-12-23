// lab13.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "lab13.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB13, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB13));

    MSG msg;

    // Main message loop:
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB13));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB13);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

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
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
void Image0(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 5, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        cx,        	cy + 20,
        cx + 20,	cy - 20,
        cx - 20,   	cy - 20,
        cx,        	cy + 20
    };
    Polyline(hdc, p, 4);

    DeleteObject(hPen);
}


void Image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        cx,      	cy - 20,
        cx + 20,	cy + 20,
        cx - 20, 	cy + 20,
        cx,     	cy - 20
    };
    Polyline(hdc, p, 4);

    DeleteObject(hPen);
}
void Image2(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);

    POINT p[5] = {
        cx,      	cy - 20,
        cx + 20,	cy,
        cx, 	cy + 20,
        cx - 20, 	cy,
        cx,     	cy - 20
    };
    Polyline(hdc, p, 5);

    DeleteObject(hPen);
}

void Image3(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);

    POINT p[5] = {
        cx,      	cy,
        cx + 20,	cy - 20,
        cx, 	cy + 20,
        cx - 20, 	cy - 20,
        cx,     	cy
    };
    Polyline(hdc, p, 5);

    DeleteObject(hPen);
}

void Image5(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);

    POINT p[6] = {
        cx,      	cy,
        cx + 20,	cy - 20,
        cx + 20, 	cy + 20,
        cx - 20, 	cy + 20,
        cx - 20, 	cy - 20,
        cx,     	cy
    };
    Polyline(hdc, p, 6);

    DeleteObject(hPen);
}

void PictureV(HDC hdc) {
    int x, y, i;

    x = 100;
    y = 50;
    i = 0;
    do {

        Image0(hdc, x, y, RGB(0, 255, 0));
        y += 70;

        i++;
    } while (i < 6);
}
void PictureH(HDC hdc) {
    int x, y, j;

    x = 100;
    y = 50;
    j = 0;
    do {

        Image0(hdc, x, y, RGB(255, 0, 0));
        x += 50;

        j++;
    } while (j < 8);
}

void gradient(HDC hdc)
{
    int i = 1, j = 2;
    int x = 50, y = 70;
    while (i < 10)
    {
        j = 2;
        while (j < 13)
        {
            Image0(hdc, j * x, i * y, RGB(10 * (j - 2), 10 * i, 0));
            j++;
        }
        i++;

    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Parse the menu selections:
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

        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //PictureH(hdc);
        gradient(hdc);

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

// Message handler for about box.
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
