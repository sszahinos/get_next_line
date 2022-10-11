<h1 align="center">get_next_line</h1>
<h2>42Barcelona, level 1</h2>
<h3>Description</h3>
<p>Function that allows the user to read line by line from a file descriptor a.k.a. fd. It reads a defined size buffer from fd and analyzes if there is a new line. If there is any, it returns all the line until the new line is found. Else it will return the entire line.
If executed more than one time, the program reads first from the static variable to see if there any characters left from the last execution.</p>
<h3>Example:</h3>
<p>We have "This is a \nnewline."</p>
<p>First execution -> "This is a \n"</p>
<p>Second execution -> "new line."</p>
