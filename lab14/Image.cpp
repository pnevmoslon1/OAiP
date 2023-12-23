#include "Image.h"

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

void Auto(HDC hdc, int x, int y)
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
    DeleteObject(hPen);
}