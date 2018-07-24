# Tiny-Rover
A modification of Adafruit's  Trinket Powered Rover to function as a tabletop scale RC tank

The Adafruit Trinket Rover ( https://learn.adafruit.com/trinket-powered-rover/red-rover ) is a cool starter project. The only drawback is that the treads are those woven wrist bands and I can't find them cheaply. I've created a replacement drive wheel and idler that mimic the same design, but instead take standard silicone wrist bands that are readily available on online retailers like Amazon.

These wrist bands are typically available in two sizes- youth (7 in) and adult (8 in). I have only tried this with the YOUTH size. If you try this with the adult size, your mileage may vary.


# Tiny-Tank

The other part of this is that I want to make a small, cheap RC tank. 

It will be powered by an Arduino Mini Pro (since I have ~10 laying around). I'm using the 5v variant. It will have a laser cannon that will fire and light sensors that will detect hits from enemy tanks. It will also have a buzzer for sound effects and indicator LEDs to show have many lives the tank still has.

The TX/RX is the super cheap, 4 channel RF modules available on eBay/Amazon for dirt cheap. I shose them for their cheapness and the ability to set the channels on them.

The light sensors are your typical photoresistors that are "extended" through straws. When the straws have a laser shone on them at 3", there is still a noticible jump in the code's analog reading.

The first iteration was tested and works! The only problems still are mechanical with the chassis throwing track.

The second iteration of the board was designed and ordered.

# Problems to still troubleshoot:

- The continuous diameter of the drive wheel and idler cause the tank to throw track. Aaron suggested adding a bevel on the inside.

- Board schematic MkII is in! It includes an on/off switch, is smaller in size, and has solder points for AA/AAA battery packs OR a 2cell, 7.4v lipo battery.

- The trimpot can be used to adjust the sensitivity of the light sensor threshold. An alternative could be that during the setup loop a number of measurements are taken and averaged.

