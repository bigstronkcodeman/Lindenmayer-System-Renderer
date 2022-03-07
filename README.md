# Lindenmayer System Renderer
Design, draw, and explore custom L-Systems

A Lindenmayer System is a type of formal grammar, consisting of an alphabet of symbols, a set of production rules, and a starting state (string) which is referred to as the "axiom". These production rules are applied iteratively, starting with the axiom, some specified number of times. Then, the resulting string is interpreted as a set of instructions for drawing. Using these systems, we can render a vast collection of different types of beautiful fractal images. The possibilities really are endless!

The rules for interpreting symbols:
```
Character        Meaning
   F	         Move forward by line length drawing a line
   f	         Move forward by line length without drawing a line
   +	         Turn left by turning angle
   -	         Turn right by turning angle
   |	         Reverse direction (ie: turn by 180 degrees)
   [	         Push current drawing state onto stack
   ]	         Pop current drawing state from the stack
   #	         Increment the line width by line width increment
   !	         Decrement the line width by line width increment
   @	         Draw a dot with line width radius
   {	         Open a polygon
   }	         Close a polygon and fill it with fill colour
   >	         Multiply the line length by the line length scale factor
   <	         Divide the line length by the line length scale factor
   &	         Swap the meaning of + and -
   (	         Decrement turning angle by turning angle increment
   )	         Increment turning angle by turning angle increment
```

![lich](https://user-images.githubusercontent.com/43645849/156948885-6cd1cdfc-ca72-489d-91c5-2089e2707d9f.png)
