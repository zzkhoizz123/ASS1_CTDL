/*
* =========================================================================================
* Name        : processData.cpp
* Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
* =========================================================================================
*/
#include "eventLib.h"
#include "dbLib.h"


inline bool operator==(NinjaInfo_t& lhs, const char* rhs) {
	return strcmp(lhs.id, rhs) == 0;
}

struct MapTime {
	char id[ID_MAX_LENGTH];
	long time;

	MapTime() :time(0) {
		strcpy(id, "");
	}

	MapTime(const char *newid, long newtime) :time(newtime) {
		strcpy(id, newid);
	}
};

inline bool operator==(MapTime &lm, char* id) {
	return (strcmp(lm.id, id) == 0);
}

inline bool operator==(MapTime &lm, const char* id) {
	return (strcmp(lm.id, id) == 0);
}

struct MapRoad {
	char id[ID_MAX_LENGTH];
	double RoadLength;

	MapRoad() : RoadLength(0) {
		strcpy(id, "");
	}

	MapRoad(const char *idnew, double rLength) :RoadLength(rLength) {
		strcpy(id, idnew);
	}
};

inline bool operator==(MapRoad &lm, char* id) {
	return (strcmp(lm.id, id) == 0);
}

inline bool operator==(MapRoad &lm, const char* id) {
	return (strcmp(lm.id, id) == 0);
}


// Khai bao nguyen mau ham


bool process1Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);

bool process2Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);

bool process3Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);
bool testId(const char *id, L1List<NinjaInfo_t> &list);

bool process4Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);

bool process5Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);

bool process6Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);

bool process7Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dblist);

bool process8Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dblist);

string id_maxRoad(L1List<MapRoad> &mapList);
bool checkId_mapRoad(char *id, L1List<MapRoad> &mapList);
double RoadLength(const char* id, L1List<NinjaInfo_t> &dbList);
bool process9Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);

long TimeGo(const char* id, L1List<NinjaInfo_t> &dbList);
bool checkId_mapTime(char * id, L1List<MapTime> &mapList);
string id_maxTime(L1List<MapTime> &mapList);
bool process10Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);


bool checkId_idList(char *id, L1List<string> &idList);
void RefineId(L1List<NinjaInfo_t> &dbList, L1List<string> &idList);
bool process11Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);


long TimeStop(const char *id, L1List<NinjaInfo_t> &dblist);
bool process12Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);


bool checkNinja(const char* id, L1List<NinjaInfo_t> &dbList);
void A_AboveLeft(double xA, double yA, double xB, double yB, L1List<NinjaInfo_t> &dbList, L1List<NinjaInfo_t> &dbNew);
void A_AboveRight(double xA, double yA, double xB, double yB, L1List<NinjaInfo_t> &dbList, L1List<NinjaInfo_t> &dbNew);
void A_BottomLeft(double xA, double yA, double xB, double yB, L1List<NinjaInfo_t> &dbList, L1List<NinjaInfo_t> &dbNew);
void A_BottomRight(double xA, double yA, double xB, double yB, L1List<NinjaInfo_t> &dbList, L1List<NinjaInfo_t> &dbNew);
void converstUseful(ninjaEvent_t event, NinjaInfo_t ninja, double &xA, double &yA, double &xB, double &yB);
bool process13Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);



int checkId_List(char * id, L1List<NinjaInfo_t> &newList);
bool process14Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList);



bool processEvent(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList, void* pGData) {
	// TODO: Your code comes here


	string str = event.code;
	string str_first = str.substr(0, 1); //---------------------------------------- take evey character from position one to over
	string str_first_last = str.substr(0, 2);

	if (str == "1" && str.size() == 1) {
		return process1Event(event, nList);
	}
	else if (str_first == "2" && str.size() == 1) {
		return process2Event(event, nList);
	}
	else if (str_first == "3" && str.size() == 1) {
		return process3Event(event, nList);
	}
	else if (str_first == "4" && str.size() == 1) {
		return process4Event(event, nList);
	}
	else if (str_first == "5") {
		return process5Event(event, nList);
	}
	else if (str_first == "6") {
		return process6Event(event, nList);
	}
	else if (str_first == "7") {
		return process7Event(event, nList);
	}
	else if (str_first == "8") {
		return process8Event(event, nList);
	}
	else if (str_first == "9" && str.size() == 1) {
		return process9Event(event, nList);
	}
	else if (str_first_last == "10" && str.size() == 2) {
		return process10Event(event, nList);
	}
	else if (str_first_last == "11") {
		return process11Event(event, nList);
	}
	else if (str_first_last == "12" && str.size() == 2) {
		return process12Event(event, nList);
	}
	else if (str_first_last == "13" && str.size() == 18) {
		return true; /// Khong xu ly
	}
	else if (str_first_last == "14" && str.size() == 2) {
		return process14Event(event, nList);
	}
	else {
		return false;
	}
	/// NOTE: The output of the event will be printed on one line
	/// end by the endline character.
}


bool process1Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {

	try {
		cout << event.code << ":" << dbList[0].id << '\n';
	}
	catch (DSAException *ex) {
		cout << ex->getErrorText() << '\n';
	}
	return true;
}


bool process2Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {
	long size = dbList.getSize();
	try {
		cout << event.code << ":" << dbList[size - 1].id << '\n';
	}
	catch (DSAException *ex) {
		cout << ex->getErrorText() << '\n';
	}
	return true;
}


bool testId(const char *id, L1List<NinjaInfo_t> &list) {
	L1Item<NinjaInfo_t> *p = list.getHead();
	while (p) {
		if (p->data == id)
			return false;
		p = p->pNext;
	}
	return true;
}


bool process3Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {

	L1Item<NinjaInfo_t> *p = dbList.getHead();
	long run = 0;
	L1List<NinjaInfo_t> newList;
	while (p) {
		if (testId(p->data.id, newList)) {
			newList.insertHead(p->data);
		}
		p = p->pNext;
	}
	cout << event.code << ":" << newList.getSize() << '\n';
	return true;
}

bool process4Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {
	char idMax[EVENT_CODE_SIZE];

	L1Item<NinjaInfo_t>* p = dbList.getHead();
	strcpy(idMax, p->data.id);
	p = p->pNext;
	while (p) {
		if (strcmp(idMax, p->data.id) < 0)
			strcpy(idMax, p->data.id);
		p = p->pNext;
	}
	cout << event.code << ":" << idMax << '\n';
	return true;
}

bool process5Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {

	string str = event.code;
	str = str.substr(1); //---------------------------------------- take evey character from position one to over
	const char *idcmp = str.c_str(); //--------------------------- convert string to const char*
	int flat = 0;
	L1Item<NinjaInfo_t> *p = dbList.getHead();
	time_t timeMove;
	NinjaInfo_t ninjaPre;
	NinjaInfo_t ninjaCur;
	//------------------------------------------------------------ get the ninja into ninjaCur and set a flat
	while (p) {
		if (strcmp(idcmp, p->data.id) == 0) {
			ninjaCur = p->data;
			flat = 1;
			break;
		}
		p = p->pNext;
	}
	if (flat == 0) {
		cout << event.code << ":-1\n";
		return true;
	}
	p = p->pNext;
	while (p) {
		if (strcmp(idcmp, p->data.id) == 0) {
			ninjaPre = ninjaCur;
			ninjaCur = p->data;
			if (distanceEarth(ninjaPre.latitude, ninjaPre.longitude, ninjaCur.latitude, ninjaCur.longitude) <= 5.0 / 1000) {
				ninjaCur = ninjaPre;
			}
			else {
				timeMove = ninjaCur.timestamp;
				char *strTime = new char[26];
				strPrintTime(strTime, timeMove);
				cout << event.code << ":" << strTime << '\n';
				return true;
			}
		}
		p = p->pNext;
	}

	cout << event.code << ":" << "ninja does not move !!!\n";
	return true;
}


bool process6Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {

	string str = event.code;
	str = str.substr(1); //---------------------------------------- take evey character from position one to over
	const char *idcmp = str.c_str(); //--------------------------- convert string to const char*
	int flat = 0;
	L1Item<NinjaInfo_t> *p = dbList.getHead();
	time_t timeStop;
	NinjaInfo_t ninjaPre;
	NinjaInfo_t ninjaCur;
	//------------------------------------------------------------ get the ninja into ninjaCur and set a flat
	while (p) {
		if (strcmp(idcmp, p->data.id) == 0) {
			ninjaCur = p->data;
			flat = 1;
			break;
		}
		p = p->pNext;
	}
	if (flat == 0) {
		cout << event.code << ":-1\n";
		return true;
	}
	p = p->pNext;
	while (p) {
		if (strcmp(idcmp, p->data.id) == 0) {
			ninjaPre = ninjaCur;
			ninjaCur = p->data;
			if (distanceEarth(ninjaPre.latitude, ninjaPre.longitude, ninjaCur.latitude, ninjaCur.longitude) <= 5.0 / 1000) {
				ninjaCur = ninjaPre;
				timeStop = ninjaPre.timestamp;
				flat = 0;
			}
		}
		p = p->pNext;
	}
	if (flat == 1) {
		cout << event.code << ":" << "ninja does not stop !!!\n";
	}
	else {
		char *strTime = new char[26];
		strPrintTime(strTime, timeStop);
		cout << event.code << ":" << strTime << '\n';
	}
	return true;
}


bool process7Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dblist) {

	string str = event.code;
	str = str.substr(1); //---------------------------------------- take evey character from position one to over
	const char *idcmp = str.c_str(); //--------------------------- convert string to const char*
	int flat = 0;
	L1Item<NinjaInfo_t>*p = dblist.getHead();
	long ninjaStop_repeat = 0;
	NinjaInfo_t ninjaPre;
	NinjaInfo_t ninjaCur;
	//------------------------------------------------------------ get the ninja into ninjaCur and set a flat
	while (p) {
		if (strcmp(idcmp, p->data.id) == 0) {
			ninjaCur = p->data;
			flat = 1;
			break;
		}
		p = p->pNext;
	}
	if (flat == 0) {
		cout << event.code << ":-1\n";
		return true;
	}
	flat = 0;
	p = p->pNext;
	while (p) {
		if (strcmp(idcmp, p->data.id) == 0) {
			ninjaPre = ninjaCur;
			ninjaCur = p->data;
			if (distanceEarth(ninjaPre.latitude, ninjaPre.longitude, ninjaCur.latitude, ninjaCur.longitude) <= 5.0 / 1000) {
				--flat;
				ninjaCur = ninjaPre;
			}
			else flat = 0;
			if (flat == -1) ninjaStop_repeat++;
		}
		p = p->pNext;
	}
	cout << event.code << ":" << ninjaStop_repeat << '\n';
	return true;
}


bool process8Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dblist) {
	string str = event.code;
	str = str.substr(1); //---------------------------------------- take evey character from position one to over
	const char *idcmp = str.c_str(); //--------------------------- convert string to const char*
	int flat = 0;
	L1Item<NinjaInfo_t>* p = dblist.getHead();
	NinjaInfo_t ninjaPre;
	NinjaInfo_t ninjaCur;
	//------------------------------------------------------------ get the ninja into ninjaCur and set a flat
	while (p) {
		if (p->data == idcmp) {
			ninjaCur = p->data;
			flat = 1;
			break;
		}
		p = p->pNext;
	}
	if (flat == 0) {
		cout << event.code << ":-1\n";
		return true;
	}

	p = p->pNext;
	double roadLenght = 0;
	while (p) {
		if (strcmp(idcmp, p->data.id) == 0) {
			ninjaPre = ninjaCur;
			ninjaCur = p->data;
			double distance = distanceEarth(ninjaPre.latitude, ninjaPre.longitude, ninjaCur.latitude, ninjaCur.longitude);
			if (distance <= 5.0 / 1000) {
				ninjaCur = ninjaPre;
			}
			else {
				roadLenght += distance;

			}
		}
		p = p->pNext;
	}

	cout << event.code << ":" << roadLenght << "\n";
	return true;
}

double RoadLength(const char* id, L1List<NinjaInfo_t> &dbList) {
	L1Item<NinjaInfo_t> *p = dbList.getHead();
	NinjaInfo_t ninjaPre;
	NinjaInfo_t ninjaCur;
	//------------------------------------------------------------ get the ninja into ninjaCur and set a flat
	while (p) {
		if (p->data == id) { //------------------------------- call operator == (ninja , char *)
			ninjaCur = p->data;
			break;
		}
		p = p->pNext;
	}
	p = p->pNext;
	double roadLenght = 0;
	while (p) {
		if (p->data == id) {
			ninjaPre = ninjaCur;
			ninjaCur = p->data;
			double distance = distanceEarth(ninjaPre.latitude, ninjaPre.longitude, ninjaCur.latitude, ninjaCur.longitude);
			if (distance <= 5.0 / 1000) {
				ninjaCur = ninjaPre;
			}
			else {
				roadLenght += distance;
			}
		}
		p = p->pNext;
	}
	return roadLenght;
}


bool checkId_mapRoad(char *id, L1List<MapRoad> &mapList) {
	L1Item<MapRoad> *p = mapList.getHead();
	while (p) {
		if (p->data == id)
			return false;
		p = p->pNext;
	}
	return true;
}


string id_maxRoad(L1List<MapRoad> &mapList) {
	char id[ID_MAX_LENGTH] = "";
	L1Item<MapRoad> *p = mapList.getHead();
	double maxLength = p->data.RoadLength;
	string str(p->data.id);
	p = p->pNext;
	while (p) {
		if (maxLength < p->data.RoadLength) {
			maxLength = p->data.RoadLength;
			str = string(p->data.id);
		}
		p = p->pNext;
	}
	return str;
}

bool process9Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {
	L1List<MapRoad> mapList;
	L1Item<NinjaInfo_t> *p = dbList.getHead();
	while (p) {
		if (checkId_mapRoad(p->data.id, mapList)) {
			double rLength = RoadLength(p->data.id, dbList);
			MapRoad map(p->data.id, rLength);
			mapList.insertHead(map); //
		}
		p = p->pNext;
	}
	string str = id_maxRoad(mapList);
	cout << event.code << ":" << str << '\n';
	return true;
}

// 1->2 : dung 
// 1->3 : dung
// 1->4 : di chuyen
//=> thoi gan di chuyen : 3->4

long TimeGo(const char* id, L1List<NinjaInfo_t> &dbList) {
	L1Item<NinjaInfo_t> *p = dbList.getHead();
	NinjaInfo_t ninjaPre;
	NinjaInfo_t ninjaCur;
	NinjaInfo_t ninjaNext;
	//------------------------------------------------------------ get the ninja into ninjaCur and set a flat
	while (p) {
		if (p->data == id) { //------------------------------- call operator == (ninja , char *)
			ninjaNext = p->data;
			break;
		}
		p = p->pNext;
	}
	p = p->pNext;
	long time = 0;
	ninjaCur = ninjaNext;
	while (p) {
		if (strcmp(id, p->data.id) == 0) {
			ninjaPre = ninjaNext;
			ninjaNext = p->data;

			double distance = distanceEarth(ninjaPre.latitude, ninjaPre.longitude, ninjaCur.latitude, ninjaCur.longitude);
			if (distance <= 5.0 / 1000) {
				ninjaCur = ninjaNext;
				ninjaNext = ninjaPre;
			}
			else {
				time += ninjaNext.timestamp - ninjaCur.timestamp;
				ninjaCur = ninjaNext;
			}
		}
		p = p->pNext;
	}
	return time;
}


bool checkId_mapTime(char * id, L1List<MapTime> &mapList) {
	L1Item<MapTime>*p = mapList.getHead();
	while (p) {
		if (p->data == id)
			return false;
		p = p->pNext;
	}
	return true;
}

string id_maxTime(L1List<MapTime> &mapList) {
	char id[ID_MAX_LENGTH] = "";
	L1Item<MapTime>*p = mapList.getHead();
	long maxtime = p->data.time;
	string str(p->data.id);
	p = p->pNext;
	while (p) {
		if (maxtime < p->data.time) {
			maxtime = p->data.time;
			str = string(p->data.id);
		}
		p = p->pNext;
	}
	return str;
}

bool process10Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {

	L1List<MapTime> mapList;
	L1Item<NinjaInfo_t> *p = dbList.getHead();
	while (p) {
		if (checkId_mapTime(p->data.id, mapList)) {
			long time = TimeGo(p->data.id, dbList);
			MapTime map(p->data.id, time);
			mapList.insertHead(map);
		}
		p = p->pNext;
	}
	string str = id_maxTime(mapList);
	cout << event.code << ":" << str << '\n';
	return true;
}


bool checkId_idList(char *id, L1List<string> &idList) {
	L1Item<string>*p = idList.getHead();
	while (p) {
		const char *cstr = p->data.c_str();
		if (strcmp(id, cstr) == 0) {
			return false;
		}
		p = p->pNext;
	}
	return true;
}

void RefineId(L1List<NinjaInfo_t> &dbList, L1List<string> &idList) {
	L1Item<NinjaInfo_t>*p = dbList.getHead();
	while (p) {
		if (checkId_idList(p->data.id, idList)) {
			string str = p->data.id;
			idList.insertHead(str);
		}
		p = p->pNext;
	}
}


bool process11Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {

	string str = event.code;
	string strcmp = str.substr(2); //---------------------------------------- take evey character from position one to over

	L1List<string> idList;
	RefineId(dbList, idList);
	L1Item<string> *p = idList.getHead();
	string strPseudo = "";
	int flat = 0;
	while (p) {
		if (p->data < strcmp) {
			strPseudo = p->data;
			flat = 1;
			break;
		}
		p = p->pNext;
	}
	if (flat == 0) {
		cout << event.code << ":-1\n";
		return true;
	}

	p = p->pNext;
	while (p) {
		if (p->data <  strcmp) {
			if (p->data > strPseudo) {
				strPseudo = p->data;
			}
		}
		p = p->pNext;
	}

	cout << event.code << ":" << strPseudo << '\n';
	return true;
}


// like question 10
// using checkId_mapTime function and id_maxTime function from question 10
// 1->2 : dung 
// 1->3 : dung
// 1->4 : di chuyen
//=> thoi gian dung : 1->3
long TimeStop(const char *id, L1List<NinjaInfo_t> &dblist) {
	L1Item<NinjaInfo_t> *p = dblist.getHead();
	NinjaInfo_t ninjaPre;
	NinjaInfo_t ninjaCur;
	//------------------------------------------------------------ get the ninja into ninjaCur and set a flat
	while (p) {
		if (strcmp(id, p->data.id) == 0) {
			ninjaCur = p->data;
			break;
		}
		p = p->pNext;
	}

	p = p->pNext;
	long timeStop = 0;
	long timetemp = 0;
	while (p) {
		if (strcmp(id, p->data.id) == 0) {
			ninjaPre = ninjaCur;
			ninjaCur = p->data;
			double distance = distanceEarth(ninjaPre.latitude, ninjaPre.longitude, ninjaCur.latitude, ninjaCur.longitude);
			if (distance <= 5.0 / 1000) {
				timetemp = ninjaCur.timestamp - ninjaPre.timestamp;
				ninjaCur = ninjaPre;
			}
			else {
				timeStop += timetemp;
				timetemp = 0;
			}
		}
		if (p->pNext == NULL) {
			timeStop += timetemp;
		}
		p = p->pNext;
	}
	return timeStop;
}

bool process12Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {
	L1List<MapTime> mapList;
	L1Item<NinjaInfo_t>*p = dbList.getHead();
	while (p) {
		if (checkId_mapTime(p->data.id, mapList)) {
			long time = TimeStop(p->data.id, dbList);
			MapTime map(p->data.id, time);
			mapList.insertHead(map);
		}
		p = p->pNext;
	}
	string str = id_maxTime(mapList);
	cout << event.code << ":" << str << '\n';
	return true;
}


bool checkNinja(const char* id, L1List<NinjaInfo_t> &dbList) {
	L1Item<NinjaInfo_t> *p = dbList.getHead();
	while (p) {
		if (p->data == id)
			return false;
		p = p->pNext;
	}
	return true;
}


void A_AboveLeft(double xA, double yA, double xB, double yB, L1List<NinjaInfo_t> &dbList, L1List<NinjaInfo_t> &dbNew) {
	L1Item<NinjaInfo_t>*p = dbList.getHead();
	while (p) {
		if (checkNinja(p->data.id, dbNew)) {
			if (p->data.longitude <= xB && p->data.longitude >= xA && p->data.latitude <= yA && p->data.latitude >= yB) {
				dbNew.insertHead(p->data);
			}

		}
		p = p->pNext;
	}
}

void A_AboveRight(double xA, double yA, double xB, double yB, L1List<NinjaInfo_t> &dbList, L1List<NinjaInfo_t> &dbNew) {
	L1Item<NinjaInfo_t>*p = dbList.getHead();
	while (p) {
		if (checkNinja(p->data.id, dbNew)) {
			if (p->data.longitude >= xB && p->data.longitude <= xA && p->data.latitude <= yA && p->data.latitude >= yB) {
				dbNew.insertHead(p->data);
			}
		}
		p = p->pNext;
	}
}

void A_BottomLeft(double xA, double yA, double xB, double yB, L1List<NinjaInfo_t> &dbList, L1List<NinjaInfo_t> &dbNew) {
	L1Item<NinjaInfo_t>*p = dbList.getHead();
	while (p) {
		if (checkNinja(p->data.id, dbNew)) {
			if (p->data.longitude <= xB && p->data.longitude >= xA && p->data.latitude >= yA && p->data.latitude <= yB) {
				dbNew.insertHead(p->data);
			}
		}
		p = p->pNext;
	}
}

void A_BottomRight(double xA, double yA, double xB, double yB, L1List<NinjaInfo_t> &dbList, L1List<NinjaInfo_t> &dbNew) {
	L1Item<NinjaInfo_t>*p = dbList.getHead();
	while (p) {
		if (checkNinja(p->data.id, dbNew)) {
			if (p->data.longitude >= xB && p->data.longitude <= xA && p->data.latitude >= yA && p->data.latitude <= yB) {
				dbNew.insertHead(p->data);
			}
		}
		p = p->pNext;
	}
}


void converstUseful(ninjaEvent_t event, NinjaInfo_t ninja, double &xA, double &yA, double &xB, double &yB) {
	string str = event.code;
	str = str.substr(2); //---------------------------------------- take evey character from position one to over

	string str_xA = str.substr(0, 4);
	string str_yA = str.substr(4, 4);
	string str_xB = str.substr(8, 4);
	string str_yB = str.substr(12, 4);

	str_xA = "." + str_xA;
	str_yA = "." + str_yA;
	str_xB = "." + str_xB;
	str_yB = "." + str_yB;

	int longiInt = (int)ninja.longitude;
	int latiInt = (int)ninja.latitude;


	string longiStr, latiStr;
	stringstream ss1, ss2;
	ss1 << longiInt;
	ss1 >> longiStr;
	ss2 << latiInt;
	ss2 >> latiStr;

	str_xA = longiStr + str_xA;
	str_yA = latiStr + str_yA;
	str_xB = longiStr + str_xB;
	str_yB = latiStr + str_yB;

	xA = stod(str_xA);
	yA = stod(str_yA);
	xB = stod(str_xB);
	yB = stod(str_yB);

}

bool process13Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {

	double xA, yA, xB, yB;
	converstUseful(event, dbList[0], xA, yA, xB, yB);
	L1List<NinjaInfo_t> dbNew;

	if (xA < xB && yA > yB)
		A_AboveLeft(xA, yA, xB, yB, dbList, dbNew);
	else if (xA > xB && yA > yB)
		A_AboveRight(xA, yA, xB, yB, dbList, dbNew);
	else if (xA < xB && yA < yB)
		A_BottomLeft(xA, yA, xB, yB, dbList, dbNew);
	else if (xA > xB && yA < yB)
		A_BottomRight(xA, yA, xB, yB, dbList, dbNew);
	else {
		cout << event.code << ":" << "Error xA coincide xB or yA coincide yB\n";
		return true;
	}

	cout << event.code << ":";
	if (dbNew.getSize() == 0)
		cout << "-1\n";
	else {
		L1Item<NinjaInfo_t>*p = dbNew.getHead();
		while (p) {
			if (p->pNext == NULL) {
				cout << p->data.id << '\n';
				break;
			}
			cout << p->data.id << " ";
			p = p->pNext;
		}
	}
	return true;
}


int checkId_List(char * id, L1List<NinjaInfo_t> &newList) {
	L1Item<NinjaInfo_t> *p = newList.getHead();
	int position = 0;
	while (p) {
		if (p->data == id) {
			return position;
		}
		position++;
		p = p->pNext;
	}
	return -1;
}

/*
- Traverse each element
- save each element in newList if it's not traversed yet
- if the element has recently traversed, check whether ninja is lost
- save it into ninjaLostLlist
*/

bool process14Event(ninjaEvent_t event, L1List<NinjaInfo_t> &dbList) {
	L1Item<NinjaInfo_t>*p = dbList.getHead();
	L1List<NinjaInfo_t> newList;
	L1List<NinjaInfo_t> ninjaLostList;

	while (p) {
		long check1 = checkId_List(p->data.id, newList);
		long check2 = checkId_List(p->data.id, ninjaLostList);

		if (check1 == -1) {
			newList.insertHead(p->data);
		}
		else {
			if (check2 == -1) {
				if (p->data.longitude < newList[check1].longitude && p->data.latitude < newList[check1].latitude) {
					ninjaLostList.push_back(newList[check1]);
				}
			}
		}
		p = p->pNext;
	}
	p = ninjaLostList.getHead();
	cout << event.code << ":";
	if (p == NULL) {
		cout << "-1\n";
	}
	else {
		while (p) {
			if (p->pNext == NULL) {
				cout << p->data.id << '\n';
				break;
			}
			cout << p->data.id << " ";
			p = p->pNext;
		}
	}
	return true;
}

