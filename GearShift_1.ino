/* inspired by 7-segment-display: playground2014.wordpress.com
 * original gear shift indicator design by George MACIU & Nicu FLORICA (niq_ro)
 * http://www.tehnic.go.ro/ & http://www.arduinotehniq.com/
 * http://nicuflorica.blogspot.ro/ & http://arduinotehniq.blogspot.com/
*/

byte digitArray[12][7] =  // {a,b,c,d,e,f,g}
 { 
 { 1,1,1,1,1,1,0 }, // = 0
 { 0,1,1,0,0,0,0 }, // = 1
 { 1,1,0,1,1,0,1 }, // = 2
 { 1,1,1,1,0,0,1 }, // = 3
 { 0,1,1,0,0,1,1 }, // = 4
 { 1,0,1,1,0,1,1 }, // = 5
 { 1,0,1,1,1,1,1 }, // = 6
 { 1,1,1,0,0,0,0 }, // = 7
 { 1,1,1,1,1,1,1 }, // = 8
 { 1,1,1,0,0,1,1 }, // = 9
 { 0,0,0,0,0,0,0 }, // = off
 { 1,1,0,0,1,1,1 } // = P
 };
int clipire = 0;
 
void setup() {
 pinMode(2, OUTPUT); // kingbrigth - a
 pinMode(3, OUTPUT); // kingbrigth - b
 pinMode(4, OUTPUT); // kingbrigth - c
 pinMode(5, OUTPUT); // kingbrigth - d
 pinMode(6, OUTPUT); // kingbrigth - e
 pinMode(7, OUTPUT); // kingbrigth - f
 pinMode(8, OUTPUT); // kingbrigth - g

 pinMode(9, INPUT); // parking, D9
 pinMode(10, INPUT); // 1st gear, D10
 pinMode(11, INPUT); // 2nd gear, D11
 pinMode(12, INPUT); // 3rd gear, D12
 pinMode(14, INPUT); // 4rd gear, D14 (A0)
 pinMode(15, INPUT); // 5rd gear, D15 (A1)
 pinMode(16, INPUT); // 6rd gear, D16 (A2)
 pinMode(17, INPUT); // reverse gear, D17 (A3) 

digitalWrite(10, HIGH); // pull-up the internal resistor
digitalWrite(11, HIGH); // pull-up the internal resistor
digitalWrite(12, HIGH); // pull-up the internal resistor
digitalWrite(13, HIGH); // pull-up the internal resistor
digitalWrite(14, HIGH); // pull-up the internal resistor
digitalWrite(15, HIGH); // pull-up the internal resistor
digitalWrite(16, HIGH); // pull-up the internal resistor
digitalWrite(17, HIGH); // pull-up the internal resistor
}

// we define a function to display one digit
void setDigit(byte digit) {
 byte pin=2;
 for (byte i = 0; i < 7; ++i) {
 digitalWrite(pin, digitArray[digit][i]);
 ++pin;
 }
}

void loop() {

if (digitalRead(9) == LOW) setDigit(11);  // parking
else
if (digitalRead(10) == LOW) setDigit(1);  // 1st gear
else
if (digitalRead(11) == LOW) setDigit(2);  // 2nd gear
else
if (digitalRead(12) == LOW) setDigit(3);  // 3rd gear
else
if (digitalRead(14) == LOW) setDigit(4);  // 4rd gear
else
if (digitalRead(15) == LOW) setDigit(5);  // 5rd gear
else
if (digitalRead(16) == LOW) setDigit(6);  // 6rd gear
else
//if (digitalRead(17) == LOW) setDigit(0);  // reverse
if (digitalRead(17) == LOW)
{
if (clipire%2 == 1) setDigit(0);  // parking
else setDigit(10);  
}
else
setDigit(10);  // display off
delay(100);
clipire = clipire + 1;
}
