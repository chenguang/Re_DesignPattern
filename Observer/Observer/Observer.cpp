#include "Observer.h"
#include <iostream>
#include <algorithm>

using namespace std;

Observer::Observer()
{}

Observer::~Observer()
{}

ConcreteObserver::ConcreteObserver()
{}

ConcreteObserver::~ConcreteObserver()
{}

void ConcreteObserver::Update(Subject* pSubject)
{
	this->m_state = pSubject->GetState();
	cout << "The ConcreteObserver is " << m_state << std::endl;
}

Subject::Subject()
{}

Subject::~Subject()
{}

void Subject::Attach(Observer* pObserver)
{
	this->m_lst.push_back(pObserver);
	cout << "Attach an Observer:"<<m_name<<"\n";
}

void Subject::Detach(Observer* pObserver)
{
	list<Observer*>::iterator iter;
	iter = find(m_lst.begin(), m_lst.end(), pObserver);
	if (iter != m_lst.end())
	{
		m_lst.erase(iter);
	}
	cout << "Detach an Observer:"<<"\n";
}

void Subject::Notify()
{
	list<Observer*>::iterator iter = this->m_lst.begin();
	for (; iter != m_lst.end(); iter++)
	{
		(*iter)->Update(this);
	}
}

string Subject::GetState()
{
	return this->m_state;
}


void Subject::SetState(string state)
{
	this->m_state = state;
}

string Subject::GetName()
{
	return this->m_name;
}
void Subject::SetName(string name)
{
	this->m_name = name;
}

ConcreteSubject::ConcreteSubject()
{}

ConcreteSubject::~ConcreteSubject()
{}
