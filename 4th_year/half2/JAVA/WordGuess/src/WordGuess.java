import java.io.*;
import java.util.*;

public class WordGuess 
{
	public static int GuessingGame()
	{
		Scanner input = new Scanner(System.in);
		String secretWord = "TESTING";
		String wordSoFar = "", updatedWord = "";
		String letterGuess, wordGuess = "";
		int numGuesses = 0;

		System.out.println("Guess the word, human.");
        for (int i = 0; i < secretWord.length(); i++) {
            wordSoFar += "-";
        }
        System.out.println(wordSoFar + " , " + secretWord.length() + " letters\n");

        do 
        {
        	numGuesses += 1;

        	System.out.print("Enter a letter:");
            letterGuess = input.nextLine();
            letterGuess = letterGuess.toUpperCase();           

            if (letterGuess.equalsIgnoreCase("t") == true)
            {
				char[] temp = wordSoFar.toCharArray();
				temp[3] = 'T';
				temp[0] = 'T';
				wordSoFar = String.valueOf(temp);
            }

            if (secretWord.indexOf(letterGuess) >= 0) 
            {
	            updatedWord = wordSoFar.substring(0, secretWord.indexOf(letterGuess));
	            updatedWord += letterGuess;                                            
	            updatedWord += wordSoFar.substring(secretWord.indexOf(letterGuess) + 1, wordSoFar.length());
				wordSoFar = updatedWord;
            }

            System.out.println(wordSoFar + "\n");

        } while(!wordSoFar.equals(secretWord));

        System.out.println("You won in " + numGuesses + " guesses!");

   		return 0;
	}

	public static void main (String[] args) 
	{
		String answer = "y";
		boolean AnotherGameFlag = true;
		Scanner scan = new Scanner(System.in);

		while(AnotherGameFlag)
		{
			GuessingGame();

			System.out.println();
			System.out.println("Would you like to play again?(y/n)");
			answer = scan.next();
			if(answer.equalsIgnoreCase("y") == true) {
				AnotherGameFlag = true;
			} else {
				System.out.println("Goodbye, my friend.");
				AnotherGameFlag = false;
			}
			System.out.println();
		}
	}
}