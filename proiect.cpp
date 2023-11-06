#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <string.h>
#include <cstring>

using namespace std;

//The Cast class represents actors and their roles
class Cast
{
private:
    string name; //Actor's name
    string func; //Actor's role or function
public:

   //Set the actor's name
    void SetName(string name)
    {
        this->name=name;
    }

    //Set the actor's role and function
     void SetFunc(string func)
    {
        this->func = func;
    }

    //Get the actor's name and role or function
    string GetName(string name)
    {
        return name;
    }
    string GetFunc(string func)
    {
        return func;
    }

};

//Generate a random name for actors
string randomName() {

  char consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
  char vowels[] = {'a','e','i','o','u','y'};
  int length=5;
  string name = "";

  int random = rand() % 2;
  int count = 0;

  for(int i = 0; i < length; i++) {

    if(random < 2 && count < 2) {
      name = name + consonents[rand() % 19];
      count++;
    }
    else {
      name = name + vowels[rand() % 5];
      count = 0;
    }

    random = rand() % 2;

  }

  return name;

}

//The Actori class represents actors and related operations
class Actori
{
private:
    string monstru; //Type of monster for the actor
    string mancare; //Type of food for the actor
    static int costMachiaj; //Daily makeup cost
    static int costMancare; //Daily food cost

public:
    //Choose the type of food for actors
    string alegereMancarea()
    {
        string tip[]= {"Apt", "Vegetarian", "Flexitarian"};
        int poz=rand() % 3;
        if(poz==0)
            costMancare = costMancare + 40;
        else if(poz==1)
            costMancare = costMancare + 33;
        else
            costMancare = costMancare + 46;
        mancare=tip[poz];
        return mancare;
    }
    //Choose the type of monster for actors
    string alegereMonstru()
    {
        string tip[]= {"Vamp","wolf","merm","Clair","man"};
        int poz=rand() % 5;
        if(poz==0)
            costMachiaj = costMachiaj + 230;
        else if(poz==1)
            costMachiaj = costMachiaj + 555;
        else if(poz==2)
            costMachiaj = costMachiaj + 345;
        else if(poz==3)
            costMachiaj = costMachiaj + 155;
        else
            costMachiaj = costMachiaj + 55;
        mancare=tip[poz];
        monstru=tip[poz];
        return monstru;
    }

    //Get the daily food cost for all actors
    static int costMancareZilnica()
    {
        return costMancare;
    }

    //Get the daily makeup cost for all actors
    static int costMachiajZilnic()
    {
        return costMachiaj;
    }
};

int Actori :: costMancare=0;
int Actori :: costMachiaj=0;

//The Personal class represents non-actor personnel
class Personal : public Actori
{
public:

    //Choose the type of monster for non-actor personnel (override)
    string alegeMonstru()
    {
        return "none";
    }
};

//The Transport class represents transportation and related operations
class Transport
{
public:
    //Calculate the number of buses required for a given number of people
    void cate (int n)
    {
        cout<<n/50+1;
    }

    //Calculate the transportation cost for a given number of people
    virtual int cost(int n)
    {
        return (n/50+1)*5680*2;
    }
};

// The Cazari class represents accommodation and related operations
class Cazari : public Transport
{
private:
    int room2;
    int room3;
public:
    // Calculate the cost of accommodation for a given number of people
    int cost(int n)
    {
        room2=(n-132)/2;
        room3=132/3;
        room2=room2*350;
        room3=room3*450;
        return (room2+room3);
    }
};

// The Total function calculates costs for different periods
void Total(int zile, int n, int c1, int c2, int c3)
{
    fstream file3("cost2.csv", ios::app);
    float dolar=4.63;
    Transport autocar;
    Cazari room;
    float costAutocar = autocar.cost(n) / dolar;
    float costCazare = room.cost(n) * zile / dolar;
    float costMachiaj = c1 * zile / dolar;
    float costMancare = (c2 + c3) * zile / dolar;
    float costApa = (n / 2 * 6) * zile / dolar;
    float costCafea = (n / 2 * 30) * zile / dolar;
    float costSuc = (n / 2.5 * 8) * zile / dolar;
    float costChirie = (10000 * zile - zile / 10 * (2 / 100) * 10000 * zile) / dolar;

    file3 << "---Perioada de " << zile << " de zile---" << endl;
    file3 << "Transport: " << "," << int(costAutocar) << "$" << endl;
    file3 << "Cazare: " << "," << int(costCazare) << "$" << endl;
    file3 << "Machiaj: " << "," << int(costMachiaj) << "$" << endl;
    file3 << "Mancare: " << "," << int(costMancare) << "$" << endl;
    file3 << "Apa: " << "," << int(costApa) << "$" << endl;
    file3 << "Cafea: " << "," << int(costCafea) << "$" << endl;
    file3 << "Suc: " << "," << int(costSuc) << "$" << endl;
    file3 << "Inchiriere spatiu: " << "," << int(costChirie) << "$" << endl << endl;
    file3.close();

}

int main()
{
    int i;


    string fname = "wednesdayCast.csv";
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file (fname, ios::in  );
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";

    for(i=0; i<content.size(); i++)
    {

        cout<<"name: " << content[i][0] << "\t" << "function: " << content[i][1] << endl;

    }
    file.close();

    //The new actors

    string name,func;
    string costum[7]={"vamp","wolf","merm","clair","man"};

    string fname1="wednesdayCast.csv";
    fstream file1 (fname1, ios::app );

    for (i=0; i<=132; i++)
    {

        name = randomName();
        func = costum[rand() %5];
        Cast p1;
        p1.SetName(name);
        p1.SetFunc(func);
       file1 << p1.GetName(name) << ',' << p1.GetFunc(func) << endl;


    }
    file1.close();

    //The meniu for 3 days

    string fname2="masa.csv";
    vector <string> row1;
    vector <vector<string>> meniu;
    string line1, word1;
    fstream f1 (fname2, ios::in);
    if (!file.is_open())
    {
        cout << "eroare la deschidere!!" << endl;

    }
    else
    {
        while(getline(f1,line1))
        {
            row1.clear();

            stringstream str(line1);

            while (getline (str, word1, ','))
                row1.push_back(word1);
            meniu.push_back(row1);
        }
    }
    f1.close();

    cout << "-------------MENIU 1------------" << endl;
    cout << "----- Meniu pentru cei apti ----" << endl;
    cout << "supa: " << meniu[rand() % 8][0] << endl;
    cout << "fel principal: " << meniu[(rand() % 9) + 8][0] << endl;
    cout << "desert: " << meniu[(rand() % 7) +17][0] << endl;
    cout << "----- Meniu pentru vegetarieni----" << endl;
    cout << "supa: " << meniu[rand() % 3 + 5][0] << endl;
    cout << "fel principal: " << meniu[(rand() % 3) + 14][0] << endl;
    cout << "desert: " << meniu[(rand() % 7) + 17][0] << endl;
    cout << "----- Meniu pentru flexitarieni ----" << endl;
    cout << "supa: " << meniu[rand() % 5 + 3][0] << endl;
    cout << "fel principal: "<<meniu[(rand() % 6) + 11][0] << endl;
    cout << "desert: "<<meniu[(rand() % 7) + 17][0] << endl << endl << endl;

    cout << "-------------MENIU 2------------" << endl;
    cout << "----- Meniu pentru cei apti ----" << endl;
    cout << "supa: "<< meniu[rand() % 8][0] << endl;
    cout << "fel principal: " << meniu[(rand() % 9) + 8][0] << endl;
    cout << "desert: " << meniu[(rand() % 7) + 17][0] << endl;
    cout << "----- Meniu pentru vegetarieni----" << endl;
    cout << "supa: " << meniu[rand() % 3 + 5][0] << endl;
    cout << "fel principal: " << meniu[(rand() % 3) + 14][0] << endl;
    cout << "desert: " << meniu[(rand() % 7) + 17][0] << endl;
    cout << "----- Meniu pentru flexitarieni ----" << endl;
    cout << "supa: " << meniu[rand() % 5 + 3][0] << endl;
    cout << "fel principal: " << meniu[(rand() % 6) + 11][0] << endl;
    cout << "desert: " << meniu[(rand() % 7) + 17][0] << endl << endl << endl;

    cout << "-------------MENIU 3------------" << endl;
    cout << "----- Meniu pentru cei apti ----" << endl;
    cout << "supa: " << meniu[rand() % 8][0] << endl;
    cout << "fel principal: "<<meniu[(rand() % 9) + 8][0] << endl;
    cout << "desert: " << meniu[(rand() % 7) + 17][0] << endl;
    cout << "----- Meniu pentru vegetarieni----" << endl;
    cout << "supa: " << meniu[rand() % 3 + 5][0] << endl;
    cout << "fel principal: " << meniu[(rand() % 3) + 14][0] << endl;
    cout << "desert: " << meniu[(rand() % 7) + 17][0] << endl;
    cout << "----- Meniu pentru flexitarieni ----" << endl;
    cout << "supa: " << meniu[rand() % 5 + 3][0] << endl;
    cout << "fel principal: " << meniu[(rand() % 6) + 11][0] << endl;
    cout << "desert: " << meniu[(rand() % 7) + 17][0] << endl;


    fstream des ("cost2.csv", ios::app);
    if (!des.is_open())
        cout << "eroare";
    else{
    Actori actori;
    Personal pers;
    string mancare, machiaj;
    int n=0;
    des<<"Nume"<<","<<"Functie"<<","<<"Dieta"<<","<<"Personaj"<<endl;
    for(int i=0; i<content.size(); i++)
    {
        if( content[i][1].find("actor",0)==0 || content[i][1].compare("figurant")==0)
        {
            mancare=actori.alegereMancarea();
            machiaj=actori.alegereMonstru();
        }
        else
        {
            mancare=pers.alegereMancarea();
            machiaj=pers.alegereMonstru();
        }
        des<<content[i][0]<<","<<content[i][1]<<","<<mancare<<","<<machiaj<<endl;
        n++;
    }

    des.close();
    n++;

    int c1=actori.costMachiajZilnic();
    int c2=actori.costMancareZilnica();
    int c3=pers.costMancareZilnica();


    Total(30,n,c1,c2,c3);
    Total(45,n,c1,c2,c3);
    Total(60,n,c1,c2,c3);
    Total(100, n, c1,c2,c3);
    }


    return 0;

}
