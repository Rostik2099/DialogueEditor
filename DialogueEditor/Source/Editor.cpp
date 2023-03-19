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

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImNodes::CreateContext();
	ImGuiIO& igIO = ImGui::GetIO(); (void)igIO;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(appWindow, true);
	ImGui_ImplOpenGL3_Init("#version 330");
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

	ImGui::Begin("Dialogue Editor");

	ImNodes::BeginNodeEditor();

	const int hardcodenode = 1;
	ImNodes::BeginNode(hardcodenode);
	ImNodes::BeginNodeTitleBar();
	ImGui::Text("Start");
	ImNodes::EndNodeTitleBar();
	ImNodes::BeginOutputAttribute(2);
	ImGui::Text("Output");
	ImNodes::EndOutputAttribute();
	ImNodes::EndNode();

	const int hardcode2 = 3;
	ImNodes::BeginNode(hardcode2);
	ImNodes::BeginNodeTitleBar();
	ImGui::Text("End");
	ImNodes::EndNodeTitleBar();
	ImNodes::BeginInputAttribute(4);
	ImGui::Text("Input");
	ImNodes::EndInputAttribute();
	ImNodes::EndNode();

	ImNodes::Link(0, 2, 4);
	ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_BottomLeft);

	ImNodes::EndNodeEditor();
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
