
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../Header/EXTI_Configuration.h"
#include "../Header/EXTI_Private.h"
#include "../Header/EXTI_Interface.h"
#include "../Header/EXTI_Register.h"

#include "../../DIO/HEADER/DIO_interface.h"



/*Global pointer to function to hold int0 ISR address*/
void (*EXTI_P_Int0Func)(void)=NULL;

/*Options For Triggering Mode*/
#define EXTI_FallingEdge			0
#define EXTI_RisingEdge  			1
#define EXTI_OnChangeEdge			2
#define EXTI_LowLevel    			3
/*-------------------------------*/
#define EXTI0             0
#define EXTI1             1
#define EXTI2             2
/*-------------------------------*/
void EXTI0_VoidInit0(void)
{
	/* Step 1 : Set PULLUP because input will be Sensor or Button*/
	DIO_u8PullUpPin(EXTI0_PORT,EXTI0_PIN,DIO_EN_PULL_UP_RES);
	/*Step 2 : Enable PIE (EXTI_INT0)*/
	SET_BIT(EXTI_GICR,EXTI_INT0);

	/*Check Trigger Mode By #if*/
#if EXTI0_TriggerMode == EXTI_LowLevel
	CLEAR_BIT(EXTI_MCUCR,EXTI_ISC00);
	CLEAR_BIT(EXTI_MCUCR,EXTI_ISC01);
#elif EXTI0_TriggerMode == EXTI_OnChangeEdge
	SET_BIT(EXTI_MCUCR,EXTI_ISC00);
	CLEAR_BIT(EXTI_MCUCR,EXTI_ISC01);
#elif EXTI0_TriggerMode == EXTI_FallingEdge
	CLEAR_BIT(EXTI_MCUCR,EXTI_ISC00);
	SET_BIT(EXTI_MCUCR,EXTI_ISC01);
#elif EXTI0_TriggerMode == EXTI_RisingEdge
	SET_BIT(EXTI_MCUCR,EXTI_ISC00);
	SET_BIT(EXTI_MCUCR,EXTI_ISC01);
#endif
}
void EXTI1_VoidInit1(void)
{
	/*SET INT 1 PIN AS INPUT*/
	DIO_u8SetPinDirection(EXTI1_PORT,EXTI1_PIN,PIN_INPUT);
	/*SET Internal PULLUP*/
	DIO_u8SetPinValue(EXTI1_PORT,EXTI1_PIN,DIO_HIGH);
	/*Enable EXTI 1*/
	SET_BIT(EXTI_GICR,EXTI_INT1);
	/*Check Triggering MODE*/
#if EXTI1_TriggerMode == EXTI_FallingEdge
	SET_BIT(EXTI_MCUCR,EXTI_ISC11);
	CLEAR_BIT(EXTI_MCUCR,EXTI_ISC10);
#elif EXTI1_TriggerMode == EXTI_RisingEdge
	SET_BIT(EXTI_MCUCR,EXTI_ISC11);
	SET_BIT(EXTI_MCUCR,EXTI_ISC10);
#elif EXTI1_TriggerMode == 	EXTI_OnChangeEdge
	CLEAR_BIT(EXTI_MCUCR,EXTI_ISC11);
	SET_BIT(EXTI_MCUCR,EXTI_ISC10);
#elif EXTI1_TriggerMode == 	EXTI_LowLevel
	CLEAR_BIT(EXTI_MCUCR,EXTI_ISC11);
	CLEAR_BIT(EXTI_MCUCR,EXTI_ISC10);
#endif


}
void EXTI2_VoidInit2(void)
{
	DIO_u8SetPinDirection(EXTI2_PORT,EXTI2_PIN,PIN_INPUT);
	DIO_u8SetPinValue(EXTI2_PORT,EXTI2_PIN,DIO_HIGH);
	SET_BIT(EXTI_GICR,EXTI_INT2);
#if EXTI2_TriggerMode == EXTI_FallingEdge
	CLEAR_BIT(EXTI_MCUCSR,EXTI_ISC2);
#elif EXTI2_TriggerMode == EXTI_RisingEdge
	SET_BIT(EXTI_MCUCSR,EXTI_ISC2);
#endif
}
/*describtion: a function to set the required sense control of int0 using post build configuration
 * input:  Local_u8Sense , option are :   1- EXTI_FallingEdge
 *                                        2- EXTI_RisingEdge
 *                                        3- EXTI_OnChangeEdge
 *                                        4- EXTI_LowLevel
 * */
void EXTI_VoidInt0SetSenseControl(u8 Local_u8Sense)
{

	switch(Local_u8Sense)
	{
	case EXTI_FallingEdge:
		CLEAR_BIT(EXTI_MCUCR,EXTI_ISC00);
		SET_BIT(EXTI_MCUCR,EXTI_ISC01);
		break;
	case EXTI_RisingEdge :
		SET_BIT(EXTI_MCUCR,EXTI_ISC00);
		SET_BIT(EXTI_MCUCR,EXTI_ISC01);
		break;
	case EXTI_OnChangeEdge :
		SET_BIT(EXTI_MCUCR,EXTI_ISC00);
		CLEAR_BIT(EXTI_MCUCR,EXTI_ISC01);
		break;
	case EXTI_LowLevel :
		CLEAR_BIT(EXTI_MCUCR,EXTI_ISC00);
		CLEAR_BIT(EXTI_MCUCR,EXTI_ISC01);
		break;
	}
}
void EXTI_VoidInt1SetSenseControl(u8 Local_u8Sense)
{

	switch(Local_u8Sense)
	{
	case EXTI_FallingEdge:
		SET_BIT(EXTI_MCUCR,EXTI_ISC11);
		CLEAR_BIT(EXTI_MCUCR,EXTI_ISC10);
		break;
	case EXTI_RisingEdge :
		SET_BIT(EXTI_MCUCR,EXTI_ISC11);
		SET_BIT(EXTI_MCUCR,EXTI_ISC10);
		break;
	case EXTI_OnChangeEdge :
		CLEAR_BIT(EXTI_MCUCR,EXTI_ISC11);
		SET_BIT(EXTI_MCUCR,EXTI_ISC10);
		break;
	case EXTI_LowLevel :
		CLEAR_BIT(EXTI_MCUCR,EXTI_ISC11);
		CLEAR_BIT(EXTI_MCUCR,EXTI_ISC10);
		break;
	}

}
void EXTI_VoidInt2SetSenseControl(u8 Local_u8Sense)
{

	switch(Local_u8Sense)
	{
	case EXTI_FallingEdge:
		CLEAR_BIT(EXTI_MCUCSR,EXTI_ISC2);
		break;
	case EXTI_RisingEdge :
		SET_BIT(EXTI_MCUCSR,EXTI_ISC2);
		break;
	}

}
void EXTI_u8IntEnable(u8 Local_u8Int)
{
	switch(Local_u8Int){
	case EXTI0:
		/* Step 1 : Set PULLUP because input will be Sensor or Button*/
		DIO_u8PullUpPin(EXTI0_PORT,EXTI0_PIN,DIO_EN_PULL_UP_RES);
		/*Step 2 : Enable PIE (EXTI_INT0)*/
		SET_BIT(EXTI_GICR,EXTI_INT0);
		break;
	case EXTI1:
		/* Step 1 : Set PULLUP because input will be Sensor or Button*/
		DIO_u8PullUpPin(EXTI1_PORT,EXTI1_PIN,DIO_EN_PULL_UP_RES);
		/*Step 2 : Enable PIE (EXTI_INT0)*/
		SET_BIT(EXTI_GICR,EXTI_INT1);
		break;
	case EXTI2:
		/* Step 1 : Set PULLUP because input will be Sensor or Button*/
		DIO_u8PullUpPin(EXTI2_PORT,EXTI2_PIN,DIO_EN_PULL_UP_RES);
		/*Step 2 : Enable PIE (EXTI_INT0)*/
		SET_BIT(EXTI_GICR,EXTI_INT2);
		break;
	}
}
void EXTI_u8IntDisable(u8 Local_u8Int)
{
	switch(Local_u8Int){
	case EXTI0:
		/* Step 1 : turn off pull up */
		DIO_u8PullUpPin(EXTI0_PORT,EXTI0_PIN,DIO_DIS_PULL_UP_RES);
		/*Step 2 : disable PIE (EXTI_INT0)*/
		CLEAR_BIT(EXTI_GICR,EXTI_INT0);
		break;
	case EXTI1:
		/* Step 1 : turn off pull up */
		DIO_u8PullUpPin(EXTI1_PORT,EXTI1_PIN,DIO_DIS_PULL_UP_RES);
		/*Step 2 : disable PIE (EXTI_INTq)*/
		CLEAR_BIT(EXTI_GICR,EXTI_INT1);
		break;
	case EXTI2:
		/* Step 1 : turn off pull up */
		DIO_u8PullUpPin(EXTI2_PORT,EXTI2_PIN,DIO_DIS_PULL_UP_RES);
		/*Step 2 : disable PIE (EXTI_INTw)*/
		CLEAR_BIT(EXTI_GICR,EXTI_INT2);
		break;
	}
}
void EXTI_u8Int0SetCallBack(void(*Local_P_Int0Func)(void))
{
	if(Local_P_Int0Func != NULL )
	{
		EXTI_P_Int0Func= Local_P_Int0Func ;
	}
	else
	{
		/*do nothing*/
	}
}
/*ISR of INT0*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXTI_P_Int0Func();
}
























