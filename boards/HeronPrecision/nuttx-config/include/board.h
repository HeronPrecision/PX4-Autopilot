#ifndef BOARD_H
#define BOARD_H

// ESC1 Motors (Timer 1)
#define ESC1_MOTOR1_PIN    G2   // Motor 1, Timer 1: Channel 1
#define ESC1_MOTOR2_PIN    H2   // Motor 2, Timer 1: Channel 2
#define ESC1_MOTOR3_PIN    J7   // Motor 3, Timer 1: Channel 3
#define ESC1_MOTOR4_PIN    K7   // Motor 4, Timer 1: Channel 4

// ESC2 Motors (Timer 4)
#define ESC2_MOTOR5_PIN    F8   // Motor 5, Timer 4: Channel 1
#define ESC2_MOTOR6_PIN    E8   // Motor 6, Timer 4: Channel 2
#define ESC2_MOTOR7_PIN    J5   // Motor 7, Timer 4: Channel 3
#define ESC2_MOTOR8_PIN    K5   // Motor 8, Timer 4: Channel 4

// ESC3 (CAN in alternate mode, Timer 2)
#define ESC3_MOTOR9_PIN    G2   // Motor 9, Timer 2: Channel 1
#define ESC3_MOTOR10_PIN   H2   // Motor 10, Timer 2: Channel 2
#define ESC3_MOTOR11_PIN   J7   // Motor 11, Timer 2: Channel 3
#define ESC3_MOTOR12_PIN   K7   // Motor 12, Timer 2: Channel 4

// Serial Communication pins (UART)
#define TX1_PIN            H10  // UART1 Tx pin
#define RX1_PIN            D10  // UART1 Rx pin
#define TX2_PIN            J10  // UART2 Tx pin
#define RX2_PIN            G9   // UART2 Rx pin
#define TX3_PIN            K3   // UART3 Tx pin
#define RX3_PIN            K9   // UART3 Rx pin
#define TX4_PIN            A7   // UART4 Tx pin
#define RX4_PIN            A8   // UART4 Rx pin
#define TX5_PIN            E8   // UART5 Tx pin
#define RX5_PIN            F8   // UART5 Rx pin
#define TX6_PIN            F10  // UART6 Tx pin
#define RX6_PIN            D7   // UART6 Rx pin
#define TX7_PIN            J5   // UART7 Tx pin
#define RX7_PIN            D9   // UART7 Rx pin

// SPI pins for BMI270 Gyro 1 
#define BMI1_CS_PIN        G5   // SPI Chip Select for BMI270 Gyro 1
#define BMI1_SCK_PIN       A7   // SPI Clock for BMI270 Gyro 1
#define BMI1_MISO_PIN      A6   // SPI MISO for BMI270 Gyro 1
#define BMI1_MOSI_PIN      C5   // SPI MOSI for BMI270 Gyro 1
#define BMI1_INT_PIN       K4   // BMI270 Interrupt Pin

// SPI pins for BMI270 Gyro 2 (redundant)
#define BMI2_CS_PIN        J5   // SPI Chip Select for BMI270 Gyro 2
#define BMI2_SCK_PIN       B3   // SPI Clock for BMI270 Gyro 2
#define BMI2_MISO_PIN      D3   // SPI MISO for BMI270 Gyro 2
#define BMI2_MOSI_PIN      E3   // SPI MOSI for BMI270 Gyro 2
#define BMI2_INT_PIN       J4   // BMI270 Interrupt Pin

// I2C bus pins
#define I2C1_SCL_PIN       B6   // I2C1 Clock
#define I2C1_SDA_PIN       B7   // I2C1 Data
#define I2C2_SCL_PIN       PB10 // I2C2 Clock
#define I2C2_SDA_PIN       PB11 // I2C2 Data

// CAN bus pins (if needed)
#define CAN1_TX_PIN        D8   // CAN1 Transmit
#define CAN1_RX_PIN        D9   // CAN1 Receive
#define CAN2_TX_PIN        E8   // CAN2 Transmit
#define CAN2_RX_PIN        E9   // CAN2 Receive

// Other sensor/LED pins
#define OTG_FS_VBUS_PIN    C9   // OTG FS VBUS pin
#define BL_LED_PIN         A10  // Blue LED
#define RD_LED_PIN         A9   // Red LED
#define GR_LED_PIN         A8   // Green LED

// SDMMC1 (SD Card) pins
#define SDMMC1_CMD_PIN     B7   // SDMMC Command
#define SDMMC1_CLK_PIN     C12  // SDMMC Clock
#define SDMMC1_D0_PIN      PC8  // SDMMC Data Line 0
#define SDMMC1_D1_PIN      PC9  // SDMMC Data Line 1
#define SDMMC1_D2_PIN      PC10 // SDMMC Data Line 2
#define SDMMC1_D3_PIN      PC11 // SDMMC Data Line 3

// ADC Pins
#define CUR_SNS1_PIN       F3   // Current sensor 1 ADC pin
#define CUR_SNS2_PIN       F4   // Current sensor 2 ADC pin

#endif // BOARD_H
