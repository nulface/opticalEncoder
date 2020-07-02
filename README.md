# opticalEncoder
an arduino file for reading an optical encoder sensor with 600 ticks

### This is the optical encoder I am using
![ ](https://i.ebayimg.com/images/g/HDsAAOSwTA9X6SWd/s-l500.jpg "The optical encoder I have")

### This is how they look on the inside
![ ](https://www.researchgate.net/profile/Jose_Maria_Del_Burgo2/publication/324777358/figure/fig1/AS:619657472008193@1524749262507/Principle-of-operation-of-an-optical-encoder.png "How they look inside")

### It produces a /digital/ish signal that looks like this
![ ](https://i.stack.imgur.com/GfuJB.jpg "They produce a signal like this")

In reality, These encoders do not produce perfect square waves, but as a conceptual model, this is close enough.

If it is spinning clockwise, the pulses are A then B then A then B and so on
If it is spinning counter clockwise, the pulses are B then A then B then A and so on

In digital electronics we are concerned with rising and falling edges of square waves in addition to their logic high and logic low states. A rising edge of B is seen in the transition from 1 to 2 in the above diagram.

We can tell which direction it is spinning based on these four pieces of information.
Logic high, logic low, rising edge, falling edge. and we have these 4 pieces of information for both A and B.

for example we know it is spinning clockwise if A is on a rising edge and B is in the logic high state. alternatively we know it is spinning counter clockwise if A is a rising edge and B is in a logic low state.

The arduino project contains functions for interupt pins. the interrupt pins are special pins that allow you to interrupt your code mid execution and run other code. There are several options for exactly what sort of signal you want to respond to. such as: A rising edge, a falling edge, logic high, and logic low. when one of these states are detected your interupt function will run.

The interrupt pins on the arduino UNO are pins 2 and 3.
You can assign an interupt function using the "attachInterrupt" function
This function has 3 parameters.
First is deciding which pin you want to use for your interupt.
the second is the name of the function you want to call when the state is detected.
and lastly, the state you want to detect.

here is an example from the code found below.
attachInterrupt(digitalPinToInterrupt(interruptA), aFall, FALLING);

this attaches the function aFall to the interruptA pin and triggers on a falling edge.


note: there may only be 600 ticks on this encoder, but because it reads the rising and falling edge there are actually 1200 ticks per 360 degrees of rotation.
