#include <iostream>

using namespace std;

class Handler {
protected:
	Handler* next;

public:
	void setHandler(Handler* next) {
		this->next = next;
	}

	Handler() {}

	Handler(Handler* next) : next(next) {}

	virtual void process(int age) = 0;
};


class AHandler : public Handler {
public:
	AHandler() : Handler() {}

	AHandler(Handler* next) : Handler(next) {}

	void process(int age) override {
		if (age >= 1 && age <= 17) {
			cout << "Everything good. A handler" << endl;
			return;
		}

		if (next == nullptr) {
			cout << "End. No result. A handler" << endl;
			return;
		}
		next->process(age);
	}
};

class BHandler : public Handler {
public:
	BHandler() : Handler() {}

	BHandler(Handler* next) : Handler(next) {}

	void process(int age) override {
		if (age >= 18 && age <= 65) {
			cout << "Everything good. B handler" << endl;
			return;
		}

		if (next == nullptr) {
			cout << "End. No result. B handler" << endl;
			return;
		}
		next->process(age);
	}
};

class CHandler : public Handler {
public:
	CHandler() : Handler() {}

	CHandler(Handler* next) : Handler(next) {}

	void process(int age) override {
		if (age >= 66 && age <= 100) {
			cout << "Everything good. C handler" << endl;
			return;
		}

		if (next == nullptr) {
			cout << "End. No result. C handler" << endl;
			return;
		}
		next->process(age);
	}
};



int main()
{
	Handler* fisrt = new AHandler();
	Handler* second = new BHandler();
	Handler* third = new CHandler();

	fisrt->setHandler(second);
	second->setHandler(third);

	fisrt->process(99);
}