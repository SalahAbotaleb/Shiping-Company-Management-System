#include "Cargo.h"


Cargo::Cargo(Itemtype t,int ID, int Dis, int Lt, int cost, Time time)
{
	type = t;
	this->ID = ID;
	deldis = Dis;
	this->Lt = Lt;
	this->cost = cost;
	Pt = time;
}

Cargo::Cargo()
{
}

int Cargo::getid() const
{
	return ID;
}

int Cargo::getTID() const
{
	return TID;
}

void Cargo::setTID(int id)
{
	TID = id;
}

Itemtype Cargo::gettype()
{
	return type;
}

Time Cargo::getprept()
{
	return Pt;
}

Time Cargo::getCDT()
{
	return CDT;
}

Time Cargo::getWT()
{
	return WT;
}

void Cargo::setWT(Time& t)
{
	WT = t;
}

void Cargo::setCDT(Time& t)
{
	CDT = t;
}

void Cargo::settype(Itemtype t)
{
	type = t;
}

int Cargo::getloadt()
{
	return Lt;
}




int Cargo::getdeldis()
{
	return deldis;
}

int Cargo::getcost()
{
	return cost;
}



std::ostream& operator<<(std::ostream& f, const Cargo* C)
{
	f << C->getid();
	return f;
}


