#include <WiFi.h>
#include <HTTPClient.h>
const char* ssid     = "macco";
const char* password = "maccotest";

String device_id = "MACCO1";
String dataIn, RFIDTAG;
String dt[10];
String rfidtag = "";
const char* sendtag = "";
int i;
boolean parsing=false;

String payload, payload2, payload3, id_device, record, rilis;
const char* data_record ="";
const char* data_rilis = "";

String dt1[10];

void setup() 
{
    Serial.begin(115200);
    Serial2.begin(115200);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected with IP address: ");
    Serial.println(WiFi.localIP());
    
    dataIn="";
}
 
void loop() 
{
     if(Serial2.available()>0)
     {
           char inChar = (char)Serial2.read();
           dataIn += inChar;
           if (inChar == '\n') {parsing = true;}
     }
     if(parsing)
     {
           rfidData();
           if ((WiFi.status() == WL_CONNECTED)) { 
           //URL Push Data
           scan();
           //pendaftaran();
           }
           parsing=false;
           dataIn="";
     }
}
