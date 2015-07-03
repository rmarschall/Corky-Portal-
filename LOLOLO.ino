


#include <Bridge.h>
 
#include <Temboo.h>


 
/*** NOTE - INSERT YOUR CREDENTIAL ***/
 
const String TWITTER_ACCESS_TOKEN = "2532622116-Y60nX3RSigcs3FM67PfAEP60nRKW8Ght6uBgFEb";
 
const String TWITTER_ACCESS_TOKEN_SECRET = "iTXksYut7DE9p4vZmENGbMX2ge1JpUnX0iU4rG6vbSKfZ";
 
const String TWITTER_CONSUMER_KEY = "sFYTL8mgwMhjZKDrZjpNMMITJ";
 
const String TWITTER_CONSUMER_SECRET = "DNB7V5Ie7TjF4lWjJDIf8fNn6mWCIELZPBbkcJGHVo93JG4zX0";
 
const String TEMBOO_ACCOUNT = "rmarschall";  // your Temboo account name
 
const String TEMBOO_APP_KEY_NAME = "myFirstApp";  // your Temboo app key name
 
const String TEMBOO_APP_KEY  = "eb1137a9351a4f34b7ee54a121fbbc44";  // your Temboo app key






const int buttonPin = 5;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH); // turn on input pin's pull-up resistor 
  Serial.begin(57600);
  Bridge.begin();
  
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {     
    // turn LED on:    
    
    String tweetText("The Portal has been opened! "  + String(millis()) );
    
    
    TembooChoreo StatusesUpdateChoreo;  // Instantiate the object for sending TWEET
 
       // Invoke Temboo client
 
       StatusesUpdateChoreo.begin();
 
       // Set Temboo credetials
 
       StatusesUpdateChoreo.setAccountName(TEMBOO_ACCOUNT);
 
       StatusesUpdateChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
 
       StatusesUpdateChoreo.setAppKey(TEMBOO_APP_KEY);
 
       // Set API library (Twitter > Tweets > StatusesUpdate)
 
       StatusesUpdateChoreo.setChoreo("/Library/Twitter/Tweets/StatusesUpdate");
 
       // Set Twitter credetials
 
       StatusesUpdateChoreo.addInput("AccessToken", TWITTER_ACCESS_TOKEN);
 
       StatusesUpdateChoreo.addInput("AccessTokenSecret", TWITTER_ACCESS_TOKEN_SECRET);
 
       StatusesUpdateChoreo.addInput("ConsumerKey", TWITTER_CONSUMER_KEY);    
 
       StatusesUpdateChoreo.addInput("ConsumerSecret", TWITTER_CONSUMER_SECRET);
 
       // Message to be sent
 
       StatusesUpdateChoreo.addInput("StatusUpdate", tweetText);
 
       // Execute sending
 
       unsigned int returnCode = StatusesUpdateChoreo.run();
    
    
    
    
    Serial.println("OPEN");
    delay(5000);
  } 
  else {
   
    // turn LED off:
    Serial.println("CLOSED");
  }
}

