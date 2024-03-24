#include "ImGuiManager.h"

bool ImGuiManager::Initialize(HWND _hWnd)
{
	IMGUI_CHECKVERSION();	//ImGui導入バージョンを確認
	ImGui::CreateContext();	//コンテキストを作成
	ImGuiIO& io = ImGui::GetIO();	//必要なデータを取得
	ImGui::StyleColorsDark();	//カラーを黒に設定

	//ImGuiを初期化
	if (!ImGui_ImplWin32_Init(_hWnd))return false;
	if (!ImGui_ImplDX11_Init(Direct3D::pDevice_,Direct3D::pContext_))return false;
	return true;
}

bool ImGuiManager::DrawStart()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	return true;
}

void ImGuiManager::Feature()
{
#ifdef _DEBUG
	ImGui::Begin("Hello, world!");//ImGuiの処理を開始
	{
		//この中にしたい処理を記述
		//描画されるボタンを押したら...
		if (ImGui::Button("button")) {
			PostQuitMessage(0);	//プログラム終了
		}
	}
#endif // _DEBUG

	
}

bool ImGuiManager::DrawEnd()
{
#ifdef _DEBUG
	ImGui::End();//ImGuiの処理を終了
#endif // _DEBUG

	//ImGuiの描画処理
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return true;
}

bool ImGuiManager::Release()
{
	//ImGuiの開放処理
	ImGui_ImplDX11_Shutdown();
	ImGui::DestroyContext();

	return true;
}
