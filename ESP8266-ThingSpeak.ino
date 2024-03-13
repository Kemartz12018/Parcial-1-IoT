#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

char* ssid = "*********"; //Enter your Wi-Fi Name
char* pass = "*********";  //Enter your Wi-Fi password

unsigned long myChannelNumber = 2462437; //Enter your Thingspeak channel id
const char * myWriteAPIKey = "IZFK20X5RPQR3EE5";



WiFiClient client;

float temp;

void setup() {


 Serial.begin(9600);
 Serial.print("Connecting to Wi-Fi : ");
 Serial.println(ssid);
 WiFi.begin(ssid,pass);// Pass the credential for local wifi network to connect ESP8266 board
    while (WiFi.status()!= WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");

    delay(500);
    ThingSpeak.begin(client);
}

void loop() {
  
  temp = analogRead(A0)*(3.3/1024)*100; 
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.println("\n...Sending data to cloud...\n");
  Serial.println("------------------------------------------------------------------------------------------\n");
  ThingSpeak.setField(1, temp);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  Serial.println("\n...ENVIADO\n");
  Serial.println("------------------------------------------------------------------------------------------\n");
  delay(600000); 
  
 
  
}