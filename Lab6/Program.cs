using System;

namespace Lab6
{
    class Program
    {
        public static void LevelUp(ref Character player)
        {
            player.Level++;
        }
        public static void CreateDefaultName(out string name)
        {
            name = "Default Name";
        }
        static void Main(string[] args)
        {
            
            string name;
            CreateDefaultName(out name);
            Character player = new Character(name, "Human", 3, new Equipment(1), new Equipment(10));
            player.Display();
            LevelUp(ref player);
            player++;
            Character.Display(player);

            Character player1 = new Character(name);
            player1.Display();

            Character[] players = new Character[5];
            for (int i = 0; i < players.Length; i++)
            {
                players[i] = new Character();
                players[i].Display();
            }
            Console.WriteLine("Created characters count: " + Character.GetCounter());
            Console.ReadKey();
        }
    }
}