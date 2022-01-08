#pragma once

#include <Windows.h>
#include <stdio.h>
#include <thread>

namespace Hooks
{
	inline HHOOK MouseHook = nullptr;
	LRESULT CALLBACK MouseHookCallback(int nCode, WPARAM wParam, LPARAM lParam);

	void Destroy();
	DWORD WINAPI Spawn();
}