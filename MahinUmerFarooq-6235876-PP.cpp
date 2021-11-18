#include <iostream>
#include <time.h>



//Random generators created to distribute cards to the player and the banker
int randomPlayer(int random) {
    std::time_t t = time(0);
    random = t % 13;
    if (random == 0) {
        random = random + 1;
    }
    return random;
            
}
int randomBanker(int random) {
    std::clock_t t = clock();
    random = t % 13;
    if (random == 0) {
        random = random + 1;
    }
    return random;
} 

int main()
{
    
    std::cout << "******Welcome to DesertLand Resort!****** " << std::endl;
    int Playercount = 0; //player's card value 
    int Bankercount = 0; //banker's card value 
    int points = 500; //player's points
    int playerPoints = 0; //player's wins
    int bankerPoints = 0; //banker's wins

    //for loop runs 5 times which is the duration of the game - 5 rounds. 
    for (int i = 0; i < 5;) {
        std::cout << "Press 'h' to see the rules of the card game" << std::endl; //random
        std::cout << "Press 's' to play the " << i+1 << " round of the simple card game" << std::endl; //5
        std::cout << "Press 'q' to quit" << std::endl; //1
        std::cout << "Input your choice" << std::endl;

        char choice;
        std::cin >> choice; //user input is taken for the menu
        std::cout << "***********************************************************************************\n";

        int player =0; //random inputs for the randomizer 
        int banker=0;
        
        

        
        if (choice == 'h') { //if user picks 'h' then the rules are displayed
            std::cout << "RULES: \n 1. A player can play against the banker only. \n 2. Both the player and the banker receive a card from the card deck \n 3. The person with the highest card value will be the WINNER. \n 4. Each round has a fixed bet of $10 points. \n NOTE: In the event of a tie, the banker is declared as winner\n----------------------------------------------------------------\n" << std::endl;
        }

        else if (choice == 's') { //the first round is started when user picks s
            std::cout << "Starting game! \n\nShuffling and Dealing cards:\n" << std::endl;

            Playercount = randomPlayer(player); //player is assigned a card
            std::cout << "*Player card: " << Playercount << "*\n";
           
            Bankercount = randomBanker(banker); //banker is assigned a card
            std::cout << "*Banker card: " << Bankercount << "*\n";

            i++; //i which is the round number is incremented only when user picks 's'. 

            if (Playercount > Bankercount) { //if player's card is bigger than banker's then player gets 10 points
                points += 10;
                std::cout << "*You win this round*\n**********************************************************************************" << std::endl;
                playerPoints++;
            }
            else {
                points -= 10; //else 10 points are deducted
                std::cout << "*Banker wins this round*\n**********************************************************************************\n" << std::endl;
                bankerPoints++;
            }

            
        }

        else if(choice == 'q') { //if 'q' is chosen, then game is closed
            exit(1);
        }
        

    }
    int c = 'a';
    while (c == 'a' ) { //random value is assigned to an integer which is later used to shut game down.
        if (playerPoints > bankerPoints) {
            std::cout << "***Congratulations! You Win!***\n" << std::endl;

        }
        else {
            std::cout << "---The banker wins. Try again next time :( ---\n" << std::endl;
        }
        std::cout << "***********************************" << std::endl;
        std::cout << "*Thank you for playing !          *" << std::endl;
        std::cout << "*Your total points are:" << points << "        *" << std::endl;

        std::cout << "*press q and enter to exit        *" << std::endl; 
        std::cout << "***********************************" << std::endl;
        std::cin >> c;

    }
}

