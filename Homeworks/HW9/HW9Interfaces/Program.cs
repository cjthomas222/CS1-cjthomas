using System;

namespace HW9Interfaces
{
    public interface IDog
    {
        void Bark();
        void Fetch();
    }

    public class Dog: IDog
    {
        public void Bark()
        {
            Console.WriteLine("Woof!");
        }

        public void Fetch()
        {
            Console.WriteLine("Fetching...");
        }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            Dog dog = new Dog();
            dog.Bark();
            dog.Fetch();
        }
    }
}