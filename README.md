# HX711-Library-for-STM32F4

### Setup
* Set PD_SCK pin as GPIO_Output. 
* Set DOUT pin as GPIO_Input. 

### Example
```
HX711 sensor;
sensor.PD_SCK_PinType=GPIOE;
sensor.PD_SCK_PinNumber=GPIO_PIN_11;
sensor.DOUT_PinType=GPIOE;
sensor.DOUT_PinNumber=GPIO_PIN_12;
sensor.mode=0;
int read = HX711_Read(&sensor);
```
