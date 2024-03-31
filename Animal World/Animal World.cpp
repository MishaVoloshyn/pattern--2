#include <iostream>
#include <string>

using namespace std;

class Continent abstract 
{
public:
    virtual void CreateContinent() abstract;
    virtual Carnivores* CreateCarnivores() abstract;
    virtual Herbivores* CreateHerbivores() abstract;
};

class Africa : public Continent 
{
public:
    void CreateContinent() override 
    {
        cout << "Africa" << endl;
    }

    Carnivores* CreateCarnivores() override 
    {
        Carnivores* carnivores = new Lion();
        carnivores->SetPower();

        return carnivores;
    }

    Herbivores* CreateHerbivores() override 
    {
        Herbivores* herbivores = new Wildebeest();
        herbivores->SetWeight();
        herbivores->SetLife();

        return herbivores;
    }
};

// Создатель фауны в Северной Америке
class NorthAmerica : public Continent {
public:
    void CreateContinent() override {
         cout << "North America\n";
    }
    Carnivores* CreateCarnivores() override 
    {
        Carnivores* carnivores = new Wolf();
        carnivores->SetPower();

        return carnivores;
    }
    Herbivores* CreateHerbivores() override 
    {
        Herbivores* herbivores = new Buffalo();
        herbivores->SetWeight();
        herbivores->SetLife();

        return herbivores;
    }
};

class AnimalWorld 
{
    Carnivores* carnivores;
    Herbivores* herbivores;
public:
    AnimalWorld(Continent* continent) 
    {
        carnivores = continent->CreateCarnivores();
        herbivores = continent->CreateHerbivores();
    }

    void Eat() 
    {
        herbivores->EatGrass();
    }
    void EatHerbivores() 
    {
        carnivores->Eat(herbivores);
    }
};


class Herbivores 
{
protected:
    double weight = 0;
    bool life = true;
public:

    virtual void SetWeight() = 0;
    virtual void SetLife() = 0;
    virtual void SetDeath() = 0;

    int GetWeight() 
    {
        return weight; 
    }

    void EatGrass()
    {
        cout << " + 10 weight" << endl;
        weight += 10;
    }
};


class Wildebeest : public Herbivores 
{
    void SetWeight() 
    {
        weight = 155;
    }
    void SetLife() 
    {
        life = true;
    }
    void SetDeath() 
    {
        life = false;
    }
};
class Buffalo : public Herbivores 
{
    void SetWeight() 
    {
        weight = 835;
    }
    void SetLife() 
    {
        life = true;
    }
    void SetDeath() 
    {
        life = false;
    }
};
class Elk : public Herbivores 
{
    void SetWeight() 
    {
        weight = 480;
    }
    void SetLife() 
    {
        life = true;
    }
    void SetDeath() 
    {
        life = false;
    }
};


class Carnivores {
protected:
    int power = 0;
public:
    void Eat(Herbivores* herbivores) 
    {
        if (power > herbivores->GetWeight()) 
        {
            cout << "+10 power" << endl;
            power += 10;
        }
        else 
        {
            cout << "-10 power" << endl;
            power -= 10;
        }

        herbivores->SetDeath();
    }

    virtual void SetPower() = 0;
};

class Lion : public Carnivores 
{
    void SetPower() 
    {
        power = 400;
    }
};
class Wolf : public Carnivores 
{
    void SetPower() 
    {
        power = 200;
    }
};
class Tiger : public Carnivores 
{
    void SetPower() 
    {
        power = 450;
    }
};

int main() {

    // Africa
    Continent* continent = new Africa();
    AnimalWorld* animalWorld = new AnimalWorld(continent);

    animalWorld->Eat();
    animalWorld->EatHerbivores();

    delete continent;
    delete animalWorld;


    // NorthAmerica
    continent = new NorthAmerica();
    animalWorld = new AnimalWorld(continent);

    animalWorld->Eat();
    animalWorld->EatHerbivores();

    delete continent;
    delete animalWorld;

    return 0;
}
