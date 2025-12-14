#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "Actions/Action.h"
#include "Components/Component.h"

class ApplicationManager
{
	enum { MaxCompCount = 200 };

private:
	int CompCount;
	Component* CompList[MaxCompCount];

	Output* OutputInterface;
	Input* InputInterface;

	// ===== Clipboard system =====
	Component* Clipboard;     // copied or cut component
	bool IsClip_Cut;          // true if cut, false if copy

public:
	ApplicationManager();

	// Core functions
	ActionType GetUserAction();
	void ExecuteAction(ActionType);
	void UpdateInterface();

	Output* GetOutput();
	Input* GetInput();

	// Component management
	void AddComponent(Component* pComp);

	// ===== Clipboard functions =====
	void SetClipboard(Component* pComp, bool IsCut);
	Component* GetClipboard() const;
	bool GetIsCut() const;
	void Uncut();
	void ClearClipboard();

	void RemoveComponent(Component* pComp);

	// Selection (implemented by teammate)
	Component* GetSelected();

	~ApplicationManager();
};

#endif
