#include<stdio.h>
#include<time.h>

int water = 10;
int timer = 0;
int fish = 1;
int filter = 10;
int i = 0;
float waste = 0;
float ammonia = 0;
float nitrite = 0;
float nitrate = 0;

int main()
{
    //declare and init time vars
    time_t secondslast;
    time_t secondsnow;   
    secondslast = time(NULL);
    // start game loop
    while (1) {
    // set current time in seconds
    secondsnow = time(NULL);
    // check if one full second has passed

    if (secondsnow > secondslast) {
    // update secondslast var so next check doesnt loop immediately
    secondslast = time(NULL);
    // make incremental modifications to stats that change over time
    // waste builds up from fish and added food
    waste += (fish*0.00025);
    // biomedia in filter converts waste to ammonia, then nitrite, then nitrate
    // this for loop runs for each point of filter health
    // right now this should keep down the waste of 100 fish at full filter health
    // Balancing this stuff is TODO
     for (i = filter; i > 0; --i)
     {
         //setting all these up in if loops so they work fine when other stuff effects water params
         if (waste > .0005)
         {
             waste -= 0.0005;
             ammonia += 0.00025;
         }
        if (ammonia > 0.00025)
        {
            ammonia -= 0.00025;
            nitrite += 0.00015;
        }
        if (nitrite > 0.00015)
        {
            nitrite -= 0.00015;
            nitrate += 0.0001;        
        }
    //end of filter for loop
     }
    // lastly call the screen function to update ui
    screen();
    }
    // end bracket for gameloop
    }

//end bracket of main()
return 0;
}

void screen()
{
    // clear screen each pass before printing
    system("clear");
    // Print out UI
    printf("Aquarium Status \n    Gallons: %i \n    Fish: %i \n    Time Played: %i \n\n", water,fish,timer);
    printf("Biological Status \n    Filter Efficiency: %i \n    Waste Content: %f \n    Ammonia: %f \n    Nitrite: %f \n    Nitrate: %f \n", filter,waste,ammonia,nitrite,nitrate);
    // increment game timer as function is called once per second
    // converting this to hours, minutes, and seconds is on the TODO
    timer +=1;
}

void store()
{
}
