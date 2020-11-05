#include "Inkplate6Plus.h"
Inkplate display(INKPLATE_1BIT);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  display.begin();
  // Init touchscreen and power it on after init (send false as argument to put it in deep sleep right after init)
  if (display.tsInit(true))
  {
    Serial.println("Touchscreen init ok");
  }
  else
  {
    Serial.println("Touchscreen init fail");
    while (true);
  }
}

void loop()
{
  // Check if there is any touch detected
  if (display.tsAvailable())
  {
    uint8_t n;
    uint16_t x[2], y[2];

    // See how many fingers are detected (max 2) and copy x and y position of each finger on touchscreen
    n = display.tsGetData(x, y);
    if (n != 0)
    {
      Serial.printf("%d finger%c ", n, n > 1 ? 's' : NULL);
      for (int i = 0; i < n; i++)
      {
        Serial.printf("X=%d Y=%d ", x[i], y[i]);
      }
      Serial.println();
    } else {
      x[0] = 0;
      x[1] = 0;
      y[0] = 0;
      y[1] = 0;
      Serial.println("Release");
    }
  }
}
