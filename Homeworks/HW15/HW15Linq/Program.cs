
namespace HW15
{
    public class HW15Linq
    {
        public static void Main(string[] args)
        {
            //LAMBDA::
            Console.WriteLine("LAMBDA Examples::");
            // List<int> list = new List<int>();
            // for(int i = 0; i< 100; i++)
            // {
            //     list.Add(i);
            // }

            // List<int> even = new List<int>();
            // even = list.FindAll(x => x % 2 == 0);
            // foreach (int i in even)
            // {
            //     Console.WriteLine(i);
            // }

            Console.WriteLine("Area of square with side length 5:");
            Func<int,int> square = x => x * x;
            Console.WriteLine(square(5));

            List<string> list = new List<string>() { "Connor", "Jeff", "Sally", "Sarah", "Tom" };
            List<string> subset = list.FindAll(x => x.Length == 4);
            Console.WriteLine("Names with 4 letters:");
            foreach (string s in subset)
            {
                Console.WriteLine(s);
            }

            Console.WriteLine("Greeting:");
            Action<string> greet = name => Console.WriteLine($"Hello {name}");
            greet("Connor");

            // Func<int,int,bool> isEqual = (x,y) => x == y;
            // Console.WriteLine(isEqual(5,5));

            // //LINQ::
            Console.WriteLine("LINQ Examples::");
             List<string> names = new List<string>() { "Connor", "Jeff", "Sally", "Sarah", "Tom" };
            // //List<string> subset = names.FindAll(name[0] == 'J');
            IEnumerable<string> subset2 = from name in names
                                         where name[0] == 'C'
                                         select name;
            Console.WriteLine("Names that start with C:");
            foreach (var i in subset2)
            {
                Console.WriteLine(i);
            }

            
            var ascending = from name in names
                            orderby name ascending
                            select name;
            
            Console.WriteLine("Names in ascending order:");
            foreach (var i in ascending)
            {
                Console.WriteLine(i);
            }

        }
    }
}