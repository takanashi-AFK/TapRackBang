#include "ImGuiManager.h"

bool ImGuiManager::Initialize(HWND _hWnd)
{
	IMGUI_CHECKVERSION();	//ImGui�����o�[�W�������m�F
	ImGui::CreateContext();	//�R���e�L�X�g���쐬
	ImGuiIO& io = ImGui::GetIO();	//�K�v�ȃf�[�^���擾
	ImGui::StyleColorsDark();	//�J���[�����ɐݒ�

	//ImGui��������
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
	ImGui::Begin("Hello, world!");//ImGui�̏������J�n
	{
		//���̒��ɂ������������L�q
		//�`�悳���{�^������������...
		if (ImGui::Button("button")) {
			PostQuitMessage(0);	//�v���O�����I��
		}
	}
#endif // _DEBUG

	
}

bool ImGuiManager::DrawEnd()
{
#ifdef _DEBUG
	ImGui::End();//ImGui�̏������I��
#endif // _DEBUG

	//ImGui�̕`�揈��
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return true;
}

bool ImGuiManager::Release()
{
	//ImGui�̊J������
	ImGui_ImplDX11_Shutdown();
	ImGui::DestroyContext();

	return true;
}
