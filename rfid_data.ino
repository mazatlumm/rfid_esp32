void rfidData()
{
      int j=0;
      
      dt[j]="";
      for(i=1;i<dataIn.length();i++)
      {
        dt[j] = dt[j] + dataIn[i];
      }

      RFIDTAG = dt[0];
      RFIDTAG.remove(0,2);
      RFIDTAG.trim();
      
      Serial.print("RFID TAG : ");
      Serial.print(RFIDTAG);
      Serial.print("\n\n");
}
