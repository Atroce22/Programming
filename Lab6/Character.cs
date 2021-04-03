using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    class Character
    {
        public static List<string> NAMES = new List<string> { "Lo Whitbottom", "Meginhard Swiftfoot", "Godomar Gawkroger", "Gerontius Chubb - Baggins", "Walcaud Leafwalker", "Griffon Harfoot", "Balbo Sackville", "Butilin Lothran", "Willehad Silverstring", "Berengar Undertree" };
        public static List<string> RACES = new List<string> { "Human", "Orc", "Elf", "Hobbit", "Charr", "Norn" };

        private static Random random = new Random();
        private static int counter = 0;

        public string Name { get; set; }
        public string Race { get; set; }
        private int level;
        public int Level { get { return level; } set { level = value; UpdateData(); } }
        public int Health { get; set; }
        public int Mana { get; set; }
        public int Experience { get; set; }
        public float Damage { get; set; }
        private bool dead = false;
        public int Id { get; set; }
        private Equipment leftHand = null;
        private Equipment rightHand = null;

        public static Character operator ++(Character character) { character.Level += 1; return character; }

        public static int GetCounter()
        {
            return counter;
        }
        public Character(string name)
        {
            Name = name;
            Race = RACES[random.Next(RACES.Count)];
            Level = random.Next(10) + 1;
            leftHand = new Equipment(random.Next(25) + 1);
            rightHand = new Equipment(random.Next(25) + 1);
            Id = counter++;
            UpdateData();
        }
        public Character(string name, string race, int level, Equipment left, Equipment right )
        {
            Name = name;
            Race = race;
            Level = level;
            leftHand = left;
            rightHand = right;
            Id = counter++;
            UpdateData();
        }

        public Character()
        {
            Name = NAMES[random.Next(NAMES.Count)];
            Race = RACES[random.Next(RACES.Count)];
            Level = random.Next(10) + 1;
            leftHand = new Equipment(random.Next(25) + 1);
            rightHand = new Equipment(random.Next(25) + 1);
            Id = counter++;
            UpdateData();
        }

        public string Read()
        {
            Console.WriteLine("Input character name: ");
            return Console.ReadLine();
        }

        public void Display()
        {
            Console.WriteLine(string.Format("ID: {9}\nName: {0}\nRace: {1}\nLevel: {2}\nExperience: {3} / 100\nHealth: {4}\nMana: {5}\nDamage: {6} ({7} + {8})\n\n", Name, Race, Level, Experience, Health, Mana, GetDamage(), Damage, GetEquipmentDamage(), Id));
        }

        public static void Display(Character character)
        {
            character.Display();
        }

        public void LevelUp()
        {
            level++;
        }

        public void Add(int exp)
        {
            Experience += exp;
            while (Experience >= 100)
            {
                Experience -= 100;
                LevelUp();
            }
        }

        public void TakeDamage(int dmg)
        {
            Health -= dmg;
            if (Health <= 0)
            {
                Health = 40 * level;
                Experience = 0;
                dead = true;
                Console.WriteLine("You're dead\n");
            }
        }

        public Equipment GetLeftHand()
        {
            return leftHand;
        }
        public Equipment GetRightHand()
        {
            return rightHand;
        }

        public float GetDamage()
        {
            return Damage + GetEquipmentDamage();
        }

        private void UpdateData()
        {
            Health = 40 * level;
            Mana = 20 * level;
            Damage = 5 * level;
        }

        private int GetEquipmentDamage()
        {
            if (leftHand != null && rightHand != null)
                return leftHand + rightHand;
            return 0;
        }
        
    
}
}
