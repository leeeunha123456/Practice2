// Copyright 2018 <Author>

#ifndef TYPING_MACHINE_H_
#define TYPING_MACHINE_H_

#include <string>

#include "node.h"

class TypingMachine {
private:
	Node* headNode;
	Node* tailNode;
	Node* cursorNode;
	int stringCount;

public:
	TypingMachine();
	void HomeKey();
	void EndKey();
	void LeftKey();
	void RightKey();
	bool TypeKey(char key);
	bool EraseKey();
	Node* getCursorNode();
	Node* getHeadNode();
	std::string Print(char separator);
};

#endif  // TYPING_MACHINE_H_
