using System;

namespace Project2
{
    public class Point
    {
        public int X { get; set; }
        public int Y { get; set; }
    
        public Point(int x, int y)
        {
            X = x;
            Y = y;
        }
    
        public static Point operator +(Point point1, Point point2)
        {
            int resultX = point1.X + point2.X;
            int resultY = point1.Y + point2.Y;
            return new Point(resultX, resultY);
        }
    
        public static Point operator *(Point point, int scale)
        {
            int resultX = point.X * scale;
            int resultY = point.Y * scale;
            return new Point(resultX, resultY);
        }
    
        public static Point operator *(Point point1, Point point2)
        {
            int resultX = point1.X * point2.X;
            int resultY = point1.Y * point2.Y;
            return new Point(resultX, resultY);
        }
    
        public override string ToString()
        {
            return $"({X}, {Y})";
        }
    
        public static bool operator ==(Point point1, Point point2)
        {
            if (ReferenceEquals(point1, null))
                return ReferenceEquals(point2, null);
    
            return point1.Equals(point2);
        }
    
        public static bool operator !=(Point point1, Point point2)
        {
            return !(point1 == point2);
        }
    
        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType())
                return false;
    
            Point other = (Point)obj;
            return X == other.X && Y == other.Y;
        }
    
        public override int GetHashCode()
        {
            return (X << 2) ^ Y;
        }
    }
    
    public class PointCalculator
    {
        public static void Main(string[] args)
        {
            Point point1 = new Point(3, 4);
            Point point2 = new Point(5, 6);
    
            Point additionResult = point1 + point2;
            Console.WriteLine($"Addition: {point1} + {point2} = {additionResult}");
    
            Point scaleResult = point1 * 2;
            Console.WriteLine($"Scaling: {point1} * 2 = {scaleResult}");
    
            Point multiplicationResult = point1 * point2;
            Console.WriteLine($"Multiplication: {point1} * {point2} = {multiplicationResult}");
    
            bool isEqual = point1 == point2;
            Console.WriteLine($"Comparison: {point1} == {point2} ? {isEqual}");
    
            bool isNotEqual = point1 != point2;
            Console.WriteLine($"Comparison: {point1} != {point2} ? {isNotEqual}");
        }
    }
}