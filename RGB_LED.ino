// NOTE: lines that have // at the beginning are called comments, 
// make sure to read them, but they don't actually do anything, the Arduino ignores them
// Same for lines inside of /* and */ (as shown below)

//   /**/ comments for Harware connections section
//      ||
//      ||   
//      ||
//      \/
/*
  Hardware connections:

  An RGB LED is actually three LEDs (red, green, and blue) in
  one package. When you run them at different brightnesses,
  the red, green and blue mix to form new colors.

  Starting at the flattened edge of the flange on the LED,
  the pins are ordered RED, COMMON, GREEN, BLUE.

  Connect RED to a 330 Ohm resistor. Connect the other end
  of the resistor to Arduino digital pin 9.

  Connect COMMON pin to GND.

  Connect GREEN to a 330 Ohm resistor. Connect the other end
  of the resistor to Arduino digital pin 10.

  Connect BLUE to a 330 Ohm resistor. Connect the other end
  of the resistor to Arduino digital pin 11.
*/


// First we'll define the pins by name to make the sketch
// easier to follow.

// The 3 lines below are called variables
  // Variables hold values, so everytime you use RED_PIN, you use the value it represents, or 9
  // The int specifies the type of varaible. "int" is for integer, but others exist too!
  // The const in front of the int signifies that it is constant, won't change thoughout the program 
  // ʕ•ᴥ•ʔ <-- it's a spoopy bear

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

// This variable controls how fast we loop through the colors.
// (Try changing this to make the fading faster or slower.)
int DISPLAY_TIME = 100;  // In milliseconds

// Everything inside of the setup curly brackets is run once at the beginning
void setup()
{
  // Computers are dumb; we have to tell the Aruino what each of our pins will be doing before we can use them (outputting)
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

// Everything inside of the loop curly brackets is run repeatedly while the Aruino is powered on
void loop()
{
  // These 2 lines run the mainColors and showSpectrum functions
  // Funcitons are like variables, but instead of holding a value, they hold a chunk of code
  // So everytime we use mainColors we tell the Arduino to run the code in the mainColors curly brackets
  mainColors();
  showSpectrum();
  // ฅ^•ﻌ•^ฅ <-- spoopy not pupper
}


// This is the definition of the function mainColors, it's what will be run everytime we use the name mainColors (as above)
// This function displays the eight "main" colors that the RGB LED can produce
void mainColors()
{
  // all LEDs off:
  digitalWrite(RED_PIN, LOW); // digitalWrite = changing output, LOW = stop output, HIGH = start/continue output
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000); // delay = well...delay, the 1000 is in milliseconds

  // Only red on
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Only green on 
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Only blue on
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // Red and Green on to make yellow
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Green and blue on to make cyan
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // red and blue on to mkae purple
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // All on to make white
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);
}



// Below are two more functions we've written,
// showSpectrum() and showRGB().

// showRGB() displays a single color on the RGB LED.
// You call showRGB() with the number of a color you want
// to display.

// showSpectrum() steps through all the colors of the RGB LED,
// displaying a rainbow. showSpectrum() actually calls showRGB()
// over and over to do this.

// We'll often break tasks down into individual functions like
// this, which makes your sketches easier to follow, and once
// you have a handy function, you can reuse it in your other
// programs.


// showSpectrum()

// This function steps through all the colors of the RGB LED.
// It does this by stepping a variable from 0 to 768 (the total
// number of colors), and repeatedly calling showRGB() to display
// the individual colors.

// In this function, we're using a "for loop" to step a variable
// from one value to another, and perform a set of instructions
// for each step. For loops are a very handy way to get numbers
// to count up or down.

// Every for() loop has three statements separated by semicolons:

//   1. Something to do before starting

//   2. A test to perform; as long as it's true,
//      it will keep looping

//   3. Something to do after each loop (usually
//      increase a variable)

// For the for loop below, these are the three statements:

//   1. x = 0;     Before starting, make x = 0.

//   2. x < 768;   While x is less than 768, run the
//                 following code.

//   3. x++        Putting "++" after a variable means
//                 "add one to it". (You can also use "x = x + 1")

// Every time you go through the loop, the statements following
// the loop (those within the brackets) will run.

// And when the test in statement 2 is finally false, the sketch
// will continue.


void showSpectrum()
{
  int x;  // define an integer variable called "x"

  // Now we'll use a for() loop to make x count from 0 to 767
  // (Note that there's no semicolon after this line!
  // That's because the for loop will repeat the next
  // "statement", which in this case is everything within
  // the following brackets {} )

  for (x = 0; x < 768; x++)

    // Each time we loop (with a new value of x), do the following:

  {
    showRGB(x);  // Call RGBspectrum() with our new x
    delay(10);   // Delay for 10 ms (1/100th of a second)
  }
}


// showRGB()

// This function translates a number between 0 and 767 into a
// specific color on the RGB LED. If you have this number count
// through the whole range (0 to 767), the LED will smoothly
// change color through the entire spectrum.

// The "base" numbers are:
// 0   = pure red
// 255 = pure green
// 511 = pure blue
// 767 = pure red (again)

// Numbers between the above colors will create blends. For
// example, 640 is midway between 512 (pure blue) and 767
// (pure red). It will give you a 50/50 mix of blue and red,
// resulting in purple.

// If you count up from 0 to 767 and pass that number to this
// function, the LED will smoothly fade between all the colors.
// (Because it starts and ends on pure red, you can start over
// at 0 without any break in the spectrum).


void showRGB(int color)
{
  int redIntensity;
  int greenIntensity;
  int blueIntensity;

  // Here we'll use an "if / else" statement to determine which
  // of the three (R,G,B) zones x falls into. Each of these zones
  // spans 255 because analogWrite() wants a number from 0 to 255.

  // In each of these zones, we'll calculate the brightness
  // for each of the red, green, and blue LEDs within the RGB LED.

  if (color <= 255)          // zone 1
  {
    redIntensity = 255 - color;    // red goes from on to off
    greenIntensity = color;        // green goes from off to on
    blueIntensity = 0;             // blue is always off
  }
  else if (color <= 511)     // zone 2
  {
    redIntensity = 0;                     // red is always off
    greenIntensity = 255 - (color - 256); // green on to off
    blueIntensity = (color - 256);        // blue off to on
  }
  else // color >= 512       // zone 3
  {
    redIntensity = (color - 512);         // red off to on
    greenIntensity = 0;                   // green is always off
    blueIntensity = 255 - (color - 512);  // blue on to off
  }

  // analogWrite is like digitalWrite, but it outputs things in between LOW and HIGH
    // so if we output redIntensity as 128, it will output half of HIGH (255 is max, 255 / 2 = ~128)
    // Note, the physical pin on the Arduino has to support this capability (PWM pins)
  analogWrite(RED_PIN, redIntensity); 
  analogWrite(BLUE_PIN, blueIntensity);
  analogWrite(GREEN_PIN, greenIntensity);
}

// ʕ•ᴥ•ʔ <-- another spoopy bear (bet you didn't see that one coming)
