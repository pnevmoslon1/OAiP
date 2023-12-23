// lab9.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "lab9.h"

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
    LoadStringW(hInstance, IDC_LAB9, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB9));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB9));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB9);
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
void StClausAuto(HDC hdc, int x, int y) 
{

    // верхний треугольник
    MoveToEx(hdc, x + 20, y + 0, NULL);
    LineTo(hdc, x + 30, y + 20);
    LineTo(hdc, x + 10, y + 20);
    LineTo(hdc, x + 20, y + 0);

    // средний треугольник
    MoveToEx(hdc, x + 20, y + 10, NULL);
    LineTo(hdc, x + 30, y + 40);
    LineTo(hdc, x + 10, y + 40);
    LineTo(hdc, x + 20, y + 10);

    // нижний треугольник
    MoveToEx(hdc, x + 20, y + 30, NULL);
    LineTo(hdc, x + 40, y + 80);
    LineTo(hdc, x + 0, y + 80);
    LineTo(hdc, x + 20, y + 30);
}
void drawTruck(HDC hdc, int x, int y)
{
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 0 + x, 30 + y, 40 + x, 50 + y);
    Rectangle(hdc, 10 + x, 10 + y, 40 + x, 30 + y);
    Rectangle(hdc, 40 + x, y, 100 + x, 50 + y);

    hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 10 + x, 40 + y, 30 + x, 60 + y);
    Ellipse(hdc, 70 + x, 40 + y, 90 + x, 60 + y);
}
void SCLogo(HDC hdc) {
    int i = 0;
    while (i <= 10)
    {
        StClausAuto(hdc, i * 75, 0);
        i++;
    }
    i = 0;
    while (i <= 5)
    {
        StClausAuto(hdc, 0, i * 100);
        i++;
    }

    i = 0;
    while (i <= 5)
    {
        StClausAuto(hdc, i * 75, i * 100);
        i++;
    }

    /*StClausAuto(hdc, 0, 0);
    StClausAuto(hdc,500, 0);
    StClausAuto(hdc,0, 500);
    StClausAuto(hdc, 500, 500);*/
}

void drawTrucks1(HDC hdc)
{
    int i = 0;
    while (i <= 10)
    {
        drawTruck(hdc, i * 110, 0);
        i++;
    }
}
void drawTrucks2(HDC hdc)
{
    int i = 0;
    while (i <= 7)
    {
        drawTruck(hdc, 0, i * 75);
        i++;
    }
}
void drawTrucks3(HDC hdc)
{
    int i = 0;
    while (i <= 7)
    {
        drawTruck(hdc, i * 100, i * 75);
        i++;
    }
}
void Logo(HDC hdc, int x, int y)
{
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(200, 0, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x, y + 106, NULL);
    LineTo(hdc, x + 19, y + 73);
    LineTo(hdc, x + 59, y + 73);
    LineTo(hdc, x + 39, y + 37);
    LineTo(hdc, x + 60, y + 2);
    LineTo(hdc, x + 81, y + 36);
    LineTo(hdc, x + 60, y + 73);
    LineTo(hdc, x + 102, y + 73);
    LineTo(hdc, x + 120, y + 106);
    LineTo(hdc, x + 80, y + 106);
    LineTo(hdc, x + 60, y + 73);
    LineTo(hdc, x + 40, y + 106);
    LineTo(hdc, x , y + 106);
    

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
            // TODO: Add any drawing code that uses hdc here...
            
           /* SCLogo(hdc);
            drawTruck(hdc, 0, 0);
            drawTrucks1(hdc);*/
            //drawTrucks2(hdc);
            drawTrucks3(hdc);
            //Logo(hdc, 0, 0);
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
