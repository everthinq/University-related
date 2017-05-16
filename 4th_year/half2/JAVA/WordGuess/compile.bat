javac -d bin src/*.java
java -cp ".;bin;lib/*" WordGuess %*
pause