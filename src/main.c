/*
 * main.c
 *
 *  Created on: Feb 27, 2017
 *      Author: KahLok
 */


#include "stm32f4xx.h"

#include "defines.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_onewire.h"
//#include "tm_stm32f4_usart.h"
#include <stdio.h>
#include "tm_stm32f4_ds18b20.h"
#include "tm_stm32f4_disco.h"

int main(void) {
    char buf[40];
    uint8_t devices, i, j, count, device[1][8];
    uint8_t alarm_count;
	uint8_t alarm_device[1][8];
	float temp[1];
    /* OneWire working structure */
    TM_OneWire_t OneWire;

    /* Initialize system */
    SystemInit();

    /* Initialize delay */
    TM_DELAY_Init();

    /* Initialize OneWire1 instance on pin PD0 */
    TM_OneWire_Init(&OneWire, GPIOA, GPIO_Pin_10);
    TM_GPIO_Init(GPIOA, GPIO_Pin_5, TM_GPIO_Mode_OUT, TM_GPIO_OType_OD, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Medium);
    /* Initialize USART, TX: PB6, RX: PB7 */
   // TM_USART_Init(USART1, TM_USART_PinsPack_2, 115200);

    /* Check for any device on 1-wire */
    devices = TM_OneWire_First(&OneWire);
    count = 0;
    while (devices) {
        /* Increase count variable */
        count++;

        /* Get full 8-bytes rom address */
        TM_OneWire_GetFullROM(&OneWire, device[count - 1]);

        /* Check for new device */
        devices = TM_OneWire_Next(&OneWire);
    }


    /* If any devices on 1-wire */
  //  if (count > 0) {
  //      sprintf(buf, "Devices found on 1-wire instance: %d\n", count);
    //    TM_USART_Puts(USART1, buf);

        /* Display 64bit rom code */
   /*     for (j = 0; j < count; j++) {
            for (i = 0; i < 8; i++) {
                sprintf(buf, "0x%02X ", device[j][i]);
                TM_USART_Puts(USART1, buf);
            }
            TM_USART_Puts(USART1, "\n");
        }  */
//    } else {
        /* Nothing on OneWire */
  //      TM_USART_Puts(USART1, "No devices on OneWire.\n\n");
  //  }


    /* Go through all connected devices and set resolution to 12bits */
        for (i = 0; i < count; i++) {
            /* Set resolution to 12bits */
            TM_DS18B20_SetResolution(&OneWire, device[i], TM_DS18B20_Resolution_12bits);
        }

        /* Set high temperature alarm on device number 0, 25 degrees celcius */
        TM_DS18B20_SetAlarmHighTemperature(&OneWire, device[0], 70);

        TM_DS18B20_SetAlarmLowTemperature(&OneWire , device[0], -20);

        /* Disable alarm temperatures on device number 1 */
        TM_DS18B20_DisableAlarmTemperature(&OneWire, device[1]);

        while (1) {
            /* Start temperature conversion on all devices on one bus */
            TM_DS18B20_StartAll(&OneWire);

            /* Wait until all are done on one onewire port */
            while (!TM_DS18B20_AllDone(&OneWire));

            /* Read temperature from ROM address and store it to temps variable */
            TM_DS18B20_Read(&OneWire, device[0], &temp[0]);
            TM_GPIO_TogglePinValue(GPIOA, GPIO_Pin_5);

                }

}


