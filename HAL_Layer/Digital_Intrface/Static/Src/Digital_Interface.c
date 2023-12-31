
/*
 * Digital_Interface.c
 *
 *  Created on: Apr 20, 2023
 *      Author: Abdu
 */


#include "HAL_Layer/Digital_Intrface/Dynamic/inc/Digital_Interface_Cfg.h"
#include "../inc/Digital_Interface.h"
#include <stdlib.h>
#include "MCAL_Layer/DIO/Static/inc/DIO.h"


static void Digital_Interface_WriteHigh(DigitalInterface_Type* const me);
static void Digital_Interface_WriteLow(DigitalInterface_Type* const me);
static void Digital_Interface_Toggle(DigitalInterface_Type* const me);


static void Digital_Interface_WriteHigh(DigitalInterface_Type* const me){
    me->Dio_Level = DIO_Level_HIGH;
    Dio_WriteChannel(me->Dio_Ch, DIO_Level_HIGH);
}

static void Digital_Interface_WriteLow(DigitalInterface_Type* const me){
    me->Dio_Level = DIO_Level_LOW;
    Dio_WriteChannel(me->Dio_Ch, DIO_Level_LOW);
}

static void Digital_Interface_Toggle(DigitalInterface_Type* const me){
    if(me->Dio_Level == DIO_Level_HIGH){
        me->Write_Low(me);
    }else{
        me->Write_High(me);
    }
}

DigitalInterface_Type* Digital_Interface_Create(DIO_ChannelType DIO_CH){
    DigitalInterface_Type* me;
    me = (DigitalInterface_Type*)malloc(sizeof(DigitalInterface_Type));
    if(me != Null_Ptr){
        me->Write_High = Digital_Interface_WriteHigh;
        me->Write_Low = Digital_Interface_WriteLow;
        me->Write_Toggle = Digital_Interface_Toggle;
        me->Dio_Ch = DIO_CH;
    }
    return me;
}

void Digital_Interface_Destroy(DigitalInterface_Type* me){
    if(me != Null_Ptr){
        free(me);
    }
}

