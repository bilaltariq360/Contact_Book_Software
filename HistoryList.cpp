#include "HistoryList.h"

int HistoryList::object_index = 0;

HistoryList::HistoryList() {
	SetObjects(0);
	history_objects = nullptr;
}

HistoryList::HistoryList(int objects) {
	SetObjects(objects);
}


HistoryList& HistoryList::operator = (const HistoryList& history_list) {
	this->objects = history_list.objects;
	this->object_index = history_list.object_index;
	
	for (int i = 0; i < objects; i++) {
		*(this->history_objects + i) = *(history_list.history_objects + i);
	}

	return *this;
}

void HistoryList::SetObjects(int objects) {
	this->objects = objects;
}

void HistoryList::SetHistoryObjects() {
	this->history_objects = new HistoryObject[GetObjects()];
}

int HistoryList::GetObjects() const {
	return this->objects;
}

void HistoryList::ResizeHistoryList() {
	HistoryObject* resize_history_objects = new HistoryObject[GetObjects()];
	for (int i = 0; i < GetObjects(); i++){
		*(resize_history_objects + i) = *(history_objects + i);
	}
	delete[] history_objects;
	history_objects = nullptr;
	history_objects = new HistoryObject[GetObjects() + 1];
	for (int i = 0; i < GetObjects(); i++) {
		*(history_objects + i) = *(resize_history_objects + i);
	}
	SetObjects(GetObjects() + 1);
}

void HistoryList::PrintHistoryList() {
	for (int i = object_index - 1; i >= 0; i--){
		std::cout << "Time = " << history_objects[i].GetHour() << ":" << history_objects[i].GetMinute() << ":" << history_objects[i].GetSecond() << "  ";
		std::cout << "Date = " << history_objects[i].GetDay() << "\\" << history_objects[i].GetMonth() << "\\" << history_objects[i].GetYear() << std::endl;
		std::cout << "Searched String = " << history_objects[i].GetSearchedString() << std::endl << std::endl;
		std::cout << "-----------------------------------------------------" << std::endl << std::endl;
	}
}

void HistoryList::InsertSearch(std::string search_id) {
	ResizeHistoryList();
	this->history_objects[object_index].SetDateAndTimeString();
	this->history_objects[object_index].SetSearchedString(search_id);
	object_index++;
}