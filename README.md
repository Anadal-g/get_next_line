
# GET_NEXT_LINE 42

You will understand how files are opened, read and closed in an OS,
and how they are interpreted by a programming language for further analysis.
This task is crucial to understand for a future programmer since much of the time is based
on manipulating files for data management and persistence.
This project consists of coding a function that returns one line at a time from a text file.


The prototype of the function should be the following:

`char	*get_next_line(int fd)``

What do we use?

In our get_next_line we have only the following functions from authorized external libraries:

| Función  | Descripción														 			|
|-------|-----------------------------------------------------------------------------------|
| malloc | Request a memory block of the size supplied as a parameter.   													|
| free | Unallocates a block of memory that was previously allocated by a call.											|
| read |  Reads the contents of the selected system file.

How it works?

As I mentioned, you send this function the file descriptor to read line by line, for example, if we have a file called textotest.txt and I have the following content:

`line1`

`line2`

`line3`

Every time we call the function (using the FileDescriptor of testtext.txt) it will print a line:

`linea1  //lee la primera linea
linea2  //lee la segunda linea
linea3  //lee la tercera linea
(null)  //devuelve NULL por que ha llegado al final del archivo (EOF)`

How do we use the function?

To use it you must first know the path of the function and use the .h file of this function. Then add it in the header of your program:

`#include "./<carpeta_de_get_next_line>/get_next_line.h"`

