#include <Wire.h> // For I2C communication

int ADXL345= 0x53; //
float X_axis, Y_axis, Z_axis;
float roll,pitch,rollF,pitchF=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Wire.begin();
Wire.beginTransmission(ADXL345);
Wire.write(0x2D);// address for the register
Wire.write(8); // D3 is for enabling measurement (8 is dec equivalent for 0000 1000)
Wire.endTransmission();
delay(100);
// Calibration
//X-Axis
Wire.beginTransmission(ADXL345);
Wire.write(0x1E);
Wire.write(1);
Wire.endTransmission();
delay(10);
//Y-axis
Wire.beginTransmission(ADXL345);
Wire.write(0x1F);
Wire.write(-2);
Wire.endTransmission();
delay(10);
//Z-axis
Wire.beginTransmission(ADXL345);
Wire.write(0x20);
Wire.write(-9);
Wire.endTransmission();
delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:
Wire.beginTransmission(ADXL345);
Wire.write(0x32);
Wire.endTransmission(false);
Wire.requestFrom(ADXL345,6,true);

X_axis=(Wire.read() | Wire.read() << 8);
X_axis = X_axis / 256;
Y_axis=(Wire.read() | Wire.read() << 8);
Y_axis = Y_axis / 256;
Z_axis=(Wire.read() | Wire.read() << 8);
Z_axis = Z_axis / 256;


Serial.print(X_axis);
Serial.print(" ");
Serial.print(Y_axis);
Serial.print(" ");
Serial.println(Z_axis);


}

