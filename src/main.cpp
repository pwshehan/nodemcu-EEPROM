#include <Arduino.h>

#include <EEPROM.h>

int addr_ssid = 0;         // ssid index
int addr_password = 20;    // password index
String ssid = "Shein";     // wifi ssid
String password = "25072"; // and password

// Set to true to reset eeprom before to write something
#define RESET_EEPROM false

void setup()
{
  Serial.begin(115200);
  EEPROM.begin(512);
  Serial.println("");

  if (RESET_EEPROM)
  {
    for (int i = 0; i < 512; i++)
    {
      EEPROM.write(i, 0);
    }
    EEPROM.commit();
    delay(500);
  }

  Serial.println("");
  Serial.print("Write WiFi SSID at address ");
  Serial.println(addr_ssid);
  Serial.print("");
  for (int i = 0; i < ssid.length(); ++i)
  {
    EEPROM.write(addr_ssid + i, ssid[i]);
    Serial.print(ssid[i]);
    Serial.print("");
  }

  Serial.println("");
  Serial.print("Write WiFi Password at address ");
  Serial.println(addr_password);
  Serial.print("");
  for (int j = 0; j < password.length(); j++)
  {
    EEPROM.write(addr_password + j, password[j]);
    Serial.print(password[j]);
    Serial.print("");
  }

  Serial.println("");
  if (EEPROM.commit())
  {
    Serial.println("Data successfully committed");
  }
  else
  {
    Serial.println("ERROR! Data commit failed");
  }

  Serial.println("");
  Serial.println("Check writing");
  String ssid;
  for (int k = addr_ssid; k < addr_ssid + 20; ++k)
  {
    ssid += char(EEPROM.read(k));
  }
  Serial.print("SSID: ");
  Serial.println(ssid);

  String password;
  for (int l = addr_password; l < addr_password + 20; ++l)
  {
    password += char(EEPROM.read(l));
  }
  Serial.print("PASSWORD: ");
  Serial.println(password);
}

void loop()
{
}