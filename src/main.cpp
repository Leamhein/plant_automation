#include <Adafruit_SSD1306.h>
#include <assets/icons.h>
#include <utils/moisture.h>
#include <utils/water_level.h>
#include <utils/sensors.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(126, 32, &Wire, OLED_RESET);


void drawWaterSensorLevel(int waterLevel) {
	display.clearDisplay();
	display.drawBitmap(10, 0, water_level_icon, 32, 32, 1);
	display.setCursor(50, 7);
	display.print(waterLevel);
	display.println('%');
	display.display();
}

void drawMoistureSensorValue(int moisture) {
	display.clearDisplay();
	display.drawBitmap(10, 0, moisture_icon, 32, 32, 1);
	display.setCursor(50, 7);
	display.print(moisture);
	display.println('%');
	display.display();
}

void setup()
{
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display.setTextSize(3);
}

void loop()
{
	Sensors sensorsValues = getSensorsValues();

	drawWaterSensorLevel(sensorsValues.waterLevel);
	delay(4000);
	drawMoistureSensorValue(sensorsValues.moisture);
	delay(4000);
}
