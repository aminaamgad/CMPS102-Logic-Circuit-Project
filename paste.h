#ifndef PASTE_H
#define PASTE_H

#include "Actions/Action.h"
#include "Components/Component.h"

class Paste : public Action
{
	Component* pastedComp;

public:
	Paste(ApplicationManager* pManager);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif
