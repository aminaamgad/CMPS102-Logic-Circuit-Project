#include "COPY.h"
#include "ApplicationManager.h"

COPY::COPY(ApplicationManager* pApp) : Action(pApp) {}

void COPY::ReadActionParameters() {}

void COPY::Execute()
{
	Output* pOut = pManager->GetOutput();
	Component* selected = pManager->GetSelected();

	if (!selected)
	{
		pOut->PrintMsg("Select a component to copy");
		return;
	}

	pManager->SetClipboard(selected, false);
	pOut->PrintMsg("Component copied");
}

void COPY::Undo()
{
	pManager->ClearClipboard();
}

void COPY::Redo()
{
}
