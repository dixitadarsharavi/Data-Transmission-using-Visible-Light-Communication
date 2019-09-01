void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int arr[32];
  int po[8]={1,2,4,8,16,32,64,128}; //powers of 2
  int i,j=0,k=0,flag=0,n=0,x=0, avg=250;
  int sensorValue;
  
  while(j<3)
  {
    sensorValue = analogRead(A2);
    if(sensorValue>avg)
    {
      arr[j++]=1;
      k=k+po[j-1];
      //Serial.print("1");
      flag++;
      delay(75);
    }
    else if(sensorValue<=avg && flag>0)
    {
      arr[j++]=0;
      //Serial.print("0");
      delay(75);
    }    
  }
  if(k==3)
  {
    for(i=0;i<8;i++)
    {
      sensorValue = analogRead(A2);
      if(sensorValue<=avg)
      {
        arr[j++]=0;
        //Serial.print("0");
      }
      else if(sensorValue>avg)
      {
        arr[j++]=1;
        //Serial.print("1");
        n=n+po[i];
      }
      delay(75);      
    }
    for(int z=0;z<3;z++)
    {
      sensorValue = analogRead(A2);
      if(sensorValue<=avg)
      {
        arr[j++]=0;
        //Serial.print("0");
      }
      else if(sensorValue>avg)
      {
        x=x+po[z];
        arr[j++]=1;
        //Serial.print("1");        
      }
      delay(75);      
    }
//    for(int l=0;l<j;l++)
//    {
//      Serial.print(arr[l]);
//    }
    if(x==4)
    {
      Serial.print(char(n));   
    }
  }
}
