// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() : headNode(new Node('H')), cursorNode(headNode), stringCount(0) 
{ 
	tailNode = headNode->InsertNextNode('T'); 
}

void TypingMachine::HomeKey() 
{
	cursorNode = headNode;
}

void TypingMachine::EndKey() 
{
	cursorNode = tailNode->GetPreviousNode();
}

void TypingMachine::LeftKey() 
{
	if (cursorNode != headNode) 
	{
		cursorNode = cursorNode->GetPreviousNode();
	}
}

void TypingMachine::RightKey() 
{
	if (cursorNode->GetNextNode() != tailNode) 
	{
		cursorNode = cursorNode->GetNextNode();
	}
}

bool TypingMachine::TypeKey(char key) 
{
	// ���ĺ� & Ư�����ڸ� �ޱ�
	if (key < ASCII_RANGE_START || key > ASCII_RANGE_END)
		return false;
	// typing size
	if (stringCount >= MAX_LENGTH)
		return false;

	cursorNode = cursorNode->InsertNextNode(key);
	stringCount++;
	return true;
}

bool TypingMachine::EraseKey() 
{
	if (cursorNode == headNode) 
		return false;

	cursorNode = cursorNode->GetPreviousNode();
	cursorNode->EraseNextNode();
	stringCount--;
	return true;
}

std::string TypingMachine::Print(char separator) 
{
	std::string result = "";

	Node* currentNode = headNode;
	while (currentNode != tailNode) 
	{
		if (currentNode != headNode) 
		{
			result.push_back(currentNode->GetData());
		}
		if (currentNode == cursorNode && separator != '\0') 
		{
			result.push_back(separator);
		}
		currentNode = currentNode->GetNextNode();
	}
	return result;
}
