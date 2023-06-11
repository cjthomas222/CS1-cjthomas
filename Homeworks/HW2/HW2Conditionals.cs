using System;

namespace HW2Conditionals
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter the amount of money to calculate the tax:");
            float income = float.Parse(Console.ReadLine());

            float totalTax = 0;

            if (income < 10000)
            {
                totalTax = income * 0.05f;
            }
            else if (income >= 10000 && income <= 100000)
            {
                totalTax = income * 0.097f;
            }
            else if (income > 100000)
            {
                totalTax = income * 0.14f;
            }

            Console.WriteLine($"Total Tax: {totalTax.ToString("0.00")}");

            Console.WriteLine("Enter the number of lines to print:");
            int lines = int.Parse(Console.ReadLine());

            Console.WriteLine("\nTriangle:");
            for (int i = 1; i <= lines; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            Console.WriteLine("\nInverted Triangle:");
            for (int i = lines; i >= 1; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            Console.WriteLine("\nSquare:");
            for (int i = 1; i <= lines; i++)
            {
                for (int j = 1; j <= lines; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }
    }
}