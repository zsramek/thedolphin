//Trigger Output Pins
int triggerOut0 = 38;
int triggerOut1 = 39;
int triggerOut2 = 40;
int triggerOut3 = 41;
int triggerOut4 = 42;
int triggerOut5 = 43;
int triggerOut6 = 44;
int triggerOut7 = 45;
int triggerOut8 = 46;
int triggerOut9 = 47;
int triggerOut10 = 48;
int triggerOut11 = 49;
int triggerOut12 = 50;
int triggerOut13 = 51;
int triggerOut14 = 52;
int triggerOut15 = 53;

//Live-Play Pins
int livePlayIn0 = 2;
int livePlayIn1 = 3;
int livePlayIn2 = 4;
int livePlayIn3 = 5;
int livePlayOut0 = 6;
int livePlayOut1 = 7;
int livePlayOut2 = 8;
int livePlayOut3 = 9;

boolean livePlayClicked0 = false;
boolean livePlayClicked1 = false;
boolean livePlayClicked2 = false;
boolean livePlayClicked3 = false;
boolean livePlayClicked4 = false;
boolean livePlayClicked5 = false;
boolean livePlayClicked6 = false;
boolean livePlayClicked7 = false;
boolean livePlayClicked8 = false;
boolean livePlayClicked9 = false;
boolean livePlayClicked10 = false;
boolean livePlayClicked11 = false;
boolean livePlayClicked12 = false;
boolean livePlayClicked13 = false;
boolean livePlayClicked14 = false;
boolean livePlayClicked15 = false;

int livePlayCount0 = 0;
int livePlayCount1 = 0;
int livePlayCount2 = 0;
int livePlayCount3 = 0;
int livePlayCount4 = 0;
int livePlayCount5 = 0;
int livePlayCount6 = 0;
int livePlayCount7 = 0;
int livePlayCount8 = 0;
int livePlayCount9 = 0;
int livePlayCount10 = 0;
int livePlayCount11 = 0;
int livePlayCount12 = 0;
int livePlayCount13 = 0;
int livePlayCount14 = 0;
int livePlayCount15 = 0;

boolean livePlayCounting0 = false;
boolean livePlayCounting1 = false;
boolean livePlayCounting2 = false;
boolean livePlayCounting3 = false;
boolean livePlayCounting4 = false;
boolean livePlayCounting5 = false;
boolean livePlayCounting6 = false;
boolean livePlayCounting7 = false;
boolean livePlayCounting8 = false;
boolean livePlayCounting9 = false;
boolean livePlayCounting10 = false;
boolean livePlayCounting11 = false;
boolean livePlayCounting12 = false;
boolean livePlayCounting13 = false;
boolean livePlayCounting14 = false;
boolean livePlayCounting15 = false;

int livePlayMax = 50;

int livePlayRow = 1;

int button = 0;

void setup()
{
  pinMode(triggerOut0, OUTPUT);
  pinMode(triggerOut1, OUTPUT);
  pinMode(triggerOut2, OUTPUT);
  pinMode(triggerOut3, OUTPUT);
  pinMode(triggerOut4, OUTPUT);
  pinMode(triggerOut5, OUTPUT);
  pinMode(triggerOut6, OUTPUT);
  pinMode(triggerOut7, OUTPUT);
  pinMode(triggerOut8, OUTPUT);
  pinMode(triggerOut9, OUTPUT);
  pinMode(triggerOut10, OUTPUT);
  pinMode(triggerOut11, OUTPUT);
  pinMode(triggerOut12, OUTPUT);
  pinMode(triggerOut13, OUTPUT);
  pinMode(triggerOut14, OUTPUT);
  pinMode(triggerOut15, OUTPUT);

  pinMode(livePlayIn0, INPUT);
  pinMode(livePlayIn1, INPUT);
  pinMode(livePlayIn2, INPUT);
  pinMode(livePlayIn3, INPUT);
  pinMode(livePlayOut0, OUTPUT);
  pinMode(livePlayOut1, OUTPUT);
  pinMode(livePlayOut2, OUTPUT);
  pinMode(livePlayOut3, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  scanButtons();
}

void scanButtons()
{
  //~~~~~~~~~~~~~~1~~~~~~~~~~~~~~~
  if (livePlayRow == 1)
  {
    //Serial.println("Row1");
    digitalWrite(livePlayOut0, HIGH);
    digitalWrite(livePlayOut1, LOW);
    digitalWrite(livePlayOut2, LOW);
    digitalWrite(livePlayOut3, LOW);

    if (digitalRead(livePlayIn0) == HIGH && livePlayCount0 == 0)
    {
      livePlayCounting0 = true;
    }
    if (livePlayCounting0 == true)
    {
      if (livePlayCount0 < livePlayMax)
      {
        livePlayCount0++;
      }
      else
      {
        livePlayCount0 = 0;
        livePlayCounting0 = false;
      }
    }
    if (digitalRead(livePlayIn0) == HIGH && livePlayCount0 >= livePlayMax)
    {
      if (livePlayClicked0 == false)
      {
        button = 15;
        Serial.println("15");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked0 = true;
        livePlayCounting0 = false;
        livePlayCount0 = 0;
      }
    }
    else if (digitalRead(livePlayIn0) == LOW)
    {
      if (livePlayClicked0 == true)
      {
        livePlayClicked0 = false;
      }
    }

    //~~~~

    if (digitalRead(livePlayIn1) == HIGH && livePlayCount1 == 0)
    {
      livePlayCounting1 = true;
    }
    if (livePlayCounting1 == true)
    {
      if (livePlayCount1 < livePlayMax)
      {
        livePlayCount1++;
      }
      else
      {
        livePlayCount1 = 0;
        livePlayCounting1 = false;
      }
    }
    if (digitalRead(livePlayIn1) == HIGH && livePlayCount1 >= livePlayMax)
    {
      if (livePlayClicked1 == false)
      {
        button = 13;
        Serial.println("13");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked1 = true;
        livePlayCounting1 = false;
        livePlayCount1 = 0;
      }
    }
    else if (digitalRead(livePlayIn1) == LOW)
    {
      if (livePlayClicked1 == true)
      {
        livePlayClicked1 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn2) == HIGH && livePlayCount2 == 0)
    {
      livePlayCounting2 = true;
    }
    if (livePlayCounting2 == true)
    {
      if (livePlayCount2 < livePlayMax)
      {
        livePlayCount2++;
      }
      else
      {
        livePlayCount2 = 0;
        livePlayCounting2 = false;
      }
    }
    if (digitalRead(livePlayIn2) == HIGH && livePlayCount2 >= livePlayMax)
    {
      if (livePlayClicked2 == false)
      {
        button = 11;
        Serial.println("11");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked2 = true;
        livePlayCounting2 = false;
        livePlayCount2 = 0;
      }
    }
    else if (digitalRead(livePlayIn2) == LOW)
    {
      if (livePlayClicked2 == true)
      {
        livePlayClicked2 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn3) == HIGH && livePlayCount3 == 0)
    {
      livePlayCounting3 = true;
    }
    if (livePlayCounting3 == true)
    {
      if (livePlayCount3 < livePlayMax)
      {
        livePlayCount3++;
      }
      else
      {
        livePlayCount3 = 0;
        livePlayCounting3 = false;
      }
    }
    if (digitalRead(livePlayIn3) == HIGH && livePlayCount3 >= livePlayMax)
    {
      if (livePlayClicked3 == false)
      {
        button = 9;
        Serial.println("9");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked3 = true;
        livePlayCounting3 = false;
        livePlayCount3 = 0;
      }
    }
    else if (digitalRead(livePlayIn3) == LOW)
    {
      if (livePlayClicked3 == true)
      {
        livePlayClicked3 = false;
      }
    }
    livePlayRow = 2;
  }
  //~~~~~~~~~~~~~~2~~~~~~~~~~~~~~~
  if (livePlayRow == 2)
  {
    //Serial.println("Row2");
    digitalWrite(livePlayOut1, HIGH);
    digitalWrite(livePlayOut0, LOW);
    digitalWrite(livePlayOut2, LOW);
    digitalWrite(livePlayOut3, LOW);

    if (digitalRead(livePlayIn0) == HIGH && livePlayCount4 == 0)
    {
      livePlayCounting4 = true;
    }
    if (livePlayCounting4 == true)
    {
      if (livePlayCount4 < livePlayMax)
      {
        livePlayCount4++;
      }
      else
      {
        livePlayCount4 = 0;
        livePlayCounting4 = false;
      }
    }
    if (digitalRead(livePlayIn0) == HIGH && livePlayCount4 >= livePlayMax)
    {
      if (livePlayClicked4 == false)
      {
        button = 7;
        Serial.println("7");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked4 = true;
        livePlayCounting4 = false;
        livePlayCount4 = 0;
      }
    }
    else if (digitalRead(livePlayIn0) == LOW)
    {
      if (livePlayClicked4 == true)
      {
        livePlayClicked4 = false;
      }
    }

    //~~~~

    if (digitalRead(livePlayIn1) == HIGH && livePlayCount5 == 0)
    {
      livePlayCounting5 = true;
    }
    if (livePlayCounting5 == true)
    {
      if (livePlayCount5 < livePlayMax)
      {
        livePlayCount5++;
      }
      else
      {
        livePlayCount5 = 0;
        livePlayCounting5 = false;
      }
    }
    if (digitalRead(livePlayIn1) == HIGH && livePlayCount5 >= livePlayMax)
    {
      if (livePlayClicked5 == false)
      {
        button = 5;
        Serial.println("5");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked5 = true;
        livePlayCounting5 = false;
        livePlayCount5 = 0;
      }
    }
    else if (digitalRead(livePlayIn1) == LOW)
    {
      if (livePlayClicked5 == true)
      {
        livePlayClicked5 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn2) == HIGH && livePlayCount6 == 0)
    {
      livePlayCounting6 = true;
    }
    if (livePlayCounting6 == true)
    {
      if (livePlayCount6 < livePlayMax)
      {
        livePlayCount6++;
      }
      else
      {
        livePlayCount6 = 0;
        livePlayCounting6 = false;
      }
    }
    if (digitalRead(livePlayIn2) == HIGH && livePlayCount6 >= livePlayMax)
    {
      if (livePlayClicked6 == false)
      {
        button = 3;
        Serial.println("3");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked6 = true;
        livePlayCounting6 = false;
        livePlayCount6 = 0;
      }
    }
    else if (digitalRead(livePlayIn2) == LOW)
    {
      if (livePlayClicked6 == true)
      {
        livePlayClicked6 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn3) == HIGH && livePlayCount7 == 0)
    {
      livePlayCounting7 = true;
    }
    if (livePlayCounting7 == true)
    {
      if (livePlayCount7 < livePlayMax)
      {
        livePlayCount7++;
      }
      else
      {
        livePlayCount7 = 0;
        livePlayCounting7 = false;
      }
    }
    if (digitalRead(livePlayIn3) == HIGH && livePlayCount7 >= livePlayMax)
    {
      if (livePlayClicked7 == false)
      {
        button = 1;
        Serial.println("1");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked7 = true;
        livePlayCounting7 = false;
        livePlayCount7 = 0;
      }
    }
    else if (digitalRead(livePlayIn3) == LOW)
    {
      if (livePlayClicked7 == true)
      {
        livePlayClicked7 = false;
      }
    }
    livePlayRow = 3;
  }

  //~~~~~~~~~~~~~~3~~~~~~~~~~~~~~~
  if (livePlayRow == 3)
  {
    //Serial.println("Row3");
    digitalWrite(livePlayOut2, HIGH);
    digitalWrite(livePlayOut0, LOW);
    digitalWrite(livePlayOut1, LOW);
    digitalWrite(livePlayOut3, LOW);

    if (digitalRead(livePlayIn0) == HIGH && livePlayCount8 == 0)
    {
      livePlayCounting8 = true;
    }
    if (livePlayCounting8 == true)
    {
      if (livePlayCount8 < livePlayMax)
      {
        livePlayCount8++;
      }
      else
      {
        livePlayCount8 = 0;
        livePlayCounting8 = false;
      }
    }
    if (digitalRead(livePlayIn0) == HIGH && livePlayCount8 >= livePlayMax)
    {
      if (livePlayClicked8 == false)
      {
        button = 16;
        Serial.println("16");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked8 = true;
        livePlayCounting8 = false;
        livePlayCount8 = 0;
      }
    }
    else if (digitalRead(livePlayIn0) == LOW)
    {
      if (livePlayClicked8 == true)
      {
        livePlayClicked8 = false;
      }
    }

    //~~~~

    if (digitalRead(livePlayIn1) == HIGH && livePlayCount9 == 0)
    {
      livePlayCounting9 = true;
    }
    if (livePlayCounting9 == true)
    {
      if (livePlayCount9 < livePlayMax)
      {
        livePlayCount9++;
      }
      else
      {
        livePlayCount9 = 0;
        livePlayCounting9 = false;
      }
    }
    if (digitalRead(livePlayIn1) == HIGH && livePlayCount9 >= livePlayMax)
    {
      if (livePlayClicked9 == false)
      {
        button = 14;
        Serial.println("14");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked9 = true;
        livePlayCounting9 = false;
        livePlayCount9 = 0;
      }
    }
    else if (digitalRead(livePlayIn1) == LOW)
    {
      if (livePlayClicked9 == true)
      {
        livePlayClicked9 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn2) == HIGH && livePlayCount10 == 0)
    {
      livePlayCounting10 = true;
    }
    if (livePlayCounting10 == true)
    {
      if (livePlayCount10 < livePlayMax)
      {
        livePlayCount10++;
      }
      else
      {
        livePlayCount10 = 0;
        livePlayCounting10 = false;
      }
    }
    if (digitalRead(livePlayIn2) == HIGH && livePlayCount10 >= livePlayMax)
    {
      if (livePlayClicked10 == false)
      {
        button = 12;
        Serial.println("12");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked10 = true;
        livePlayCounting10 = false;
        livePlayCount10 = 0;
      }
    }
    else if (digitalRead(livePlayIn2) == LOW)
    {
      if (livePlayClicked10 == true)
      {
        livePlayClicked10 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn3) == HIGH && livePlayCount11 == 0)
    {
      livePlayCounting11 = true;
    }
    if (livePlayCounting11 == true)
    {
      if (livePlayCount11 < livePlayMax)
      {
        livePlayCount11++;
      }
      else
      {
        livePlayCount11 = 0;
        livePlayCounting11 = false;
      }
    }
    if (digitalRead(livePlayIn3) == HIGH && livePlayCount11 >= livePlayMax)
    {
      if (livePlayClicked11 == false)
      {
        button = 10;
        Serial.println("10");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked11 = true;
        livePlayCounting11 = false;
        livePlayCount11 = 0;
      }
    }
    else if (digitalRead(livePlayIn3) == LOW)
    {
      if (livePlayClicked11 == true)
      {
        livePlayClicked11 = false;
      }
    }
    livePlayRow = 4;
  }

  //~~~~~~~~~~~~~~4~~~~~~~~~~~~~~~
  if (livePlayRow == 4)
  {
    //Serial.println("Row4");
    digitalWrite(livePlayOut3, HIGH);
    digitalWrite(livePlayOut0, LOW);
    digitalWrite(livePlayOut1, LOW);
    digitalWrite(livePlayOut2, LOW);

    if (digitalRead(livePlayIn0) == HIGH && livePlayCount12 == 0)
    {
      livePlayCounting12 = true;
    }
    if (livePlayCounting12 == true)
    {
      if (livePlayCount12 < livePlayMax)
      {
        livePlayCount12++;
      }
      else
      {
        livePlayCount12 = 0;
        livePlayCounting12 = false;
      }
    }
    if (digitalRead(livePlayIn0) == HIGH && livePlayCount12 >= livePlayMax)
    {
      if (livePlayClicked12 == false)
      {
        button = 8;
        Serial.println("8");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked12 = true;
        livePlayCounting12 = false;
        livePlayCount12 = 0;
      }
    }
    else if (digitalRead(livePlayIn0) == LOW)
    {
      if (livePlayClicked12 == true)
      {
        livePlayClicked12 = false;
      }
    }

    //~~~~

    if (digitalRead(livePlayIn1) == HIGH && livePlayCount13 == 0)
    {
      livePlayCounting13 = true;
    }
    if (livePlayCounting13 == true)
    {
      if (livePlayCount13 < livePlayMax)
      {
        livePlayCount13++;
      }
      else
      {
        livePlayCount13 = 0;
        livePlayCounting13 = false;
      }
    }
    if (digitalRead(livePlayIn1) == HIGH && livePlayCount13 >= livePlayMax)
    {
      if (livePlayClicked13 == false)
      {
        button = 6;
        Serial.println("6");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked13 = true;
        livePlayCounting13 = false;
        livePlayCount13 = 0;
      }
    }
    else if (digitalRead(livePlayIn1) == LOW)
    {
      if (livePlayClicked13 == true)
      {
        livePlayClicked13 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn2) == HIGH && livePlayCount14 == 0)
    {
      livePlayCounting14 = true;
    }
    if (livePlayCounting14 == true)
    {
      if (livePlayCount14 < livePlayMax)
      {
        livePlayCount14++;
      }
      else
      {
        livePlayCount14 = 0;
        livePlayCounting14 = false;
      }
    }
    if (digitalRead(livePlayIn2) == HIGH && livePlayCount14 >= livePlayMax)
    {
      if (livePlayClicked14 == false)
      {
        button = 4;
        Serial.println("4");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked14 = true;
        livePlayCounting14 = false;
        livePlayCount14 = 0;
      }
    }
    else if (digitalRead(livePlayIn2) == LOW)
    {
      if (livePlayClicked14 == true)
      {
        livePlayClicked14 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn3) == HIGH && livePlayCount15 == 0)
    {
      livePlayCounting15 = true;
    }
    if (livePlayCounting15 == true)
    {
      if (livePlayCount15 < livePlayMax)
      {
        livePlayCount15++;
      }
      else
      {
        livePlayCount15 = 0;
        livePlayCounting15 = false;
      }
    }
    if (digitalRead(livePlayIn3) == HIGH && livePlayCount15 >= livePlayMax)
    {
      if (livePlayClicked15 == false)
      {
        button = 2;
        Serial.println("2");
        //steps[0][0] = !//steps[0][0];
        livePlayClicked15 = true;
        livePlayCounting15 = false;
        livePlayCount15 = 0;
      }
    }
    else if (digitalRead(livePlayIn3) == LOW)
    {
      if (livePlayClicked15 == true)
      {
        livePlayClicked15 = false;
      }
    }
    livePlayRow = 1;
  }

}
