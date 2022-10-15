#include "MyForm.h"
#include <Windows.h>

//"EN": {"Mouse", "Pause", "Keyboard"}
//"EN": {"Mouse": {"Click", "Hold", "Unhold", "Move"}, "Pause": {"Wait"}, "Keyboard": {"Press", "Hold", "Unhold"}
/*
Mouse: M
Pause: P
Keyboard: K
*/
/*
Click: C
Hold: H
UnHold:U
Move: M
Wait: W
Press: P
*/

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	AutoClicker::Application::EnableVisualStyles();
	AutoClicker::Application::SetCompatibleTextRenderingDefault(false);
	AutoClicker::Application::Run(gcnew AutoClicker::MyForm);
	return 0;
}