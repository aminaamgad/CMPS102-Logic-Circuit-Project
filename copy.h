#ifndef COPY_H
#define COPY_H

#include "Actions/Action.h"

class COPY : public Action
{
public:
	COPY(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif
