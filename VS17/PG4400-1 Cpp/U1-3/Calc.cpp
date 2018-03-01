#include "stdafx.h"
#include "Calc.h"
#include <iostream>

using namespace std;

Calc::Calc() {

	m_hasFirst = false;
	m_hasLast = false;
	m_first = 0;
	m_secound = 0;
	m_last = 0;
	m_op = add;

}

void Calc::AddNum(int n) {

	if (m_hasFirst) {
		m_secound = n;
	} else {
		m_first = n;
	}
	m_hasFirst = true;

}

void Calc::SetOp(Opperation o) {

	m_op = o;

}

bool Calc::HasLast() {
	return m_hasLast;
}

int Calc::Answer() {

	if (m_hasLast) { m_first = m_last; }

	int answer;
	switch (m_op) {

	case add:
		answer = m_first + m_secound;
		m_last = answer;
		m_hasLast = true;
		return answer;
	
	case sub:
		answer = m_first - m_secound;
		m_last = answer;
		m_hasLast = true;
		return answer;

	case mult:
		answer = m_first * m_secound;
		m_last = answer;
		m_hasLast = true;
		return answer;

	case division:
		if (Verify()) {
			answer = m_first / m_secound;
			m_last = answer;
			m_hasLast = true;
			return answer;
		}
		cout << "Cannot devide by zero.";
		Reset();
		return 0;

	default:
		break;
	}

}

void Calc::Reset() {

	m_hasFirst = false;
	m_hasLast = false;
	m_first = 0;
	m_secound = 0;
	m_last = 0;
	m_op = add;

}

bool Calc::Verify() {

	if (m_secound == 0) {
		return false;
	}
	return true;

}


Calc::~Calc() {



}
