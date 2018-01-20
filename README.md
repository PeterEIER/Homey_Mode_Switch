## Introduction:
All you need to implement a basic Mode Switch for Homey (by Athom), the design is based on a Nextion 2.8'' display and an ESP8266.

## Functionality:
User can select between 4 modes: @Home, Away, Night and Vacation. When no mode is selected Homey will ask to do so. When no selection is made Homey will, after 55 seconds, put itself into the
(configurable) default mode. The display will dim after 60 (mode select page) or 10 seconds (mode pages).

Software is provide as is, no support is given use at own risk.

## Revision history:
* v1.0 -  12-Januari-2018 - Initial release
* v1.1 - 14-Januari-2018  - Added support for a Homey action  (send Homey action to the sketch/Nextion display from  a flow)
* v1.2 - 14-Januari-2018 - Added  support for a Homey conditions (send Homey  condition to the sketch/Nextion display from a flow)

## Resources:
* Athom: https://www.athom.com/nl
* Itead (Nextion Display): https://www.itead.cc/display/nextion.html
* Itead support forum: http://support.iteadstudio.com/support/discussions/topics/11000001697 (this will add support for current page notification to the arduino sketch)

