namespace System
{
    class Person
    {
        private string name;
        private int age;

        public int Age
        {
            get { return age; }
            set { age = value; }
        }
        public void setName(string name)
        {
            this.name = name;
        }
        public string getName()
        {
            return this.name;
        }

        public void setName(int age)
        {
            this.age = age;
        }
        public int getAge()
        {
            return this.age;
        }
        public Person(string name, int age)
        {
            this.name = name;
            this.age = age;
        }

        public void Introduce()
        {
            Console.WriteLine("Hello, my name is " + name + " and I am " + age + " years old.");
        }
    }
}

public class HW5Classes
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter your name:");
        string name = Console.ReadLine();
        if(name == "" || name == null)
        {
            Console.WriteLine("Invalid name.");
            return;
        }

        Console.WriteLine("Enter your age:");
        int age = int.Parse(Console.ReadLine());
        if(age < 0|| age == null)
        {
            Console.WriteLine("Invalid age.");
            return;
        }

        Person person = new Person(name, age);
        person.Introduce();
    }
}