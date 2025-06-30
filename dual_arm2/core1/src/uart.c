/*
 * uart.c
 *
 *  Created on: Jun 17, 2025
 *      Author: blue
 */


#include "uart.h"

#include "xil_printf.h"


int uart_initialize(XUartLite *uart, XUartLite_Config **config, u16 device_id){
	*config = XUartLite_LookupConfig(device_id);
	if(*config == NULL){
		xil_printf("uart config not found \n\r");
		return XST_FAILURE;
	}

	int status = XUartLite_CfgInitialize(uart, *config, (*config)->RegBaseAddr);
	if(status != XST_SUCCESS){
		xil_printf("uart not initialize \n\r");
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}




void uart_send_data(XUartLite *uart, u8 *data, u32 size){
	for(u32 i =0; i< size;++i){
		XUartLite_Send(uart, &data[i], 1);
		while(XUartLite_IsSending(uart));
	}
}

u32 uart_receive_data(XUartLite *uart, u8 *buffer, u32 buffer_size){
	u32 received =0;

	while(received < buffer_size)
	{
		u32 bytes = XUartLite_Recv(uart, &buffer[received], 1);
		if(bytes> 0){
			received += bytes;
		}
		else
		{
			break;
		}
	}
	return received;
}

















