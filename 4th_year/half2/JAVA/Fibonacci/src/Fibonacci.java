public class Fibonacci {
	public static long fibonacci(int i){
		if (i == 0) return 1;
		if (i == 1) return 1;

		long fib_return = fibonacci(i - 1) + fibonacci(i - 2);
		return fib_return;
	}

	public static void main(String[] args) {
		int index = 0;
		while(true){
			if(index == 46){
				System.out.print("F(46) is out of the range of int");
				break;
			}

			System.out.print("F(" + index + ") = ");
			System.out.print(fibonacci(index) + "\n");
			index++;
		}
	}
}