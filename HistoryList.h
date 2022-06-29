#pragma once
#include "HistoryObject.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

class HistoryList {
	HistoryObject* history_objects;
	int objects;
	static int object_index;

public:

	HistoryList();
	HistoryList(int objects);
	HistoryList& operator = (const HistoryList& history_list);

	void SetHistoryObjects();
	void SetObjects(int objects);

	int GetObjects() const;

	void ResizeHistoryList();

	void InsertSearch(std::string search_id);

	void PrintHistoryList();
};

