/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Atmega32_Drivers                                    	 
// File          : twi_private.h                                  	     
// Date          : 22 Aug 2023
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

#define TWBR_REG	*((vuint8_t *)0x20)
#define TWCR_REG	*((vuint8_t *)0x56)
#define TWSR_REG	*((vuint8_t *)0x21)
#define TWDR_REG	*((vuint8_t *)0x23)
#define TWAR_REG	*((vuint8_t *)0x22)

// TWCR_REG Bits

#define TWINT_BIT		7
#define TWEA_BIT		6
#define TWSTA_BIT 		5
#define TWSTO_BIT		4
#define TWWC_BIT		3
#define TWEN_BIT		2
#define RESERVED_BIT	1
#define TWIE_BIT		0


// TWSR_REG Bits

#define TWS7_BIT		7
#define TWS6_BIT		6
#define TWS5_BIT		5
#define TWS4_BIT		4
#define TWS3_BIT		3
#define RESERVED_BIT	2
#define TWPS1_BIT		1
#define TWPS0_BIT		0

// TWAR_REG Bits

#define TWGCE_BIT	    0


/* TWI Status Bits in the TWSR Register */

#define TWI_START         				0x08   // Start condition transmitted
#define TWI_REP_START     				0x10   // Repeated start condition transmitted
#define TWI_MT_SLA_ACK    				0x18   // SLA+W transmitted, ACK received
#define TWI_MT_SLA_NACK   				0x20   // SLA+W transmitted, NACK received
#define TWI_MT_DATA_ACK   				0x28   // Data byte transmitted, ACK received
#define TWI_MT_DATA_NACK 				0x30   // Data byte transmitted, NACK received
#define TWI_MR_SLA_ACK    				0x40   // SLA+R transmitted, ACK received
#define TWI_MR_SLA_NACK   				0x48   // SLA+R transmitted, NACK received
#define TWI_MR_DATA_ACK   				0x50   // Data byte received, ACK returned
#define TWI_MR_DATA_NACK  				0x58   // Data byte received, NACK returned
#define TWI_ST_SLA_ACK    				0xA8   // SLA+R received, ACK returned
#define TWI_ST_ARB_LOST_SLA_ACK 	 	0xB0   // Arbitration lost, SLA+R received, ACK returned
#define TWI_ST_DATA_ACK   				0xB8   // Data byte transmitted, ACK received
#define TWI_ST_DATA_NACK  				0xC0   // Data byte transmitted, NACK received
#define TWI_ST_LAST_DATA_ACK    		0xC8   // Last data byte transmitted, ACK received
#define TWI_SR_SLA_ACK   				0x60   // SLA+W received, ACK returned
#define TWI_SR_ARB_LOST_SLA_ACK  		0x68   // Arbitration lost, SLA+W received, ACK returned
#define TWI_SR_GCALL_ACK    			0x70   // General call received, ACK returned
#define TWI_SR_ARB_LOST_GCALL_ACK  		0x78   // Arbitration lost, General call received, ACK returned
#define TWI_SR_DATA_ACK   				0x80   // Data byte received, ACK returned
#define TWI_SR_DATA_NACK  				0x88   // Data byte received, NACK returned
#define TWI_SR_GCALL_DATA_ACK    		0x90   // General call data received, ACK returned
#define TWI_SR_GCALL_DATA_NACK   		0x98   // General call data received, NACK returned
#define TWI_SR_STOP       				0xA0   // Stop or repeated start condition received while selected
#define TWI_NO_INFO       				0xF8   // No relevant state information available TWINT = 0
#define TWI_BUS_ERROR     				0x00   // Bus error due to illegal start or stop condition



#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
