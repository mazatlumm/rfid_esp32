void pendaftaran(){
    HTTPClient http;
    String urlgo = "http://www.alicestech.com/macco/webmacco/api/macco/isitag?tag=";
    urlgo += RFIDTAG;

    const char* sendurl = urlgo.c_str();
    Serial.println(sendurl);
    
    http.begin(sendurl); 
    int httpCode = http.GET();                                      
 
    if (httpCode > 0) { 
 
        payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
        Serial.println();
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
    http.end(); 
}
