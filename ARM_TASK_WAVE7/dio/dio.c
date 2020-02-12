/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "utils/Bit_Math.h"
#include "utils/STD_Types.h"
#include "mcal/mcu_hw.h"
/*TODO: include the header file that contains register definitions */

#include "dio.h"

uint32* ptr_portA_add = (uint32*) PORTA_BaseAddr;
uint32* ptr_portB_add = (uint32*) PORTB_BaseAddr;
uint32* ptr_portC_add = (uint32*) PORTC_BaseAddr;
uint32* ptr_portD_add = (uint32*) PORTD_BaseAddr;
uint32* ptr_portE_add = (uint32*) PORTE_BaseAddr;
uint32* ptr_portF_add = (uint32*) PORTF_BaseAddr;

uint8 gau8_Pins_LUT[8] = { 0x01, 0x02, 0x4, 0x08, 0x10, 0x20, 0x40, 0x80 };

Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Std_levelType ret;
    Dio_PortType PortId = (Dio_PortType) (ChannelId / 8);
    Dio_ChannelType ChannelPos = (Dio_ChannelType) (ChannelId % 8);

    switch (PortId)
    {
    case Dio_Port_A:
        ret = (Std_levelType) (((*ptr_portA_add) & gau8_Pins_LUT[ChannelPos])
                >> ChannelPos);
        break;

    case Dio_Port_B:
        ret = (Std_levelType) (((*ptr_portB_add) & gau8_Pins_LUT[ChannelPos])
                >> ChannelPos);
        break;

    case Dio_Port_C:
        ret = (Std_levelType) (((*ptr_portC_add) & gau8_Pins_LUT[ChannelPos])
                >> ChannelPos);
        break;

    case Dio_Port_D:
        ret = (Std_levelType) (((*ptr_portD_add) & gau8_Pins_LUT[ChannelPos])
                >> ChannelPos);
        break;

    case Dio_Port_E:
        ret = (Std_levelType) (((*ptr_portE_add) & gau8_Pins_LUT[ChannelPos])
                >> ChannelPos);
        break;

    case Dio_Port_F:
        ret = (Std_levelType) (((*ptr_portF_add) & gau8_Pins_LUT[ChannelPos])
                >> ChannelPos);
        break;

    default:
        break;
    }

    /*TODO: Return the level value of given Channel ***done*/

    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{

    Dio_PortType PortId = (Dio_PortType) (ChannelId / 8);
    Dio_ChannelType ChannelPos = (Dio_ChannelType) (ChannelId % 8);
    switch (PortId)
    {
    case Dio_Port_A:
        if (Level == STD_high)
        {
            (*ptr_portA_add) |= (gau8_Pins_LUT[ChannelPos]);
        }
        else
        {
            (*ptr_portA_add) &= !(gau8_Pins_LUT[ChannelPos]);
        }
        break;

    case Dio_Port_B:
        if (Level == STD_high)
        {
            (*ptr_portB_add) |= (gau8_Pins_LUT[ChannelPos]);
        }
        else
        {
            (*ptr_portB_add) &= !(gau8_Pins_LUT[ChannelPos]);
        }
        break;

    case Dio_Port_C:
        if (Level == STD_high)
        {
            (*ptr_portC_add) |= (gau8_Pins_LUT[ChannelPos]);
        }
        else
        {
            (*ptr_portC_add) &= !(gau8_Pins_LUT[ChannelPos]);
        }
        break;

    case Dio_Port_D:
        if (Level == STD_high)
        {
            (*ptr_portD_add) |= (gau8_Pins_LUT[ChannelPos]);
        }
        else
        {
            (*ptr_portD_add) &= !(gau8_Pins_LUT[ChannelPos]);
        }
        break;

    case Dio_Port_E:
        if (Level == STD_high)
        {
            (*ptr_portE_add) |= (gau8_Pins_LUT[ChannelPos]);
        }
        else
        {
            (*ptr_portE_add) &= !(gau8_Pins_LUT[ChannelPos]);
        }
        break;

    case Dio_Port_F:
        if (Level == STD_high)
        {
            (*ptr_portF_add) |= (gau8_Pins_LUT[ChannelPos]);
        }
        else
        {
            (*ptr_portF_add) &= !(gau8_Pins_LUT[ChannelPos]);
        }
        break;

    default:
        break;
    }

    /*TODO: Write the input value in the corresponding ChannelId */
}

uint8 Dio_ReadPort(Dio_PortType PortId)
{
    uint8 ret;

    switch (PortId)
    {
    case Dio_Port_A:
        ret = *ptr_portA_add;
        break;

    case Dio_Port_B:
        ret = *ptr_portB_add;
        break;

    case Dio_Port_C:
        ret = *ptr_portC_add;
        break;

    case Dio_Port_D:
        ret = *ptr_portD_add;
        break;

    case Dio_Port_E:
        ret = *ptr_portE_add;
        break;

    case Dio_Port_F:
        ret = *ptr_portF_add;
        break;

    default:
        break;
    }

    /*TODO: Return the Port Value*/

    return ret;
}
void Dio_WritePort(Dio_PortType PortId, uint8 value)
{
    switch (PortId)
    {
    case Dio_Port_A:
        *ptr_portA_add = value;
        break;

    case Dio_Port_B:
        *ptr_portB_add = value;
        break;

    case Dio_Port_C:
        *ptr_portC_add = value;
        break;

    case Dio_Port_D:
        *ptr_portD_add = value;
        break;

    case Dio_Port_E:
        *ptr_portE_add = value;
        break;

    case Dio_Port_F:
        *ptr_portF_add = value;
        break;

    default:
        break;
    }

    /*TODO: Write the input value in the corresponding PortId */

}
void Dio_FlipChannel(Dio_ChannelType ChannelId)
{

    Dio_PortType PortId = (Dio_PortType) (ChannelId / 8);
    Dio_ChannelType ChannelPos = (Dio_ChannelType) (ChannelId % 8);

    switch (PortId)
    {

    case Dio_Port_A:
        *ptr_portA_add ^= (gau8_Pins_LUT[ChannelPos]);
        break;
    case Dio_Port_B:
        *ptr_portB_add ^= (gau8_Pins_LUT[ChannelPos]);
        break;
    case Dio_Port_C:
        *ptr_portC_add ^= (gau8_Pins_LUT[ChannelPos]);
        break;
    case Dio_Port_D:
        *ptr_portD_add ^= (gau8_Pins_LUT[ChannelPos]);
        break;
    case Dio_Port_E:
        *ptr_portE_add ^= (gau8_Pins_LUT[ChannelPos]);
        break;
    case Dio_Port_F:
        *ptr_portF_add ^= (gau8_Pins_LUT[ChannelPos]);
        break;
    default:
        break;

    }

    /* TODO: toggle the corresponding ChannelId */
}
void Dio_FlipPort(Dio_PortType PortId)
{

    switch (PortId)
    {
    case Dio_Port_A:
        *ptr_portA_add = (*ptr_portA_add) ^ 0XFF;
        break;

    case Dio_Port_B:
        *ptr_portB_add ^= 0XFF;
        break;

    case Dio_Port_C:
        *ptr_portC_add ^= 0XFF;
        break;

    case Dio_Port_D:
        *ptr_portD_add ^= 0XFF;
        break;

    case Dio_Port_E:
        *ptr_portE_add ^= 0XFF;
        break;

    case Dio_Port_F:
        *ptr_portF_add ^= 0XFF;
        break;

    default:
        break;
    }

    /*TODO: toggle the port value */

}

