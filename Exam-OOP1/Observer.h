#pragma once
#include <vector>

using namespace std;

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Subject
{
private:
	vector<Observer*> observers;
public:
	virtual ~Subject() {}

	void registerObserver(Observer* obs);

	void unregisterObserver(Observer* obs);

	void notify();
};