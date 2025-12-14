#ifndef CUT_H
#define CUT_H

#include "Actions/Action.h"

class CUT : public Action
{
public:
	CUT(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif
