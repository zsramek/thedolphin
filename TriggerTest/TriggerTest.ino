int count;

void setup()
{
  pinMode (52, OUTPUT);
  count = 0;
}

void loop()
{
  if (count < 50)
  {
    digitalWrite(52, HIGH);
  }
  else
  {
     digitalWrite(52, LOW);
  }
  
  if (count < 10000)
  {
    count++;
  }
  else
  {
    count = 0;
  }
}

