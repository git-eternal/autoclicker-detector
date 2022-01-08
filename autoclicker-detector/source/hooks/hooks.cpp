#include "hooks.hpp"

DWORD WINAPI Hooks::Spawn()
{
	MouseHook = SetWindowsHookExA(WH_MOUSE_LL, [](int nCode, WPARAM wParam, LPARAM lParam) 
	{ 
		static int violations{ 0 };

		if (nCode == HC_ACTION && wParam != WM_MOUSEMOVE)
		{
			MSLLHOOKSTRUCT* mi = { reinterpret_cast<MSLLHOOKSTRUCT*>(lParam) };

			if ((mi->flags & LLMHF_INJECTED) || (mi->flags & LLMHF_LOWER_IL_INJECTED))
			{
				printf("[DETECTION]: Autoclicker detected (VL: %i)\n", ++violations);
			}
		}

		return CallNextHookEx(MouseHook, nCode, wParam, lParam);

	}, nullptr, 0);

	MSG msg{};

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg); DispatchMessage(&msg);
	}

	Destroy(); return EXIT_SUCCESS;
}

void Hooks::Destroy()
{
	UnhookWindowsHookEx(MouseHook);
}