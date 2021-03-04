void setup()
{
  // Open serial port at 9600 baud
  Serial.begin(9600);   
}

void loop()
{
  byte c;  
  int a,j=3;
  int arr[75]={1,1,0};

  // Check if port is active
  if(Serial.available())
  {
    // Read one character
    c = Serial.read();

    // Print the least significant bit
    Serial.print(char(c));

    for(int i=0; i<8; i++) 
    { 
      a=c%2;
      arr[j++]= a;
      c /= 2;  
    }

    c=4;

    for(int i=0;i<3;i++)
    {
      arr[j++]=c%2;
      c/=2;
    }

    for(int i=0;i<j;i++)
    {
      if(arr[i]==1)
      {
        digitalWrite(13, HIGH);
      }
      else
      {
        digitalWrite(13, LOW);
      }
      Serial.print(arr[i]);
      delay(75);
    }
  }
  digitalWrite(13, LOW);  
}

