/* Arduino USB HID Keyboard Demo
 * Random Key/Random Delay
 */
#define KEY_F5  0x3e
uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */

void setup() 
{
  Serial.begin(9600);
  
  delay(200);
}

void loop() 
{
  delay(60000);

  buf[2] = KEY_F5;    // f5
  Serial.write(buf, 8); // Send keypress
  releaseKey();
  
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}
