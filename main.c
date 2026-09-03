#include "STD_TYPES.h"
#include "DIO_int.h"

#define F_CPU 8000000UL

int main(void)
{
	
	DIO_voidSetPinDirection(DPORTA, PIN0, INPUT);
	DIO_voidSetPinDirection(DPORTA, PIN1, INPUT);
	DIO_voidSetPinDirection(DPORTA, PIN2, INPUT);

	
	DIO_voidSetPinDirection(DPORTB, PIN0, INPUT);


	DIO_voidSetPinDirection(DPORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN1, OUTPUT);
	DIO_voidSetPinDirection(DPORTC, PIN2, OUTPUT);

	
	DIO_voidConnectPullup(DPORTA, PIN0, 1);
	DIO_voidConnectPullup(DPORTA, PIN1, 1);
	DIO_voidConnectPullup(DPORTA, PIN2, 1);
	DIO_voidConnectPullup(DPORTB, PIN0, 1);

	while (1)
	{
	
		if (DIO_u8ReadPinValue(DPORTB, PIN0) == 0)
		{
			DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN1, HIGH);
			DIO_voidSetPinValue(DPORTC, PIN2, HIGH);
		}
		else 
		{
			
			if (DIO_u8ReadPinValue(DPORTA, PIN0) == 0)
			{
				DIO_voidSetPinValue(DPORTC, PIN0, HIGH);
			}
			else
			{
				DIO_voidSetPinValue(DPORTC, PIN0, LOW);
			}

		
			if (DIO_u8ReadPinValue(DPORTA, PIN1) == 0)
			{
				DIO_voidSetPinValue(DPORTC, PIN1, HIGH);
			}
			else
			{
				DIO_voidSetPinValue(DPORTC, PIN1, LOW);
			}

			
			if (DIO_u8ReadPinValue(DPORTA, PIN2) == 0)
			{
				DIO_voidSetPinValue(DPORTC, PIN2, HIGH);
			}
			else
			{
				DIO_voidSetPinValue(DPORTC, PIN2, LOW);
			}
		}
	}
}