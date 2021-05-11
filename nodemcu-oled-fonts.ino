
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#include "Argon6pt7b.h"
#include "ArgonExtended6pt7b.h"
#include "ArgonTight6pt7b.h"
#include "Atom6pt7b.h"
#include "AtomExtended6pt7b.h"
#include "AtomTight6pt7b.h"
#include "Axxell6pt7b.h"
#include "AxxellExtended6pt7b.h"
#include "AxxellTight6pt7b.h"
#include "Clarity6pt7b.h"
#include "ClarityExtended6pt7b.h"
#include "ClarityTight6pt7b.h"
#include "Consolas-Bold7pt7b.h"
#include "Consolas7pt7b.h"
#include "FrucadeSmall8pt7b.h"
#include "JetBrainsMono-Bold8pt7b.h"
#include "JetBrainsMono-Regular8pt7b.h"
#include "Mini7Condensed5pt7b.h"
#include "Mini7Extended5pt7b.h"
#include "Mini7Tight5pt7b.h"
#include "Mini75pt7b.h"
#include "MiniMicra6pt7b.h"
#include "Monaco10pt7b.h"
#include "Monotony6pt7b.h"
#include "Pico12Extended6pt7b.h"
#include "Pico126pt7b.h"
#include "ProggyClean8pt7b.h"
#include "ProggySmall8pt7b.h"
#include "ProggySquare8pt7b.h"
#include "ProggyTiny8pt7b.h"
#include "Tenacity5pt7b.h"
#include "TenacityCondensed5pt7b.h"
#include "TenacityExtended5pt7b.h"
#include "TenFour6pt7b.h"
#include "VeraMono6pt7b.h"
//#include ".h"


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
//#define SCREEN_HEIGHT 32

#define OLED_RESET     5
#define SCREEN_ADDRESS 0x3C


#define PREV_PIN D6
#define NEXT_PIN D5

bool prevBtnUp = true;
bool nextBtnUp = true;

byte btnPin = D5;
bool btnUp = true;
int fontInd = 0;


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  Serial.begin(115200);
  pinMode(btnPin, INPUT_PULLUP);
  digitalWrite(btnPin, HIGH);

  pinMode(PREV_PIN, INPUT_PULLUP);
  digitalWrite(PREV_PIN, HIGH);

  pinMode(NEXT_PIN, INPUT_PULLUP);
  digitalWrite(NEXT_PIN, HIGH);
  
  Wire.begin(4, 0);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
  
  } else {
    display.clearDisplay();
    display.display();
    
    delay(3333);
    showFont();
  }
}


void loop() {
  if (millis() % 1000 == 0) {
//    Serial.println(digitalRead(btnPin));
//    Serial.print(digitalRead(PREV_PIN));
//    Serial.print(F(" -=- "));
//    Serial.print(digitalRead(NEXT_PIN));
//    Serial.println();
  }

  if (digitalRead(PREV_PIN) == LOW && prevBtnUp) {
    Serial.println("PREV DN");
    if (--fontInd < 0) {
      fontInd = 15;
    }
    delay(100);
    prevBtnUp = false;
  }

  if (digitalRead(PREV_PIN) == HIGH && !prevBtnUp) {
    Serial.println("PREV UP");
    showFont();
    prevBtnUp = true;
  }

  if (digitalRead(NEXT_PIN) == LOW && nextBtnUp) {
    Serial.println("NEXT DN");
    if (++fontInd > 15) {
      fontInd = 0;
    }
    delay(100);
    nextBtnUp = false;
  }

  if (digitalRead(NEXT_PIN) == HIGH && !nextBtnUp) {
    Serial.println("NEXT UP");
    showFont();
    nextBtnUp = true;
  }

  
//  if (digitalRead(btnPin) == LOW && btnUp) {
//    Serial.println("BUTTON DN");
//    if (++fontInd > 15) {
//      fontInd = 0;
//    }
//    delay(100);
//    btnUp = false;
//  }
//
//  if (digitalRead(btnPin) == HIGH && !btnUp) {
//    Serial.println("BUTTON UP");
//    showFont();
//    btnUp = true;
//  }
}



void showFont() {
  Serial.println("[:] showFont() [:]");
  
  display.clearDisplay();
  display.display();

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(4, 12);
  if (fontInd == 0) {
    display.setFont(&ArgonExtended6pt7b);
    display.println(F("Argon EXT"));
  } else if (fontInd == 1) {
    display.setFont(&AtomExtended6pt7b);
    display.println(F("Atom EXT"));
  } else if (fontInd == 2) {
    display.setFont(&ClarityExtended6pt7b);
    display.println(F("Clarity EXT"));
  } else if (fontInd == 3) {
    display.setFont(&Mini7Extended5pt7b);
    display.println(F("Mini7 EXT"));
  } else if (fontInd == 4) {
    display.setFont(&TenacityExtended5pt7b);
    display.println(F("Tenacity EXT"));
  } else if (fontInd == 5) {
    display.setFont(&Monotony6pt7b);
    display.println(F("Monotony"));
  } else if (fontInd == 6) {
    display.setFont(&TenFour6pt7b);
    display.println(F("TenFour"));
  } else if (fontInd == 7) {
    display.setFont(&MiniMicra6pt7b);
    display.println(F("MiniMicra"));
  } else if (fontInd == 8) {
    display.setFont(&Pico12Extended6pt7b);
    display.println(F("Pico12 EXT"));
  } else if (fontInd == 9) {
    display.setFont(&AxxellExtended6pt7b);
    display.println(F("Axxell EXT"));
  } else if (fontInd == 10) {
    display.setFont(&FrucadeSmall8pt7b);
    display.println(F("Frucade Small"));   
  } else if (fontInd == 11) {
    display.setFont(&JetBrainsMono_Bold8pt7b);
    display.println(F("JetBrains BLD")); 
  } else if (fontInd == 12) {
    display.setFont(&Monaco10pt7b);
    display.println(F("Monaco 10")); 
  } else if (fontInd == 13) {
    display.setFont(&ProggyClean8pt7b);
    display.println(F("Proggy Clean")); 
  } else if (fontInd == 14) {
    display.setFont(&VeraMono6pt7b);
    display.println(F("Vera Mono")); 
  } else if (fontInd == 15) {
    display.setFont(&Consolas_Bold7pt7b);
    display.println(F("Consolas Bold")); 
  }

  
  display.setCursor(4, 27);
  if (fontInd == 0) {
    display.setFont(&Argon6pt7b);
    display.println(F("Argon"));
  } else if (fontInd == 1) {
    display.setFont(&Atom6pt7b);
    display.println(F("Atom"));
  } else if (fontInd == 2) {
    display.setFont(&Clarity6pt7b);
    display.println(F("Clarity"));
  } else if (fontInd == 3) {
    display.setFont(&Mini75pt7b);
    display.println(F("Mini7"));
  } else if (fontInd == 4) {
    display.setFont(&Tenacity5pt7b);
    display.println(F("Tenacity"));
  } else if (fontInd == 8) {
    display.setFont(&Pico126pt7b);
    display.println(F("Pico12"));
  } else if (fontInd == 9) {
    display.setFont(&Axxell6pt7b);
    display.println(F("Axxell")); 
  } else if (fontInd == 13) {
    display.setFont(&ProggySquare8pt7b);
    display.println(F("Proggy Square")); 
  } else if (fontInd == 15) {
    display.setFont(&Consolas7pt7b);
    display.println(F("Consolas")); 
  }

  
  display.setCursor(4, 38);
  if (fontInd == 0) {
    display.setFont(&ArgonTight6pt7b);
    display.println(F("Argon Tight"));
  } else if (fontInd == 1) {
    display.setFont(&AtomTight6pt7b);
    display.println(F("Atom Tight"));
  } else if (fontInd == 2) {
    display.setFont(&ClarityTight6pt7b);
    display.println(F("Clarity Tight"));
  } else if (fontInd == 3) {
    display.setFont(&Mini7Tight5pt7b);
    display.println(F("Mini7 Tight"));
  } else if (fontInd == 4) {
    display.setFont(&TenacityCondensed5pt7b);
    display.println(F("Tenacity Condensed"));
  } else if (fontInd == 9) {
    display.setFont(&AxxellTight6pt7b);
    display.println(F("Axxell Tight"));
  } else if (fontInd == 11) {
    display.setFont(&JetBrainsMono_Regular8pt7b);
    display.println(F("JetBrains Reg"));
  } else if (fontInd == 13) {
    display.setFont(&ProggySmall8pt7b);
    display.println(F("Proggy Small"));
  }


  display.setCursor(4, 52);
  if (fontInd == 3) {
    display.setFont(&Mini7Condensed5pt7b);
    display.println(F("Mini7 Condensed"));
  } else if (fontInd == 13) {
    display.setFont(&ProggyTiny8pt7b);
    display.println(F("Proggy Tiny"));
  }

  
  display.display();
}
