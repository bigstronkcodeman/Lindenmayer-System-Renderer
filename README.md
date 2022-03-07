# Lindenmayer System Renderer

A Lindenmayer System is a type of formal grammar, consisting of an alphabet of symbols, a set of production rules, and a starting state (string) which is referred to as the "axiom". These production rules are applied iteratively, starting with the axiom, some specified number of times. Then, the resulting string is interpreted as a set of instructions for drawing. 

Using these systems, we can render a vast collection of different types of beautiful fractal images.

This tool, made with Qt, allows you to render your own custom L-Systems, then zoom around and explore the structures in detail.

![image](https://user-images.githubusercontent.com/43645849/156964882-408d6db4-6ba3-4f64-b2d6-3aefc590eafb.png)

# Geometric interpretation of symbols:
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
   >	         Multiply the line length by the line length scale factor
   <	         Divide the line length by the line length scale factor
   &	         Swap the meaning of + and -
   (	         Decrement turning angle by turning angle increment
   )	         Increment turning angle by turning angle increment
```

# Some example screenshots:

![woah1](https://user-images.githubusercontent.com/43645849/156958006-e1ac5227-9fa2-4c1c-b0d1-3327682ecdd2.png)

![Screenshot from 2022-03-06 20-52-13](https://user-images.githubusercontent.com/43645849/156960699-bd093453-6c57-4bb2-998c-85e1d2c0efc3.png)

![image](https://user-images.githubusercontent.com/43645849/156961101-af5eb71f-48af-4930-b607-15949eb640a5.png)

and infinitely many more...
