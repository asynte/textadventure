#ifndef RESET_CPP
#define RESET_CPP
#include "gameEngineHeaders/Reset.h"

Reset::Reset(string action, string comment,int id,int limit ,int room,int slot,string state){
	this->action=action;
	this->comment=comment;
	this->id=id;
	this->limit=limit;
	this->room=room;
	this->slot=slot;
	this->state=state;
}
string Reset::getAction(){
	return action;
}
string Reset::getComment(){
	return comment;
}
int Reset::getId(){
	return id;
}

int Reset::getLimit(){
	return limit;
}
int Reset::getRoom(){
	return room;
}
int Reset::getSlot(){
	return slot;
}
string Reset::getState(){
	return state;
}

#endif
