#include "DialogueEditor.h"

DialogueEditor::DialogueEditor()
{ 
	dlgStart = new DlgStart;
	dlgEnd = new DlgEnd;
}

void DialogueEditor::Draw()
{
	ImGui::Begin("Dialogue Editor");
	ImNodes::BeginNodeEditor();

	dlgStart->Draw();
	dlgEnd->Draw();

	ImNodes::Link(0, 2, 4);
	ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_BottomLeft);

	ImNodes::EndNodeEditor();
}

DialogueEditor::~DialogueEditor() {}