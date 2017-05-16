import java.util.*;

public class NumberGuess 
{
	public static int GuessingGame()
	{
		Scanner scan = new Scanner(System.in);
		int secretNumber = (int)(Math.random() * 100);
		int numberOfTries = 0;
		int guess = 0;

		System.out.println("I am thinking of a number between 0 an 99. Guess it.");
		while(guess != secretNumber) 
		{
     		numberOfTries++;
   			guess = scan.nextInt();  

   			if(guess < secretNumber) {
   				System.out.println("Try higher.");
   			}  

   			if(guess > secretNumber) {
   				System.out.println("Try lower.");
   			}  

   			if(guess == secretNumber) {
   				System.out.println("\nYou won in " + numberOfTries + " tries.");
   			}
   		}

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