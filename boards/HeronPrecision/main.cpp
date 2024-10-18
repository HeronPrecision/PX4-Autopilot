#include "stm32h7xx_hal.h"
#include "bmi270.h"  // Assuming BMI270 driver is included or implemented??
#include "board.h"

// Define SPI Pins for both BMI270
#define SPI_SCK_PIN      GPIO_PIN_13   // Clock pin (shared)
#define SPI_MISO_PIN     GPIO_PIN_14   // Master In Slave Out (shared)
#define SPI_MOSI_PIN     GPIO_PIN_15   // Master Out Slave In (shared)
#define BMI270_CS1_PIN   GPIO_PIN_12   // Chip Select for first BMI270
#define BMI270_CS2_PIN   GPIO_PIN_10   // Chip Select for second BMI270

// Define Data Ready Interrupt Pins
#define BMI270_DRDY1_PIN GPIO_PIN_4    // Data Ready pin for first BMI270
#define BMI270_DRDY2_PIN GPIO_PIN_4    // Data Ready pin for second BMI270

// GPIO Port for SPI and BMI270
#define BMI270_GPIO_PORT GPIOB

// SPI Handle
SPI_HandleTypeDef hspi1;

// Function Prototypes
void SystemClock_Config(void);
void Error_Handler(void);
void GPIO_Init(void);
void SPI_Init(void);
void BMI270_Init(SPI_HandleTypeDef* hspi, uint16_t cs_pin);
void EXTI4_IRQHandler(void);

int main(void) {
    GPIO_Init();
    SPI_Init();
    SystemClock_Config();
    HAL_Init();

    // Initialize both BMI270 sensors
    BMI270_Init(&hspi1, BMI270_CS1_PIN);  // First BMI270
    BMI270_Init(&hspi1, BMI270_CS2_PIN);  // Second BMI270 (redundant) 

    // Main logic (gyroscope, data, processing)
    while (1) {
        // TO:DO
    }
}

// Initializes the GPIO 
void GPIO_Init(void) {
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // SPI SCK, MOSI, MISO Pins
    GPIO_InitStruct.Pin = SPI_SCK_PIN | SPI_MISO_PIN | SPI_MOSI_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;  // Alternate function for SPI1
    HAL_GPIO_Init(BMI270_GPIO_PORT, &GPIO_InitStruct);

    // BMI270 CS1 Pin
    GPIO_InitStruct.Pin = BMI270_CS1_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(BMI270_GPIO_PORT, &GPIO_InitStruct);

    // BMI270 CS2 Pin
    GPIO_InitStruct.Pin = BMI270_CS2_PIN;
    HAL_GPIO_Init(BMI270_GPIO_PORT, &GPIO_InitStruct);

    // BMI270 DRDY Pins
    GPIO_InitStruct.Pin = BMI270_DRDY1_PIN | BMI270_DRDY2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(BMI270_GPIO_PORT, &GPIO_InitStruct);

    // Enable and set EXTI Line 4 Interrupt to the highest priority
    HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

// SPI Initialization
void SPI_Init(void) {
    __HAL_RCC_SPI1_CLK_ENABLE();

    hspi1.Instance = SPI1;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 10;
    if (HAL_SPI_Init(&hspi1) != HAL_OK) {
        Error_Handler();
    }
}

// BMI270 Initialization
void BMI270_Init(SPI_HandleTypeDef* hspi, uint16_t cs_pin) {
    // Select the sensor (CS Low)
    HAL_GPIO_WritePin(BMI270_GPIO_PORT, cs_pin, GPIO_PIN_RESET);

    // Send initialization commands to BMI270
    uint8_t data[] = {0x7E, 0x11};  // Reset 
    HAL_SPI_Transmit(hspi, data, sizeof(data), HAL_MAX_DELAY);

    // Deselect the sensor (CS High)
    HAL_GPIO_WritePin(BMI270_GPIO_PORT, cs_pin, GPIO_PIN_SET);
}

// EXTI interrupt handler for data-ready
void EXTI4_IRQHandler(void) {
    // Clear the interrupt flag
    HAL_GPIO_EXTI_IRQHandler(BMI270_DRDY1_PIN);

    // TO:DO Read data from BMI270 here?
}

// System Clock Configuration
void SystemClock_Config(void) {
    // TO:DO 
}

// Error Handler
void Error_Handler(void) {
    // TO:DO 
}