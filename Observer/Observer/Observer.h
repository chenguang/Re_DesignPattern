#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
#include <list>
using namespace std;

//typedef int STATE;
class Observer;

class Subject
{
public:
	~Subject();
	virtual void Notify();
	virtual void Attach(Observer*);
	virtual void Detach(Observer*);
	virtual string GetState();
	virtual string GetName();
	virtual void SetState(string nState);
	virtual void SetName(string nName);
protected:
	Subject();
private:
	string m_state;
	string m_name;
	list<Observer*>m_lst;
};

class Observer
{
public:
	~Observer();
	virtual void Update(Subject* pSubject) = 0;
protected:
	Observer();
};
class ConcreteSubject :public Subject
{
public:
	ConcreteSubject();
	~ConcreteSubject();
};
class ConcreteObserver :public Observer
{
public:
	ConcreteObserver();
	~ConcreteObserver();
	virtual void Update(Subject*);
protected:
private:
	string m_state;
	string m_name;
};

#endif