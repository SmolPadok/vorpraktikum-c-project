/*
Vorpraktikum - C Programming Group Project
TTO: Sir Syam Firdaus Bin Muhammad Ali

Qayyum Yazid
Abdul Hakim
Eiyad Al-Fathoni
*/

//Include libraries
#include <stdio.h> //input output
#include <ctype.h> //convert to lowercase
#include <stdlib.h> //general purpose
#include <string.h> //handle string comparison
#include <time.h> //time as random seed

//Define constants
#define MAX_SIZE 256
#define N_OBJ_QUESTIONS 5
#define N_SUB_QUESTIONS 5

//Define structs for questions
//Using structs help organize properties of a question into a single data type.
//This helps with iteration and ordering by defining them as an array of questions, instead of adding questions manually.

struct obj_question {
    char title[MAX_SIZE];
    char answer_a[MAX_SIZE];
    char answer_b[MAX_SIZE];
    char answer_c[MAX_SIZE];
    char answer_d[MAX_SIZE];
    char answer;
};

struct sub_question {
    char title[MAX_SIZE];
    char desc[MAX_SIZE];
    char answer[MAX_SIZE];
};

//Objective Questions
struct obj_question objectives[N_OBJ_QUESTIONS] = {
    {
        //Question 1
        "What colour is not in the rainbow?",
        "Red",
        "Indigo",
        "Yellow",
        "Purple",
        'd'
    },
    {
        //Question 2
        "Which of these waves has the highest frequency?",
        "X-Ray",
        "Gamma Ray",
        "Ultraviolet",
        "Radio Waves",
        'b'
    },
    {
        //Question 3
        "Which of these quantities is a base quantity?",
        "Mass",
        "Force",
        "Weight",
        "Power",
        'a'
    },
    {
        //Question 4
        "How many letters are there in the alphabet?",
        "26",
        "27",
        "25",
        "20",
        'a'
    },
    {
        //Question 5
        "When was the C language created?",
        "2002",
        "1972",
        "1967",
        "1988",
        'b'
    }
};

struct sub_question subjectives[N_SUB_QUESTIONS] = {
    { 
        //Question 1
        "Who is the first Prime Minister of Malaysia?",
        "This answer has 3 words. Capitalize the start of each word.",
        "Tunku Abdul Rahman"
    },
    {
        //Question 2
        "When is Malaysia's Independence Day?",
        "Write in this example format: 1 January 1970",
        "31 August 1957"
    },
    {
        //Question 3
        "What is the symbol for Sodium in the Periodic Table?",
        "",
        "Na"
    },
    {
        //Question 4
        "What is the product of combustion of hydrocarbons?",
        "List 2 formulas separated by and",
        "CO2 and H2O"
    },
    {
        //Question 5
        "What is the name of the mathematical constant of value 3.142..",
        "",
        "Pi"
    }
};

void pause(){ //pause function helps clear the input buffer and prevent a bouncing issue

    fflush(stdin);
    printf("Press [Enter] key to continue.");
    while(getchar()!='\n'); // option TWO to clean stdin
    getchar(); // wait for ENTER

}

void clear(){ //clear function to clear the console and make the output cleaner
    system("clear");
}

int calculateObjScore(const char user[], const char answers[]){
    
    //compare user answers with correct answers and return the total correct score
    int score = 0;
    for(int i = 0; i < N_OBJ_QUESTIONS; i++){
        if(user[i] == answers[i]){
            score++;
        }
    }
    return score;
}

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

    //Assign user variables
    char name[MAX_SIZE];
    char id[9];

void main (){

    clear();

    srand(time(NULL));
    int r = (rand() % 5) + 1;

    int orderObj[N_OBJ_QUESTIONS];
    int orderSub[N_SUB_QUESTIONS];

    for(int i = 0; i < N_OBJ_QUESTIONS; i++){
        orderObj[i] = i;
    }
    for(int i = 0; i < N_SUB_QUESTIONS; i++){
        orderSub[i] = i;
    }

    shuffle(orderObj, r);
    shuffle(orderSub, r);

    char user_obj_answers[N_OBJ_QUESTIONS];
    char correct_obj_answers[N_OBJ_QUESTIONS];

    char user_sub_answers[N_SUB_QUESTIONS][MAX_SIZE];
    char *correct_sub_answers[N_SUB_QUESTIONS];

    //Create correct objective answer array
    for (int i = 0; i < N_OBJ_QUESTIONS; i++){
        int reorder = orderObj[i];
        correct_obj_answers[i] = objectives[reorder].answer;
    }

    for (int i = 0; i < N_SUB_QUESTIONS; i++){
        int reorder = orderSub[i];
        correct_sub_answers[i] = subjectives[reorder].answer;
    }


    //Ask student name
    printf ("WELCOME TO THE QUIZ\n");
    printf ("Enter your name: ");
    scanf ("%[^\n]", &name);

    clear();

    //Ask student ID
    printf ("WELCOME TO THE QUIZ\n");
    printf("Hello %s!\n", name);
    printf("Enter your student ID: ");
    scanf ("%s", &id);
    while(id[0] != 'G'){
        printf("Invalid ID. Please ensure the ID is in the following format: G20060066.\nEnter your Student ID: ");
        scanf ("%s", &id);
    }

    clear();

    //Section A Instructions
    printf("SECTION A\n");
    printf("You will be answering 5 objective questions. In each question, there are 4 choices. Type the letter you think is the correct answer.\n");
    pause();

    //Iterate through objective questions
    for(int i = 0; i < N_OBJ_QUESTIONS; i++){
        int reorder = orderObj[i];
        printf("\n%d) %s\n", i + 1, objectives[reorder].title);
        printf("(A) %s\n", objectives[reorder].answer_a);
        printf("(B) %s\n", objectives[reorder].answer_b);
        printf("(C) %s\n", objectives[reorder].answer_c);
        printf("(D) %s\n", objectives[reorder].answer_d);
        printf("\nInput your answer: ");
        scanf("%c", &user_obj_answers[i]);
        pause();
    }

    //Convert answers to lowercase for easy checking
    for(int i = 0; i < N_OBJ_QUESTIONS; i++){
        user_obj_answers[i] = tolower(user_obj_answers[i]);
    }
    
    clear();

    //Section B Instructions
    printf("SECTION B\n");
    printf("You will be answering 5 subjective questions. Follow the instructions and type in your answer according to the requested format.\n");
    pause();

    //Iterate through subjective questions
    for(int i = 0; i < N_SUB_QUESTIONS; i++){
        int reorder = orderSub[i];
        printf("\n%d) %s", i + 1 + N_OBJ_QUESTIONS, subjectives[reorder].title);
        if (subjectives[reorder].desc[0] != '\0')
        {
            printf("\n%s", subjectives[reorder].desc);
        }
        printf("\nInput your answer: ");
        scanf("%[^\n]", &user_sub_answers[i]);
        pause();
    }
    /*
    //Debugging: Print user answers
    printf("DEBUG\n");
    for(int i = 0; i < N_SUB_QUESTIONS; i++){
        printf("%d) %s\n", i, user_sub_answers[i]);
    }
    printf("DEBUG\n");
    for(int i = 0; i < N_SUB_QUESTIONS; i++){
        printf("%d) %s\n", i, correct_sub_answers[i]);
    }
*/

    clear();

    int objScore = calculateObjScore(user_obj_answers, correct_obj_answers);

    int subScore = 0;

    //Check subjective answers here, because don't know how to pass 2-dimensional array to function :(
    for(int i = 0; i < N_SUB_QUESTIONS; i++){
        int check = strcmp(user_sub_answers[i], correct_sub_answers[i]);
        if(check == 0){
            subScore++;
        }
    }

    int totalScore = objScore + subScore;
    int totalQuestions = N_OBJ_QUESTIONS + N_SUB_QUESTIONS;
    char grade;

    switch (totalScore)
    {
    case 10:
        grade = 'A';
        break;
    case 9:
        grade = 'A';
        break;
    case 8:
        grade = 'A';
        break;
    case 7:
        grade = 'A';
        break;
    case 6:
        grade = 'B';
        break;
    case 5:
        grade = 'B';
        break;
    case 4:
        grade = 'C';
        break;
    case 3:
        grade = 'C';
        break;
    case 2:
        grade = 'D';
        break;
    case 1:
        grade = 'E';
        break;
    case 0:
        grade = 'F';
        break;
    default:
        grade = 'F';
        break;
    }

    printf("QUIZ COMPLETE\n");
    printf("Name: %s\n", name);
    printf("ID: %s\n", id);
    printf("Your result is %d/%d\n", totalScore, totalQuestions);
    printf("Your grade is: %c\n", grade);
    pause();

}

