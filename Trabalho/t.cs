using System;

class Program {
  static void Main(string[] args) {
    int a, b, c;
    string[] input = Console.ReadLine().Split();
    a = int.Parse(input[0]);
    b = int.Parse(input[1]);
    c = int.Parse(input[2]);
    if(a > b)
    {
        if(b > c)
        {
            if((b - c) < (a - b)) Console.WriteLine(":)");
            else Console.WriteLine(":(");
        }
        else Console.WriteLine(":)");
    }
    else if(b > a)
    {
        if(c > b)
        {
            if((c - b) < (b - a)) Console.WriteLine(":(");
            else Console.WriteLine(":)");
        }
        else Console.WriteLine(":(");
    }
    else if(c > b) Console.WriteLine(":)");
    else Console.WriteLine(":(");
  }
}