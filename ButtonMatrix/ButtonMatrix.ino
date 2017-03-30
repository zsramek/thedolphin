//Matrix Button Test

int buttonRow = 1;

int button = 0;

boolean clicked2 = false;
boolean clicked3 = false;

void setup()
{
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (buttonRow == 1)
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    if (digitalRead(8) == HIGH)
    {
      button = 1;
    }
    else if (digitalRead(9) == HIGH)
    {
      button = 2;
    }
    buttonRow = 2; //Must come after
  }
  else if (buttonRow == 2)
  {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    if (digitalRead(8) == HIGH)
    {
      button = 3;
    }
    else if (digitalRead(9) == HIGH)
    {
      button = 4;
    }
    buttonRow = 1;
  }
  Serial.println(button);
}
