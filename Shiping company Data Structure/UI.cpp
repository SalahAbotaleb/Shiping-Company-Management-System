#include "UI.h"

UI::UI(Company* ptr)
{
	this->ptr = ptr;
}

int UI::readnumber()
{
	int x;
	cout << "Enter number: ";
	cin >> x;
	cout << endl;
	return x;
}

string UI::readfilename()
{
	string name;
	cout << "Enter file name: ";
	cin >> name;
	cout << endl;
	return name;
}

void UI::displayTime(Time t)
{
	cout << "Current Time (Day:Hour):" << t.GetDay() << ":" << t.GetHour() << endl;
}

void UI::displayline()
{
	cout << endl<<"----------------------------------" << endl;
}

void UI::displaytext(string c)
{
	cout << c ;
}

void UI::displayNum(int n)
{
	cout << n;
}

void UI::readmode()
{
	displaytext("Choose mode of opeartion");
	cout << endl;
	displaytext("For interactive mode enter 1");
	cout << endl;
	displaytext("For step-by-step mode enter 2");
	cout << endl;
	displaytext("For silent mode enter 3");
	cout << endl;
	int num = readnumber();
	mode = ( num== 1) ? interactive : (num == 2) ? stepBstep : silent;
}

void UI::PrintBracketStart(Itemtype t)
{
	if (t == Normal)
		cout << "[";
	if (t == Special)
		cout << "(";
	if (t == VIP)
		cout << "{";

}

void UI::PrintBracketEnd(Itemtype t)
{
	if (t == Normal)
		cout << "]";
	if (t == Special)
		cout << ")";
	if (t == VIP)
		cout << "}";
}

void UI::PrintQC(Queue<Cargo*>& q, Itemtype t)
{
	PrintBracketStart(t);
	q.print();
	PrintBracketEnd(t);
}

void UI::PrintLC(CargoList& q, Itemtype t)
{
	PrintBracketStart(t);
	q.Print();
	PrintBracketEnd(t);
}

void UI::PrintPQC(PriorityQueue<Cargo*>& q, Itemtype t)
{
	PrintBracketStart(t);
	q.print();
	PrintBracketEnd(t);
}


void UI::PrintEQT(Queue<Truck*>& q, Itemtype t)
{
	PrintBracketStart(t);
	q.print();
	PrintBracketEnd(t);
}

void UI::PrintEPQT(Queue<Truck*>& q, Itemtype t)
{
	PrintBracketStart(t);
	q.print();
	PrintBracketEnd(t);
}

void UI::PrintQT(Queue<Truck*>& q)
{
	q.print();
}

void UI::PrintPQT(PriorityQueue<Truck*>& q)
{
	q.print();
}




void UI::WaitOption()
{
	if (mode == interactive)
	{
		char x;
		cin.get();
	}
	if (mode == stepBstep)
	{
		Sleep(1000);
	}
}

void UI::save(ofstream& s)
{
	
}

void UI::Interface()
{
	readmode();
	while(ptr->IsRemainingEvents())
	{
		if (ptr->GetTime().CompInRangeH(5, 23))
		{
			WaitOption();
			ptr->Timer();
			ptr->CurrData();
		}
			ptr->IncrementHour();
	}
}

