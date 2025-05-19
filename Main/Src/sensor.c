/*
 * sensor.c
 */

#include "main.h"
#include "sensor.h"

__STATIC_INLINE uint16_t Sensor_ADC_Read() {
	__disable_irq();
	LL_ADC_ClearFlag_EOC(ADC1);
	LL_ADC_REG_StartConversion(ADC1);
	while (!LL_ADC_IsActiveFlag_EOC(ADC1))
		;
	uint16_t adcValue = LL_ADC_REG_ReadConversionData12(ADC1);
	__enable_irq();
	return adcValue;
}

void Sensor_TIM6_IRQ() {

}
