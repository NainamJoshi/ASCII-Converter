# ASCII-Converter
It is a command line application to Convert any Character or String to it's ASCII Values and any ASCII Values to Character or String

Usage:
  #compile the cpp file in terminal:
    $ g++ RESULT.cpp -o ascii
    (e.g here compiled file name is ascii)

  #for encoding a file:
  #here input.txt is the file I want to encode and output.txt is the file where i want to store my encoded file
    $ ./ascii -e input.txt -f output.txt

  #for decoding a file:
  #here encoded.txt is the file I want to decode and decoded.txt is the file where i want to store my decoded file
    $ ./ascii -d encoded.txt -f decoded.txt
