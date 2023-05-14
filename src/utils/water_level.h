#include <Arduino.h>

const int dryWaterSensorValue = 420; // value for dry sensor
const int wetWaterSensorValue = 682; // value for wet sensor

int calcWaterLevel(int sensorValue) {
    const int waterLevel = map(sensorValue, wetWaterSensorValue, dryWaterSensorValue, 100, 0);
    
    return waterLevel > 0 ? waterLevel : 0; // water sensor return 0 when it dry, but if we place it for 1mm to water it return 420. This helps to avoid negative values.
}