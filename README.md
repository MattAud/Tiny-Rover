# Tiny-Rover
A modification of Adafruit's  Trinket Powered Rover to function as a tabletop scale RC tank

The Adafruit Trinket Rover ( https://learn.adafruit.com/trinket-powered-rover/red-rover ) is a cool starter project. The only drawback is that the treads are those woven wrist bands and I can't find them cheaply. I've created a replacement drive wheel and idler that mimic the same design, but instead take standard silicone wrist bands that are readily available on online retailers like Amazon.

These wrist bands are typically available in two sizes- youth (7 in) and adult (8 in). I have only tried this with the YOUTH size. If you try this with the adult size, your mileage may vary.


# Tiny-Tank

The other part of this is that I want to make a small, cheap RC tank. 

It will be powered by an Arduino Mini Pro (since I have ~10 laying around). I'm using the 5v variant. It have a laser cannon that will fire and light sensors that will detect hits from enemy tanks. It will also have a buzzer for sound effects and indicator LEDs to show have many lives the tank still has.

The TX/RX is the super cheap, 4 channel RF modules available on eBay/Amazon for dirt cheap. I shose them for their cheapness and the ability to set the channels on them.

The light sensors are your typical photoresistors that are "extended" through straws. When the straws have a laser shone on them at 3", there is still a noticible jump in the code's analog reading.

The Eagle files uploaded are the first iteration and are still inbound, so I have not tested them.

# Problems to still troubleshoot:

- The continuous diameter of the drive wheel and idler cause the tank to throw track. Aaron suggested adding a bevel on the inside.

- A RAW power input of 6v is enough to power the servos, but not the servos AND the Arduino Mini Pro. The code gets SUPER choppy. I can solve this by running the RAW at ~7v (5 AAAs were tested on the breadboard), but this is kind of a crappy alternative because buying a 4 battery holder AND a 1 battery holder is just a pain. I want to find a "cleaner" way to provide power to the servos and the Arduino. mayby running an Arduino Mini Pro/Trinket 3v variant?
  >> Add a Lipo?

- Definitely forgot the power switch on the board. Well, didn't forget. The goal was to run the tank off of the 4-AAA/AA packs with the build in switch. THAT was supposed to be the on/off switch. But running the 5 AAA/AA set up ruinded this.

