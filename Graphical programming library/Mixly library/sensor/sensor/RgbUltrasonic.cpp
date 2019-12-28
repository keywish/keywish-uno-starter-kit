#include "RgbUltrasonic.h"

RgbUltrasonic::RgbUltrasonic(byte signal_pin, byte rgb_pin)
{
    SignalPin = signal_pin;
    RgbPin = rgb_pin;
    mRgb = new RGBLed(RgbPin, 6);
}

uint16_t RgbUltrasonic::GetUltrasonicDistance(void)
{
  float distance;
  unsigned long Time_Echo_us = 0;
  pinMode(SignalPin, OUTPUT);
  digitalWrite(SignalPin, LOW);
  delayMicroseconds(2);
  digitalWrite(SignalPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(SignalPin, LOW);
  pinMode(SignalPin, INPUT);
  Time_Echo_us = pulseIn(SignalPin, HIGH);
  if ((Time_Echo_us < 60000) && (Time_Echo_us > 1)) {
      FrontDistance = Time_Echo_us / 58.00;
      Serial.print("distance is :");
      Serial.print(FrontDistance);
      Serial.print("cm");
      Serial.println();  
  }
    return FrontDistance;
}

void RgbUltrasonic::SetRgbIndexColor(int start_index, int end_index, long Color)
{
    for (byte i = start_index; i <= end_index; i++) {
        mRgb->setColor(i, Color);
    }
    mRgb->show();
}


void RgbUltrasonic::SetRgbEffect(E_RGB_INDEX index, long Color, uint8_t effect = E_EFFECT_NONE)
{
	  byte start = 1, end = 6;
    if (index == E_RGB_RIGHT) {
        start = 4;
        end = 6;
    } else if (index == E_RGB_LEFT) {
        start = 1;
        end = 3;
    }

    switch((E_RGB_EFFECT)effect) {
		case E_EFFECT_NONE:
        //Serial.println("E_EFFECT_NONE");
		    SetRgbIndexColor(start, end, Color);
			  break;
    case E_EFFECT_BREATHING:
        //Serial.println("E_EFFECT_BREATHING");
        for (int i = 0; i < 256; i++) {
            mRgb->setBrightness(i);
            SetRgbIndexColor(start, end, Color);
            //delay((255 - i)/2);
            delay((i < 20)? 60 :(255/i));
        }
        for (int i = 255; i >= 0; i--) {
            mRgb->setBrightness(i);
            SetRgbIndexColor(start, end, Color);
            delay((i < 20)? 60 :(255/i));
        }
        mRgb->setBrightness(255);
        break;
    case E_EFFECT_ROTATE:
        //Serial.println("E_EFFECT_ROTATE");
		for (byte i = 0; i < 4; i++) {
			mRgb->setColor(start, Color);
			mRgb->setColor(start+1, 0);
			mRgb->setColor(start+2, 0);
			if (index == E_RGB_ALL) {
				mRgb->setColor(end-2, Color);
				mRgb->setColor(end-1, 0);
				mRgb->setColor(end, 0);
			}
			mRgb->show();
			delay(150);
			mRgb->setColor(start, 0);
			mRgb->setColor(start+1, Color);
			mRgb->setColor(start+2, 0);
			if (index == E_RGB_ALL) {
				mRgb->setColor(end-2, 0);
				mRgb->setColor(end-1, Color);
				mRgb->setColor(end, 0);
			}
			mRgb->show();
			delay(150);
			mRgb->setColor(start, 0);
			mRgb->setColor(start+1, 0);
			mRgb->setColor(start+2, Color);
			if (index == E_RGB_ALL) {
				mRgb->setColor(end-2, 0);
				mRgb->setColor(end-1, 0);
				mRgb->setColor(end, Color);
			}
			mRgb->show();
			delay(150);
		}
		SetRgbIndexColor(1, 6, 0);
		break;
      case E_EFFECT_FLASH:
          //Serial.println("E_EFFECT_FLASH");
          for (byte i = 0; i < 6; i++) {
              SetRgbIndexColor(start, end, Color);
              delay(150);
              SetRgbIndexColor(start, end, 0);
              delay(150);
          }
          break;
      }
}
