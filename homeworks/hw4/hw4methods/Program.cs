using System;

namespace HW4Methods
{
    class HW4Methods
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a string to be outputted:");
            string input = Console.ReadLine();
            Console.WriteLine(input);

            string data = GetData();
            Output(data);

            int num1 = 10;
            int num2 = 20;
            swap(ref num1, ref num2);
            Console.WriteLine("After swapping: num1 = " + num1 + ", num2 = " + num2);

            Console.WriteLine("Enter the nth Fibonacci number to generate:");
            int fibonacciCount = int.Parse(Console.ReadLine());
            fibonacci(fibonacciCount);

            Console.WriteLine("Enter a number to check if it's prime:");
            int number = int.Parse(Console.ReadLine());
            isPrime(number);
        }
        public static void Output(string message)
        {
             Console.WriteLine(message);
        }

        public static string GetData()
        {
            string data = "Hello, World!";
            return data;
        }

        public static void swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        public static void fibonacci(int n)
        {
            int a = 0;
            int b = 1;
            int c = 0;
            for (int i = 0; i < n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
            Output(a.ToString());
        }

        public static void isPrime(int n)
        {
            bool prime = true;
            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                {
                    prime = false;
                }
            }
            if (prime)
            {
                Output("Prime");
            }
            else
            {
                Output("Not Prime");
            }
        }
    }
}


