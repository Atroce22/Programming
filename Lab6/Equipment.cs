using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    class Equipment
    {
        private string name;
        private int weight = 0;
        private int price = 0;
        private int damage = 0;

        public Equipment() { }
        public Equipment(int dmg)
        {
            damage = dmg;
        }

        public int GetDamage()
        {
            return damage;

        }
    }
}
