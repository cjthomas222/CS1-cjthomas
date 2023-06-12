using System;

namespace HW7
{
    public class Vehicle
    {
        protected string Type { get; set; }
        protected string Model { get; set; }
        protected int Year { get; set; }
    
        public virtual void StartEngine()
        {
            Console.WriteLine($"Starting the {Type} engine...");
        }
    
        public virtual void StopEngine()
        {
            Console.WriteLine($"Stopping the {Type} engine...");
        }
    
        public virtual void Accelerate()
        {
            Console.WriteLine($"The {Type} is accelerating.");
        }
    
        public virtual void Brake()
        {
            Console.WriteLine($"The {Type} is braking.");
        }
    }
    
    public class Car : Vehicle
    {
        public Car(string model, int year)
        {
            Type = "Car";
            Model = model;
            Year = year;
        }
    
        public override void StartEngine()
        {
            base.StartEngine();
            Console.WriteLine($"The {Type} {Model} ({Year}) engine is running smoothly.");
        }
    
        public override void Accelerate()
        {
            base.Accelerate();
            Console.WriteLine($"The {Type} {Model} is picking up speed.");
        }
    }
    
    public class Truck : Vehicle
    {
        public Truck(string model, int year)
        {
            Type = "Truck";
            Model = model;
            Year = year;
        }
    
        public override void StartEngine()
        {
            base.StartEngine();
            Console.WriteLine($"The {Type} {Model} ({Year}) engine is revving up.");
        }
    
        public override void Brake()
        {
            base.Brake();
            Console.WriteLine($"The {Type} {Model} is slowing down.");
        }
    }
    
    public class Program
    {
        public static void Main(string[] args)
        {
            Car car = new Car("Sedan", 2022);
            car.StartEngine();
            car.Accelerate();
    
            Console.WriteLine();
    
            Truck truck = new Truck("Pickup", 2021);
            truck.StartEngine();
            truck.Brake();
        }
    }
}