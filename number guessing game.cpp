#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    //declaring variables
    int number, random;
    int attempt = 1;

    //prompt user input
    cout<<"Guess a number between 1 to 10 : ";
    //input a number
    cin>>number;

    srand(time(0));  //seeding a random number with current time

    random = rand()% 10 + 1;//generating a random number between 1 and 10

    while(number != 0)  //loops until the user input value 0
    {
        if(number == random) //checks if the guessed number equals to the random number
        {
            cout<<"you guessed correctly, with : "<<attempt<<" attempts"<<endl; //displays a message
            break; //breaks the while loop
        }
        else if(number > random)
        {
            cout<<"The guess is too high"<<endl;   //displays a message
        }
        else if(number < random)
        {
            cout<<"The guess is too low"<<endl;    //displays a message
        }
        attempt+=1; //accumulates the number of attempts

        //prompt user input
        cout<<"Guess a number between 1 to 10 : ";
        //input a number
        cin>>number;
    }

    cout<<"| Thanks for playing the guess game |"<<endl;


    return 0; // end of program
}