#pragma once
class Pair
{
	int a;
	int b;
public:
	int first();
	int second();
	Pair(int _a, int _b);
	Pair();
	~Pair() {};
	void makePair(int _a, int _b);
};

