// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() 
{
	headNode = new Node('H');
	tailNode = headNode->InsertNextNode('T');
	cursorNode = headNode;
	stringCount = 0;
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
	// 알파벳 & 특수문자만 받기
	if (key < 32 || key > 126) 
		return false;
	// typing size
	if (stringCount >= 100) 
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

Node* TypingMachine::getCursorNode() {
	return cursorNode;
}

Node* TypingMachine::getHeadNode() {
	return headNode;
}