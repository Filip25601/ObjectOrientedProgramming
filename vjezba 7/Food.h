#pragma once
class Food {
	static int counter;
public:
	void Increase();
	void Decrease();
	void Print();
	static int getCounter();
};
