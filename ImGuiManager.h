#pragma once

//ImGui関連データのインクルード
#include "Engine/ImGui/imgui.h"
#include "Engine/ImGui/imgui_impl_dx11.h"
#include "Engine/ImGui/imgui_impl_win32.h"

#include "Engine/Direct3D.h"
#include <Windows.h>
namespace ImGuiManager
{
	bool Initialize(HWND _hWnd);
	bool DrawStart();
	void Feature();
	bool DrawEnd();
	bool Release();
};

