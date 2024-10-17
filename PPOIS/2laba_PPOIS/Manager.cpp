#include <D:\LABY\BSUIR\PPOIS\2laba_PPOIS\Manager.h>
#include <vector>
#include <string>
#include <iostream>
Order Manager::compare_an_order(int indexOfOrder) {
	Order order_to_return;
	if (indexOfOrder == 1) {
		MIG mig;
		return mig;
	}
	else if (indexOfOrder == 2) {
		HeadFlex headFlex;
		return headFlex;
	}
	else if (indexOfOrder == 3) {
		IBYPROFEN ibyprofen;
		return ibyprofen;
	}
	else if (indexOfOrder == 4) {
		ANTIGISTAT antigistat;
		return antigistat;
	}
	else if (indexOfOrder == 5) {
		ACETAMINOPHEN ACETAMINOPHEN;
		return ACETAMINOPHEN;
	}
	else if (indexOfOrder == 6) {
		ASPIRIN aspirin;
		return aspirin;
	}
	else if (indexOfOrder == 7) {
		DICLOFENAC diclofenac;
		return diclofenac;
	}
	else if (indexOfOrder == 8) {
		KETOROLAC ketorolac;
		return ketorolac;
	}
}