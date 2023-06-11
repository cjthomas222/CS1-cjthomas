using System;

namespace HW6
{
    public class Dog
    {
        private string name;

        public string Name
        {
            get { return this.name; }
            set { this.name = value; }
        }

        public void makeNoise()
        {
            Console.WriteLine("Bark");
        }
    }

    public class HW6Inheritance : Dog
    {
        static void main(string[] args)
        {
            Dog dog = new Dog();
            dog.Name = "Fido";
            Console.WriteLine(dog.Name);
            dog.makeNoise();
        }
    } 
}