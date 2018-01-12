/*
Homey Mode Switch

Written by Peter EIER, based on HomeyDruino sample sketches.

Version History
v1.0 -  Januari 2018
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Nextion.h>                               // Nextion TFT Touch screen - Libraries
#include <Homey.h>

//Nextion TFT Touch screen
NexHotspot hot0 = NexHotspot(0, 1, "hot0"); // AtHome
NexHotspot hot1 = NexHotspot(0, 2, "hot1"); // Away
NexHotspot hot2 = NexHotspot(0, 3, "hot2"); // Nightmode
NexHotspot hot3 = NexHotspot(0, 4, "hot3"); // Vacation
NexHotspot hot4 = NexHotspot(0, 9, "hot4"); // undefined, please set mode!

NexTouch *nex_listen_list[] =               // Register the objects in event listen list
{
    &hot0,
    &hot1,
    &hot2,
    &hot3,
    &hot4,
    NULL
};

int hotspotid = 99;                         // 99 means undefined, please set mode!

//Nextion LCD subroutines
//see subroutine section below the main loop of the sketch

//Arduino config
void setup() {
  //The ESP8266 has only 1 serial port which is used for the Nextion display!! No serial terminal debugging posible for that reason!!

  //Connect to network
  WiFi.begin("<your ssid>", "<your ssid password>");
  while (WiFi.status() != WL_CONNECTED) { delay(500); }

  //Start Homey library
  Homey.begin("HomeyModeSwitch");
  /* Note:
     The name of each Arduino on the network needs to be unique
     since it will be used as the unique identifier for your device.
     The name is stored as a String and can thus be as long as you
     desire it to be.
  */

   // Nextion display initialization
   nexInit();
   hot0.attachPush(hot0PushCallback, &hot0); // AtHome
   hot1.attachPush(hot1PushCallback, &hot1); // Away
   hot2.attachPush(hot2PushCallback, &hot2); // Nightmode
   hot3.attachPush(hot3PushCallback, &hot3); // Vacation
   hot4.attachPush(hot4PushCallback, &hot4); // undefined, please set mode!

}

void loop() {

  //Listen to the Nextion display its serial port communications...
  nexLoop(nex_listen_list);
      
  //Handle incoming connections
  Homey.loop();
  /* Note:
   *  The Homey.loop(); function needs to be called as often as possible.
   *  Failing to do so will cause connection problems and instability.
   *  Avoid using the delay function at all times. Instead please use the
   *  method explaind on the following page on the Arduino website:
   *  https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
   */
}


//******* Subroutine section ********
void hot0PushCallback(void *ptr)
{
    dbSerialPrintln("hot0PushCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr);
    hotspotid = 0;
    int hid = Homey.trigger("hotspotid", hotspotid);
    /* Note:
     *  The first argument to the emit function is the name of the trigger  
     *  this name has to match the name used in the flow editor
     *  
     *  The second argument to the emit function is the argument.
     *  An argument can be one of the following:
     *     - a string
     *     - an integer (int)
     *     - a floating point number (float or double),
     *     - a boolean (bool)
     *     - nothing (void)
     *  
     *  Make sure to select the right type of flow card to match the type
     *  of argument sent to Homey.
     *  For a string argument the "text" flowcard is used.
     *  For an integer or floating point number the "number" flowcard is used.
     *  For the boolean argument the "boolean" flowcard is used.
     *  And when no argument is supplied the flowcard without argument is used.
     *  
     */ 
}

void hot1PushCallback(void *ptr)
{
    dbSerialPrintln("hot1PushCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr);   
    hotspotid = 1;
    int hid = Homey.trigger("hotspotid", hotspotid);      
}

void hot2PushCallback(void *ptr)
{
    dbSerialPrintln("hot2PushCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr);  
    hotspotid = 2;
    int hid = Homey.trigger("hotspotid", hotspotid);       
}

void hot3PushCallback(void *ptr)
{
    dbSerialPrintln("hot3PushCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr);  
    hotspotid = 3;
    int hid = Homey.trigger("hotspotid", hotspotid);      
}

void hot4PushCallback(void *ptr)
{
    dbSerialPrintln("hot4PushCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr);  
    hotspotid = 99;
    int hid = Homey.trigger("hotspotid", hotspotid);      
}
