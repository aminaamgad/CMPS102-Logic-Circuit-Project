#ifndef _XOR2_H
#define _XOR2_H

/*
  Class AND3
  -----------
  represent the 3-input AND gate
*/

#include "../CMPS102-Logic-Circuit-Project/Components/Gate.h"

class AND3 :public Gate
{
public:
	AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif
