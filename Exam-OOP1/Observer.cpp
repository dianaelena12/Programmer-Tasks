#include "Observer.h"

void Subject::registerObserver(Observer * obs)
{
	this->observers.push_back(obs);
}

void Subject::unregisterObserver(Observer * obs)
{
	this->observers.erase(find(this->observers.begin(), this->observers.end(), obs));
}

void Subject::notify()
{
	for (auto obs : this->observers) {
		obs->update();
	}
}
