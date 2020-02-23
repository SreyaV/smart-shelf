#ifndef CONFIG_H
#define CONFIG_H

// Server URL
char URL[] = "http://api.openweathermap.org/data/2.5/weather";
char HOST[] = "http://api.openweathermap.org";

char POSTURL[] = ""; //put server ngrok here
char POSTHOST[] = ""; //put server ngrok here

// Wifi constants
char NETWORK[] = "stratus";  // SSID for Wifi Network
char PASSWORD[] = "jeremysux"; // Password for Wifi Networkbvg

// buffers
char requestBuffer[900];
char responseBuffer[900];
char body[600];

// weather
char id[] = "4930956";
char api[] = "03f0991b65eae61e742929f915a22670";

#endif
