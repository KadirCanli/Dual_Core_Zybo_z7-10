/*
 * uart.h
 *
 *  Created on: Jun 17, 2025
 *      Author: blue
 */

#ifndef SRC_UART_H_
#define SRC_UART_H_

#include "xuartlite.h"
#include "xparameters.h"


int uart_initialize(XUartLite *uart, XUartLite_Config **config, u16 device_id);
void uart_send_data(XUartLite *uart, u8 *data, u32 size);
u32 uart_receive_data(XUartLite *uart, u8 *buffer, u32 buffer_size);
void daytv_response(XUartLite *uart);

#endif /* SRC_UART_H_ */
