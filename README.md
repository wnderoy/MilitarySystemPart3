Part 3: 
 - we mooved from char* into Strings
 - insted of raw arrays using pointers, we now use Vectors
 - manual memory managment is gone thanks to vectors

additinaly, after review with Keren, we fixed const methods returning pointers, and we now return const refrense.

ניתוח אופציות:
Military System:
 - ​	The biggest project containing a wide variety of classes.
 - ​	Date should be used in mission as well.
 - ​	in this system, it might be a good choise to save person arrays only inside each base, insted of an additional global array for all systems. in truth, every soldjier should be a assiend to a base, making the larger array redundant.
Farmville: 
* Doesn't have any Readme or visual representations, making it very difficult to understand the system and the connections between classes 
Social Lens:
* A bit too simple, not many classes, and they all play a similar role.
Supply chain:
* The project structure is sound, but I personally avoid generic projects. I find that the story is crucial for confronting difficult decisions.

After consideration, we chose military system for its complex logic and scale, forcing us to implement the classes carefully and providing a challenge.


(Monday - 29/06/2026) 
We have added support for operator<< function for printing date details in Date.h and support for operator<< function for printing rank details in Soldier.h.

in Equipment: we decided to implement operator<< insted of the printing function. also, we implemented a move ctor, as we dont have a copy ctor, and we might want to move equipments between bases.
note: we did end up implementing print, as it was in the header file and is requierd by class Warehouse.

in Truck: ctor doesnt have variable for capacity, that means we hard code it to 10. ok defualt value, but we also never change it, so we should either:
    - allocate the array staticly insted of dinamicly, as the array size is known
    - or we can enter the capcaity in the ctor and give it a defualt value of 10 to retain the original function.
im going with static allocation, as arrays dont change capacity often as so do trucks.
that means im changing the array atribute defention in .h

we kept capacity variable so other classes can refrence it (im writing this while partner is working on other classes, so i want to keep changes to a minimum)
but we changed it to a static const variable

Wearhouse: we are agian in a simular decision to the one it Truck: should capacity be static const? or should it be a variable. the. original header doesnt spesfiy beacuse the ctor does not receive a capacity. we either change ctor for a variable, or change the field capacity to static. this time ill show a variable version, as opposed to our decision in truck.
thuse we change the header a bit

added cout <<, but kept print beacuse it was in the header file.
