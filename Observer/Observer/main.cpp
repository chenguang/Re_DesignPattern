#include "Observer.h"
#include <iostream>

using namespace std;

int main()
{
	
	Observer* p1 = new ConcreteObserver();
	Observer* p2 = new ConcreteObserver();
	Observer* p3 = new ConcreteObserver();

	Subject* pSubject = new ConcreteSubject();
	pSubject->Attach(p1);
	pSubject->Attach(p2);
	pSubject->Attach(p3);
	
	pSubject->SetState("old");
	pSubject->SetName("A");
	pSubject->Notify();

	cout << "-------------------------------------" << endl;
	pSubject->SetState("new");

	pSubject->Detach(p3);
	pSubject->Notify();
	getchar();
	return 0;
}