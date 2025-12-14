#include "ApplicationManager.h"
#include "Actions/AddANDgate2.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = nullptr;

	Clipb
		oard = nullptr;
	IsClip_Cut = false;

	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;

	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;

	case ADD_CONNECTION:
		break;

	case EXIT:
		break;
	}

	if (pAct)
	{
		pAct->Execute();
		delete pAct;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(OutputInterface);
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::RemoveComponent(Component* pComp)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == pComp)
		{
			// shift components left
			for (int j = i; j < CompCount - 1; j++)
			{
				CompList[j] = CompList[j + 1];
			}

			CompList[CompCount - 1] = nullptr;
			CompCount--;
			return;
		}
	}
}


Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

Input* ApplicationManager::GetInput()
{
	return InputInterface;
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::AddComponent(Component* pComp)
{
	if (CompCount < MaxCompCount)
	{
		CompList[CompCount++] = pComp;
	}
}
////////////////////////////////////////////////////////////////////
// ================= CLIPBOARD =================

void ApplicationManager::SetClipboard(Component* pComp, bool IsCut)
{
	Clipboard = pComp;
	IsClip_Cut = IsCut;
}

Component* ApplicationManager::GetClipboard() const
{
	return Clipboard;
}

bool ApplicationManager::GetIsCut() const
{
	return IsClip_Cut;
}

void ApplicationManager::Uncut()
{
	Clipboard = nullptr;
	IsClip_Cut = false;
}

void ApplicationManager::ClearClipboard()
{
	Clipboard = nullptr;
	IsClip_Cut = false;
}
////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];

	delete OutputInterface;
	delete InputInterface;
}
