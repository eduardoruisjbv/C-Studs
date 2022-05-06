#include    <windows.h>   // Biblioteca de pacotes do Windows
#include    <stdio.h>  // Biblioteca Sensorial do sistema, é aqui que identifica que voce está num teclado e num mouse ou celular com touchscreen e etc...
#include    <stdlib.h> // Biblioteca responsavel por alocação de memoria e processamento de dados armazenados
#include    <string.h> // Biblioteca de Textos
#include    <math.h>   // Bibliteca para soluções matematicas
#include    <iostream> // Biblioteca com Funcionamento parecido da junção de <stdio.h> e <stdlib.h> porem funciona com alocação de Buffers do sistema
#include    <cstdio>   // Biblioteca com mais moderna de <stdio.h>
#include    <ctype.h> // Biblioteca que permite a ultilização do Toupper
#include    <conio.h> // Biblioteca de manipulação de caracteres


//UNIVERSIDADE DE ENSINO SUPERIOR CIENCIA DE DADOS UNIFEOB
//ESSE CODIGO FOI ESCRITO POR CARLOS EDUARDO RUI PARA FINS ACADEMICOS
//CONTATO eduardoruisjbv@outlook.com / eduardoruisjbv@gmail.com


LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);      //Daqui até o proximo comentario é apenas carregando os icones e interface

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "WindowsApp";
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);

    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx (&wincl))
        return 0;

    hwnd = CreateWindowEx (
        0,
        "WindowsApp",
        "Calculadora",
        WS_OVERLAPPEDWINDOW,
        350,
        250,
        300,
        100,
        HWND_DESKTOP,
        NULL,
        hThisInstance,
        NULL
        );

    ShowWindow (hwnd, nFunsterStil);

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

#define ID_BUTTONmais 1001
#define ID_BUTTONmenos 1002
#define ID_BUTTONvezes 1003
#define ID_BUTTONdividir 1004

HINSTANCE g_inst;
HWND EditNum1,EditNum2,EditTotal,ButtonMais,ButtonMenos,ButtonVezes,ButtonDividir;

void DesenharObjectos(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    EditNum1 = CreateWindowEx (
        WS_EX_CLIENTEDGE,
        "EDIT",
        "5",
        WS_VISIBLE|WS_CHILD|WS_BORDER|ES_RIGHT ,
        30, 30, 50, 20,
        hwnd,
        NULL,
        g_inst,
        NULL
        );

    EditNum2 = CreateWindowEx (
        WS_EX_CLIENTEDGE,"EDIT", "3",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        160, 30, 50, 20,
        hwnd, NULL, g_inst, NULL );

    EditTotal = CreateWindowEx (
        WS_EX_CLIENTEDGE,"EDIT", "",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        220, 30, 50, 20,
        hwnd, NULL, g_inst, NULL );

    ButtonMais = CreateWindowEx (
        0,
        "BUTTON",
        "+",
        WS_VISIBLE|WS_CHILD,
        80, 30, 20, 20,
        hwnd,
        (HMENU)ID_BUTTONmais,
        g_inst,
        NULL
        );

    ButtonMenos = CreateWindowEx (
        0, "BUTTON", "-",
        WS_VISIBLE|WS_CHILD,
        100, 30, 20, 20,
        hwnd, (HMENU)ID_BUTTONmenos, g_inst, NULL);

    ButtonVezes = CreateWindowEx (
        0, "BUTTON", "*",
        WS_VISIBLE|WS_CHILD,
        120, 30, 20, 20,
        hwnd, (HMENU)ID_BUTTONvezes, g_inst, NULL);

    ButtonDividir = CreateWindowEx (
        0, "BUTTON", "/",
        WS_VISIBLE|WS_CHILD,
        140, 30, 20, 20,
        hwnd, (HMENU)ID_BUTTONdividir, g_inst, NULL);

    CreateWindowEx (
        0,
        "STATIC",
        "=",
        WS_VISIBLE|WS_CHILD,
        212, 31, 5, 20,
        hwnd,
        NULL,
        g_inst,
        NULL
        );

    SendMessage((HWND) EditNum1,
        (UINT) WM_SETFONT,
        (WPARAM) GetStockObject(DEFAULT_GUI_FONT),
        (LPARAM) lParam
        );

    SendMessage((HWND) EditNum2,(UINT) WM_SETFONT, (WPARAM) GetStockObject(DEFAULT_GUI_FONT),(LPARAM) lParam);
    SendMessage((HWND) EditTotal,(UINT) WM_SETFONT, (WPARAM) GetStockObject(DEFAULT_GUI_FONT),(LPARAM) lParam);

    SendMessage(
        (HWND) ButtonMais,
        (UINT) WM_SETFONT,
        (WPARAM) GetStockObject(DEFAULT_GUI_FONT),
        (LPARAM) lParam
        );

    SendMessage((HWND) ButtonMenos,(UINT) WM_SETFONT, (WPARAM) GetStockObject(DEFAULT_GUI_FONT),(LPARAM) lParam);
    SendMessage((HWND) ButtonVezes,(UINT) WM_SETFONT, (WPARAM) GetStockObject(DEFAULT_GUI_FONT),(LPARAM) lParam);
    SendMessage((HWND) ButtonDividir,(UINT) WM_SETFONT, (WPARAM) GetStockObject(DEFAULT_GUI_FONT),(LPARAM) lParam);
}

char s_valor1[20] = "0", s_valor2[20] = "0", s_total[20] = "0";
int valor1, valor2, total;

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_CREATE:
            DesenharObjectos(hwnd,message,wParam,lParam);
        break;
        case WM_COMMAND:

            if ((HIWORD(wParam) == BN_CLICKED))
            {

                SendMessage(
                    (HWND) EditNum1,
	                (UINT) EM_GETLINE,
	                (WPARAM) 1,
	                (LPARAM) &s_valor1
                    );

                SendMessage((HWND)EditNum2,(UINT)EM_GETLINE,(WPARAM)1,(LPARAM) &s_valor2);

               	valor1 = atoi(s_valor1);
                valor2 = atoi(s_valor2);

                switch (LOWORD(wParam))     // Daqui em diante são os calculos com interação dos botões
                {
                    case ID_BUTTONmais:
                        total = valor1+valor2;
                    break;
                    case ID_BUTTONmenos:
                        total = valor1-valor2;
                    break;
                    case ID_BUTTONvezes:
                       total = valor1*valor2;
                    break;
                    case ID_BUTTONdividir:
                        total = valor1 / valor2;
                    break;
                }

                itoa (total,s_total,10);

                SendMessage(
	                (HWND) EditTotal,
	                (UINT) WM_SETTEXT,
	                (WPARAM) 0,
	                (LPARAM) &s_total
                    );

            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);
        break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}
