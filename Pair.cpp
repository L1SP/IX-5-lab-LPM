#include "Pair.h"
int Pair::first() {
	return a;
}
int Pair::second() {
	return b;
}
Pair::Pair()
{
	a = 0;
	b = 0;
}
Pair::Pair(int _a, int _b) {
	a = _a;
	b = _b;
}
void Pair::makePair(int _a, int _b) {
	a = _a;
	b = _b;
}