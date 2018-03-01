#pragma once

#include "Opperation.h"

class Calc {
public:
	Calc();

	void AddNum(int n);
	void SetOp(Opperation o);
	bool HasLast();
	int Answer();
	void Reset();

	~Calc();

private:
	bool m_hasFirst;
	bool m_hasLast;
	int m_first;
	int m_secound;
	int m_last;
	Opperation m_op;

	bool Verify();

};

