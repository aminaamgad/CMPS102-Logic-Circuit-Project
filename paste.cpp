#include "Paste.h"
#include "ApplicationManager.h"

Paste::Paste(ApplicationManager* pManager) : Action(pManager)
{
	pastedComp = nullptr;
}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Paste component");
}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	Component* clip = pManager->GetClipboard();

	if (!clip)
	{
		pOut->PrintMsg("Clipboard empty");
		return;
	}

	pManager->AddComponent(clip);
	pManager->ClearClipboard();

	pOut->PrintMsg("Component pasted");
}


void Paste::Undo()
{
}

void Paste::Redo()
{
}
