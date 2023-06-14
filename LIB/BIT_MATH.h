/*********************************************************************************************
****************************   Author : Mohammed Ayman       *********************************
****************************   Title :     BIT_MATH          *********************************
****************************   Date   : 23/4/2022            *********************************
****************************   Version->1   (23/4/2022)      *********************************
**********************************************************************************************/


/***************** DEALING WITH BITS IN REGISTER  *****************/


#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

/************************************************/
/******* SET A CERTAIN BIT IN REGISTER =1 *******/
/************************************************/
#define SET_BIT(REG,BIT_NO)           (REG|=(1<<BIT_NO))



/**************************************************/
/******* CLEAR A CERTAIN BIT IN REGISTER =0 *******/
/**************************************************/
#define CLEAR_BIT(REG,BIT_NO)         (REG&=(~(1<<BIT_NO)))
#define CLR_BIT(REG,BIT_NO)           (REG&=(~(1<<BIT_NO)))


/************************************************/
/******* TOGGLE A CERTAIN BIT IN REGISTER *******/
/******* IF 0 MAKE IT 1 , IF 1 MAKE IT 0  *******/
/************************************************/
#define TOGGLE_BIT(REG,BIT_NO)        (REG^=(1<<BIT_NO))




/*********************************************/
/******* GET A CERTAIN BIT IN REGISTER *******/
/*********************************************/
#define GET_BIT(REG,BIT_NO)           ((REG>>BIT_NO)&0b00000001)

/*********************************************/
/**SET A CERTAIN BIT IN REGISTER WITH VALUE **/
/*********************************************/
#define SET_BIT_VALUE(REG,BIT_NO,VALUE)        ( (VALUE == 0) ? ( REG &= ~(1<<BIT_NO) ) : ( REG |= (1<<BIT_NO) ) )

#define Mapping(x1,x2,y1,y2,X)                ( ( ( ( (s32)y2-(s32)y1)*((s32)X-(s32)x1))/( (s32)x2-(s32)x1 ) )  +(s32)y1)
//#define Mapping(INPUT_MIN,INPUT_MAX,OUTPUT_MIN,OUTPUT_MAX,INPUT_VALUE)    ( ( ( ( (s32)INPUT_VALUE - (s32)INPUT_MIN ) * ( (s32)OUTPUT_MAX - (s32)OUTPUT_MIN ) ) / ( (s32)INPUT_MAX - (s32)INPUT_MIN ) ) + (s32)OUTPUT_MIN )
#endif






