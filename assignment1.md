# Assignment 1

## a.
I tested my code with known values for the polynomial function. Also, I made sure there is no error by testing all possible number of points for respective integration methods.

## b.
I wrote individual comments for all the functions. The driver program documentation is thoroughly done in the readme file.

## c.
Handling errors was done by performing trial and error for all possible combinations of user inputs. 

## d.
I think the error in using my code will solely depend on the user. I have provided prompts so that the user can input the details, instead of using a file to import the necessary information. The instruction is simple enough there can be minimal human error.

## e.
Not that I am aware of, because I tried to make it as concise as possible. However, I am open to any suggestions.

## f.
I may have put all the code inside the .hpp files instead of having the source codes and separate header file. I do not know the consequences of this. The structure was not massive, so I implemented the code in the header file.

## g.
Extending the code to two dimensions would require a different integrate function in the main file. What I can imagine is having two cascading loops that deal with respective dimension. If more dimensions exist, there would be more levels.

## h.
I guess this refers back to the limitations mentioned in e. If there is another user defined function that requires additional input, my integration_rule.hpp needs to be changed. Therefore, I would need to create another class.

## i.
The implementation of this code is only for polynomial. It needs to be specified before building. I guess this can be another limitation to this driver, as it is not very flexible.