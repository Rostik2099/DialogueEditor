#include "Editor.h"

Editor::Editor()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Editor::CreateWindow(std::string title)
{
	this->appWindow = glfwCreateWindow(1600, 900, title.c_str(), NULL, NULL);
	if (!appWindow)
	{
		std::cout << "Failed to open Window" << std::endl;
	}
	glfwMakeContextCurrent(appWindow);
	glViewport(0, 0, 1600, 900);

	inpMng = new InputManager(appWindow, this);
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImNodes::CreateContext();
	ImGuiIO& igIO = ImGui::GetIO(); (void)igIO;
	igIO.Fonts->AddFontFromFileTTF("Fonts/arial.ttf", 15, NULL, igIO.Fonts->GetGlyphRangesCyrillic());
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(appWindow, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	editor = new DialogueEditor;
	saveMng = new SaveManager(this);
}

bool Editor::AppWindowShouldClose()
{
	if (appWindow)
	{
		return glfwWindowShouldClose(appWindow);
	}
	else return false;
}

void Editor::Draw()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	this->editor->Draw();
	
	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(appWindow);
}

Editor::~Editor()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImNodes::DestroyContext();
	ImGui::DestroyContext();

	glfwDestroyWindow(appWindow);
	glfwTerminate();
}
