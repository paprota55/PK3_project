#include"stdafx.h"
#include "refund.h"


refund::refund()
{
	ref = 0;
}

refund::refund(int x)
{
	ref = x;
}

refund::~refund()
{
	ref = 0;
};

void refund::setRefund(int x)
{
	ref = x;
}

void refund::setRefundMain() //ustawienie poziomu refundacji
{
	char arrow;
	int x = 0;

	const int character_up = 72;
	const int character_down = 80;

	while (true)
	{
		system("cls");
		std::cout << "Ustaw refundacje(w %): " << x << std::endl;

		std::cout << "strzalki gora/dol | enter - zatwierdz";

		arrow = _getch();
		switch (arrow)
		{
		case character_up:
			if (x < 100)x++;
			break;
		case character_down:
			if (x > 0)x--;
			break;
		case '\015':
			setRefund(x);
			return;
			break;
		}
	}
}

int refund::getRefund()
{
	return ref;
}

std::ostream & operator<<(std::ostream &out, refund&x)
{
	return out << "Poziom refundacji: " << x.getRefund() << "%" << std::endl;
}