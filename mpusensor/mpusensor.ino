#include <MPU9250_asukiaaa.h>
 
#define SDA_PIN 21
#define SCL_PIN 22
 
MPU9250 mySensor;

uint8_t sensorId;
float aX, aY, aZ, aSqrt, gX, gY, gZ, mDirection, mX, mY, mZ;

void setup() {
  while(!Serial);
  Serial.begin(115200);
  Serial.println("started");

  Wire.begin(SDA_PIN, SCL_PIN); // SDA, SCL

  mySensor.setWire(&Wire);
  mySensor.beginAccel();
  mySensor.beginGyro();
  mySensor.beginMag();

  // You can set your own offset for mag values
  // mySensor.magXOffset = -50;
  // mySensor.magYOffset = -55;
  // mySensor.magZOffset = -10;

  sensorId = mySensor.readId();
}

void loop() {
  Serial.println("sensorId: " + String(sensorId));

  mySensor.accelUpdate();
  aX = mySensor.accelX();
  aY = mySensor.accelY();
  aZ = mySensor.accelZ();
  aSqrt = mySensor.accelSqrt();
  Serial.println("accelX: " + String(aX));
  Serial.println("accelY: " + String(aY));
  Serial.println("accelZ: " + String(aZ));
  Serial.println("accelSqrt: " + String(aSqrt));

  mySensor.gyroUpdate();
  gX = mySensor.gyroX();
  gY = mySensor.gyroY();
  gZ = mySensor.gyroZ();
  Serial.println("gyroX: " + String(gX));
  Serial.println("gyroY: " + String(gY));
  Serial.println("gyroZ: " + String(gZ));

  mySensor.magUpdate();
  mX = mySensor.magX();
  mY = mySensor.magY();
  mZ = mySensor.magZ();
  mDirection = mySensor.magHorizDirection();
  Serial.println("magX: " + String(mX));
  Serial.println("maxY: " + String(mY));
  Serial.println("magZ: " + String(mZ));
  Serial.println("horizontal direction: " + String(mDirection));

  Serial.println("at " + String(millis()) + "ms");
  Serial.println(""); // Add an empty line
  delay(500);
}
