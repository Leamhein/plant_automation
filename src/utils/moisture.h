#include <Arduino.h>

const int dry = 560; // value for dry sensor
const int wet = 430; // value for wet sensor

int calcMoisturePercentage(int sensorValue) {
    return map(sensorValue, wet, dry, 100, 0);
}