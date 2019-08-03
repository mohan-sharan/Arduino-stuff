#include <Servo.h>
Servo s;
int servo_position = 0;
int servo_pin = 10;

int led_pin_1 = 5;
int led_pin_2 = 6;
int button_1 = 8;
int button_2 = 9;

void setup() {
  pinMode(led_pin_1, OUTPUT);
  pinMode(led_pin_2, OUTPUT);
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  s.attach(servo_pin);
}

void loop()
{
  while (servo_position < 90 && digitalRead(button_1) == HIGH) {
    servo_position++;
    s.write(servo_position);
    digitalWrite(led_pin_1, HIGH);
    digitalWrite(led_pin_2, LOW);
    delay(10);
  }
  while (servo_position > 0 && digitalRead(button_2) == HIGH) {
    servo_position--;
    s.write(servo_position);
    digitalWrite(led_pin_2, HIGH);
    digitalWrite(led_pin_1, LOW);
    delay(10);
  }
}
