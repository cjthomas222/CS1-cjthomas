using System;

namespace HW1Types
{
    class HW1
    {
        static void Main(string[] args)
        {
            int myInt = 42;
            decimal myDecimal = 3.14m;
            string myString = "Help me, Obi-Wan Kenobi. You're my only hope";
            char myChar = 'F';

            Console.WriteLine("Initial values:");
            Console.WriteLine($"myInt: {myInt}");
            Console.WriteLine($"myDecimal: {myDecimal}");
            Console.WriteLine($"myString: {myString}");
            Console.WriteLine($"myChar: {myChar}");

            myInt = 10;
            myDecimal = 4.505m;
            myString = "Test";
            myChar = 'B';

            Console.WriteLine("\nUpdated values:");
            Console.WriteLine($"myInt: {myInt}");
            Console.WriteLine($"myDecimal: {myDecimal}");
            Console.WriteLine($"myString: {myString}");
            Console.WriteLine($"myChar: {myChar}");

            Console.WriteLine("\nEnter the lengths of the three sides of the triangle:");

            Console.Write("Side 1: ");
            double side1 = double.Parse(Console.ReadLine());

            Console.Write("Side 2: ");
            double side2 = double.Parse(Console.ReadLine());

            Console.Write("Side 3: ");
            double side3 = double.Parse(Console.ReadLine());

            double semi = (side1 + side2 + side3) / 2;
            double area = Math.Sqrt(semi * (semi - side1) * (semi - side2) * (semi - side3));

            Console.WriteLine($"The area of the triangle is: {area}");

            Console.ReadLine();
        }
    }
}