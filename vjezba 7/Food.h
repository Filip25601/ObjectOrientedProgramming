#pragma once
class Food {
private:
	static int counter;

public:
	Food();
	~Food();
	static void changeCounter(int value);
	static void printCounter();
	static int getCounter();
	void consumeFood();
};
