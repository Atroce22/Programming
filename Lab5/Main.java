import java.util.Scanner;
import java.util.List;
import java.util.Random;


class Character {
    private String name;
    private String race;
    private int level = 0;
    private int health = 0;
    private int mana = 0;
    private int experience = 0;
    private float damage = 0;
    private boolean dead = false;
    private Random random = new Random();
    public static final List<String> NAMES = List.of("Lo Whitbottom", "Meginhard Swiftfoot", "Godomar Gawkroger", "Gerontius Chubb - Baggins", "Walcaud Leafwalker", "Griffon Harfoot", "Balbo Sackville", "Butilin Lothran", "Willehad Silverstring", "Berengar Undertree");
    public static final List<String> RACES = List.of("Human", "Orc", "Elf", "Hobbit", "Charr", "Norn");
    private Equipment left_hand = null;
    private Equipment right_hand = null;
    
    public void init(String name) {
        this.name = name;
        race = "Human";
        level = 1;
        health = 40;
        mana = 20;
        damage = 5;
        experience = 0;
    }

    public void init() {
        name = NAMES.get(random.nextInt(NAMES.size()));
        race = RACES.get(random.nextInt(RACES.size()));
        level = random.nextInt(10 + 1);
        left_hand = new Equipment(random.nextInt(25 + 1));
        right_hand = new Equipment(random.nextInt(25 + 1));
        update_data();
    }

    public String read() {
        Scanner in = new Scanner(System.in);
        System.out.println("Input character name: ");
        String s = in.nextLine();
        return s;
    }

    public void display() {
        System.out.printf("Name: %s%nRace: %s%nLevel: %d%nExperience: %d / 100%nHealth: %d%nMana: %d%nDamage: %f (%f + %d)%n%n", name, race, level, experience, health, mana, get_damage(), damage, get_equipment_damage());
    }

    public void level_up() {
        level++;
        update_data();
    }

    public void add(int exp) {
        experience += exp;
        while (experience >= 100)
        {
            experience -= 100;
            level_up();
        }
    }

    public void take_damage(int dmg){ 
        health -= dmg;
        if (health <= 0)
        {
            health = 40 * level;
            experience = 0;
            dead = true;
            System.out.println("You're dead\n");
        }
    }

    public String get_race() {
        return race;
    }

    public int get_level() {
        return level;
    }

    public int get_health() {
        return health;
    }

    public int get_mana() {
        return mana;
    }

    public int get_experience() {
        return experience;
    }

    public float get_damage(){ 
        return damage + get_equipment_damage();
    }

    private void update_data() {
        health = 40 * level;
        mana = 20 * level;
        damage = 5 * level;
    }

    private int get_equipment_damage() {
        int final_damage = 0;
        if (left_hand != null)
            final_damage += left_hand.get_damage();
        if (right_hand != null)
            final_damage += right_hand.get_damage();
        return final_damage;
    }
}

class Equipment {
    private String name;
	private int weight = 0;
	private int price = 0;
	private int damage = 0;

    public Equipment() {}
	public Equipment(int dmg)
    {
        damage = dmg;
    }

	public int get_damage()
    {
        return damage;
    }
}

public class Main {
	  public static void main(String[] args) { 
        Character player = new Character();
        player.init();
        player.display();
    }
}