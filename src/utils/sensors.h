#include <Arduino.h>

const uint8_t MOISTURE_SENSOR_PORT = A0;
const uint8_t WATER_LEVEL_SENSOR_PORT = A1;

struct Sensors
{
    int moisture;
    int waterLevel;
} sensors;

Sensors getSensorsValues(void)
{
    sensors.moisture = analogRead(MOISTURE_SENSOR_PORT);
    sensors.waterLevel = analogRead(WATER_LEVEL_SENSOR_PORT);

    return sensors;
}