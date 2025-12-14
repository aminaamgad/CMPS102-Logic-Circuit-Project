#include "CUT.h"
#include "ApplicationManager.h"

CUT::CUT(ApplicationManager* pApp) : Action(pApp) {}

void CUT::ReadActionParameters() {}

void CUT::Execute()
{
	Output* pOut = pManager->GetOutput();
	Component* selected = pManager->GetSelected();

	if (!selected)
	{
		pOut->PrintMsg("Select a component to cut");
		return;
	}

	pManager->SetClipboard(selected, true);
	pManager->RemoveComponent(selected);

	pOut->PrintMsg("Component cut");
}


void CUT::Undo()
{
	pManager->Uncut();
}

void CUT::Redo()
{
	if (pManager->GetClipboard())
	{
		pManager->SetClipboard(pManager->GetClipboard(), true);
	}
}
