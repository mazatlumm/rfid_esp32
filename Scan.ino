void scan(){
    HTTPClient http;
    String urlgo = "http://alicestech.com/macco/webmacco/api/penampung?";
    urlgo += "id_reader=18";
    urlgo += "&tag=";
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
