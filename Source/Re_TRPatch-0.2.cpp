#include <Windows.h>
#include <iostream>
#include <fstream>
#include "CommDlg.h"
#include "tchar.h"
using namespace std;
//v0.2
//���ڴ��ļ�
const char* OpenFile()
{
	TCHAR szBuffer[MAX_PATH] = { 0 };
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = _T("exe file(*.exe)\0*.exe\0");
	ofn.lpstrInitialDir = _T("");               // ·��
	ofn.lpstrFile = szBuffer;                   // ����
	ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	ofn.nFilterIndex = 0;
	//��־����Ƕ�ѡҪ����OFN_ALLOWMULTISELECT    
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
	BOOL bSel = GetOpenFileName(&ofn);
	LPWSTR lpwszStrIn = szBuffer;
	LPSTR pszOut = NULL;
	if (lpwszStrIn != NULL)
	{
		int nInputStrLen = wcslen(lpwszStrIn);
		int nOutputStrLen = WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL, 0, 0, 0) + 2;
		pszOut = new char[nOutputStrLen];       //���ܻ�����ڴ�й©  
		if (pszOut)
		{
			memset(pszOut, 0x00, nOutputStrLen);
			WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut, nOutputStrLen, 0, 0);
		}
	}
	return pszOut;
}
int main(int argc, char** argv) {
	int TRV = 0;
	int VCode = 0;
	int a[8] = { 185, 232, 3, 0, 0, 137, 72, 34 };
	int i = 0;
	bool SelectExe = FALSE;
	const int TR2 = 135041;
	const int TR3 = 212513;
	const int TR4 = 336609;
	const int TR5 = 237153;
	const char* path;
	char* pathbak;
	char bak[5] = ".bak";
	HWND hWnd = GetConsoleWindow();
	HFONT font = CreateFont(
		20, // nHeight
		0, // nWidth
		0, // nEscapement
		0, // nOrientation
		FW_NORMAL, // nWeight
		FALSE, // bItalic
		FALSE, // bUnderline
		0, // cStrikeOut
		ANSI_CHARSET, // nCharSet
		OUT_DEFAULT_PRECIS, // nOutPrecision
		CLIP_DEFAULT_PRECIS, // nClipPrecision
		DEFAULT_QUALITY, // nQuality
		DEFAULT_PITCH | FF_SWISS,
		L"΢���ź�" // nPitchAndFamily Arial
		);
	HWND b1 = CreateWindow(
		L"BUTTON",   // predefined class
		L"ѡȡ�ļ�",       // button text
		WS_VISIBLE | WS_CHILD,  //values for buttons.
		50,         // starting x position
		80,         // starting y position
		100,        // button width
		30,        // button height
		hWnd,       // parent window
		0,       // No menu
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);
	HWND b2 = CreateWindow(
		L"BUTTON",   // predefined class
		L"TR2",       // button text
		WS_VISIBLE | WS_CHILD,  //values for buttons.
		200,         // starting x position
		80,         // starting y position
		40,        // button width
		30,        // button height
		hWnd,       // parent window
		0,       // No menu
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);
	HWND b3 = CreateWindow(
		L"BUTTON",   // predefined class
		L"TR3",       // button text
		WS_VISIBLE | WS_CHILD,  //values for buttons.
		270,         // starting x position
		80,         // starting y position
		40,        // button width
		30,        // button height
		hWnd,       // parent window
		0,       // No menu
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);
	HWND b4 = CreateWindow(
		L"BUTTON",   // predefined class
		L"TR4",       // button text
		WS_VISIBLE | WS_CHILD,  //values for buttons.
		340,         // starting x position
		80,         // starting y position
		40,        // button width
		30,        // button height
		hWnd,       // parent window
		0,       // No menu
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);
	HWND b5 = CreateWindow(
		L"BUTTON",   // predefined class
		L"TR5",       // button text
		WS_VISIBLE | WS_CHILD,  //values for buttons.
		410,         // starting x position
		80,         // starting y position
		40,        // button width
		30,        // button height
		hWnd,       // parent window
		0,       // No menu
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);
	HWND b6 = CreateWindow(
		L"BUTTON",   // predefined class
		L"ʹ��˵��",       // button text
		WS_VISIBLE | WS_CHILD,  //values for buttons.
		50,         // starting x position
		150,         // starting y position
		100,        // button width
		30,        // button height
		hWnd,       // parent window
		0,       // No menu
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);
	HWND b7 = CreateWindow(
		L"BUTTON",   // predefined class
		L"��ʼ����",       // button text
		WS_VISIBLE | WS_CHILD,  //values for buttons.
		200,         // starting x position
		150,         // starting y position
		100,        // button width
		30,        // button height
		hWnd,       // parent window
		0,       // No menu
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);
	HWND b8 = CreateWindow(
		L"BUTTON",   // predefined class
		L"�˳�Ӧ��",       // button text
		WS_VISIBLE | WS_CHILD,  //values for buttons.
		350,         // starting x position
		150,         // starting y position
		100,        // button width
		30,        // button height
		hWnd,       // parent window
		0,       // No menu
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);
	SendMessage(b1, WM_SETFONT, (WPARAM)font, 1);
	SendMessage(b2, WM_SETFONT, (WPARAM)font, 1);
	SendMessage(b3, WM_SETFONT, (WPARAM)font, 1);
	SendMessage(b4, WM_SETFONT, (WPARAM)font, 1);
	SendMessage(b5, WM_SETFONT, (WPARAM)font, 1);
	SendMessage(b6, WM_SETFONT, (WPARAM)font, 1);
	SendMessage(b7, WM_SETFONT, (WPARAM)font, 1);
	SendMessage(b8, WM_SETFONT, (WPARAM)font, 1);
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (msg.hwnd == b1 && msg.message == WM_LBUTTONDOWN) {
			system("CLS");
			path = OpenFile();
			if (strcmp(path, "") != 0){
				SelectExe = TRUE;
				std::cout << "��ѡ��" << path << std::endl;
			}
			else{
				std::cout << "δѡ��exe" << std::endl;
			}
			if (VCode){
				std::cout << "�Ѿ����汾ΪTR" << VCode << std::endl;
			}
		}
		if (msg.hwnd == b2 && msg.message == WM_LBUTTONDOWN) {
			system("CLS");
			TRV = TR2;
			VCode = 2;
			std::cout << "�Ѿ����汾ΪTR2" << std::endl;
			if (SelectExe){
				std::cout << "��ѡ��exeΪ" << path << std::endl;
			}
		}
		if (msg.hwnd == b3 && msg.message == WM_LBUTTONDOWN) {
			system("CLS");
			TRV = TR3;
			VCode = 3;
			std::cout << "�Ѿ����汾ΪTR3" << std::endl;
			if (SelectExe){
				std::cout << "��ѡ��exeΪ" << path << std::endl;
			}
		}
		if (msg.hwnd == b4 && msg.message == WM_LBUTTONDOWN) {
			system("CLS");
			TRV = TR4;
			VCode = 4;
			std::cout << "�Ѿ����汾ΪTR4" << std::endl;
			if (SelectExe){
				std::cout << "��ѡ��exeΪ" << path << std::endl;
			}
		}
		if (msg.hwnd == b5 && msg.message == WM_LBUTTONDOWN) {
			system("CLS");
			TRV = TR5;
			VCode = 5;
			std::cout << "�Ѿ����汾ΪTR5" << std::endl;
			if (SelectExe){
				std::cout << "��ѡ��exeΪ" << path << std::endl;
			}
		}
		if (msg.hwnd == b6 && msg.message == WM_LBUTTONDOWN) {
			//system("CLS");
			MessageBox(hWnd, L"����ѡ������Ҫ�򲹶���exe", L"��һ��", MB_ICONINFORMATION);
			MessageBox(hWnd, L"Ȼ�������ʹ�õ�TR�汾��", L"�ڶ���", MB_ICONINFORMATION);
			MessageBox(hWnd, L"������򲹶����ɡ���Ӧ�ûὫ����exe���ݣ���������Է���ʹ�á�", L"������", MB_ICONINFORMATION);
		}
		if (msg.hwnd == b7 && msg.message == WM_LBUTTONDOWN) {
			system("CLS");
			//�����ļ�
			if (SelectExe && TRV != 0){
				pathbak = new char[strlen(path) + strlen(bak) + 1];
				strcpy_s(pathbak, strlen(path) + strlen(bak) + 1, path);
				strcat_s(pathbak, strlen(path) + strlen(bak) + 1, bak);
				ifstream src(path, ios::binary);
				ofstream dst(pathbak, ios::binary);
				dst << src.rdbuf();
				std::cout << "����Ϊ " << pathbak << "��" << std::endl;
				//��д����
				fstream ouF;
				ouF.open(path, ios::in | ios::out | ios::binary);
				for (i = 0; i < 8; i++)
				{
					ouF.seekp(TRV + i);
					ouF.put(a[i]);
				}
				ouF.close();
				std::cout << "����Ӳ����� " << path << std::endl;
				std::cout << "�汾ΪTR" << VCode << std::endl;
			}
			else if (!SelectExe && TRV != 0){
				std::cout << "��δѡ��exe" << path << std::endl;
				std::cout << "�汾ΪTR" << VCode << std::endl;
			}
			else if (SelectExe && TRV == 0){
				std::cout << "��δѡ��TR�汾" << path << std::endl;
				std::cout << "��ѡ��exeΪ" << path << std::endl;
			}
			else{
				std::cout << "��δѡ��exe��TR�汾" << path << std::endl;
			}
		}
		if (msg.hwnd == b8 && msg.message == WM_LBUTTONDOWN) {
			system("CLS");
			//��ֹ�ڴ����
			if (SelectExe){
				delete[]path;
				delete[]pathbak;
				SelectExe = 0;
			}
			MessageBox(hWnd, L"��л����ʹ��", L"лл", MB_ICONINFORMATION);
			return 0;
		}
	}
}