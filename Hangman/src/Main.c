#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <conio.h>
#include <stdlib.h>

//functions
void Fhelp();
void Fhangman(int display);
int Fplaygame();

int main()
{
	int option, i = 1;
	do {
		printf("{}    {}   {}{}   {}    {}   {}}}}}   {}      {}   {}{}   {}    {}\n{}    {}  {}  {}  {}}}  {}   {}   {}  {}}}  {{{}  {}  {}  {}}}  {}\n{}{{}}{} {}{{}}{} {} {} {}   {}       {} {{}} {} {}{{}}{} {} {} {}\n{}    {} {}    {} {}  {{{}   {} {{{{  {}  {}  {} {}    {} {}  {{{}\n{}    {} {}    {} {}    {}    {}}}} } {}      {} {}    {} {}    {}\n");
		printf("     -------\n     |     |\n     |     @\n     |   --|--\n     |     |\n     |   -- --\n_____|__________\n\n");
		printf("\n\t\t\t1. Play Game\n\t\t\t2.Help/How to play\n\t\t\t3.Quit\nOption:_\b");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			Fplaygame();
			i = 0;
			break;
		case 2:
			Fhelp();
			system("cls");
			break;
		case 3:
			i = 0;
		default:
			system("cls");
			printf("Try again!!\n\n");
		}
	} while (i == 1);

	system("pause");
	return(0);
}

void Fhelp()
{
    system("cls");
	printf("Welcome to the game Hangman!\nEnter your guess one letter at the time.\nThe objective in this game is to guess the word.\nYou can enter both uppercase and lowercase letters.\nYou will loose if you have guessed 5 letters wrong.\n\n\t\tEnter 0 to return.\n");
	//system("pause");
	int i;
	for(i=0;i<1000000000;i++);

}

//2. hangman
void Fhangman(int display)
{
	//printf("\n\tHANGMAN\n*********************\n*     -------       *\n*     |     |       *\n*     |     @       *\n*     |   --|--     *\n*     |     |       *\n*     |   -- --     *\n*_____|__________   *\n*********************\n");
	switch (display)
	{
	case 0:
		printf("\n\tHANGMAN\n*********************\n*     -------       *\n*     |     |       *\n*     |     @       *\n*     |   --|--     *\n*     |     |       *\n*     |   -- --     *\n*_____|__________   *\n*********************\n");
		printf("Game OVER !!!\n");
		break;
	case 1:
		printf("\n\tHANGMAN\n*********************\n*     -------       *\n*     |     |       *\n*     |     @       *\n*     |   --|--     *\n*     |     |       *\n*     |   --        *\n*_____|__________   *\n*********************\n");
		break;
	case 2:
		printf("\n\tHANGMAN\n*********************\n*     -------       *\n*     |     |       *\n*     |     @       *\n*     |   --|--     *\n*     |     |       *\n*     |             *\n*_____|__________   *\n*********************\n");
		break;
	case 3:
		printf("\n\tHANGMAN\n*********************\n*     -------       *\n*     |     |       *\n*     |     @       *\n*     |   --|--     *\n*     |             *\n*     |             *\n*_____|__________   *\n*********************\n");
		break;
	case 4:
		printf("\n\tHANGMAN\n*********************\n*     -------       *\n*     |     |       *\n*     |     @       *\n*     |             *\n*     |             *\n*     |             *\n*_____|__________   *\n*********************\n");
		break;
	case 5:
		printf("\n\tHANGMAN\n*********************\n*     -------       *\n*     |     |       *\n*     |             *\n*     |             *\n*     |             *\n*     |             *\n*_____|__________   *\n*********************\n");
		break;
	default:
		break;
	}

}
//3. Game
int Fplaygame()
{
	//system("cls");
	srand(time(NULL));
	//Library
	char wordindex[][8] = { "love","study","car","monday","friday" };
	//variable
	int indexnumber = rand() % 5;
	int lengthofword = strlen(wordindex[indexnumber]);
	int i, score = 0, life = 5, correctguess = 0, correcttestcount = 0;
	char guess;
	char word[8] = { '*','*','*','*','*','*' };
	char guessedword = '*';

	//Interface
	while (correctguess < lengthofword && life > 0)

	{                           // alternative to 'guessed word' test
		system("cls");
		printf("\nSCORE: %d\b\b\nLife: %d\ncorrectguess : %d", score, life, correctguess);
		//display
		Fhangman(life);
		//word and guessed letter
		printf("\nGuessed letter: %c\n\n", guessedword);
		printf("Word:\t\t\t");
		for (i = 0; i<lengthofword; i++)
		{
			printf("%c", word[i]);
		}
		printf("\nEnter your guess:");
		scanf_s(" %c",&guess);     // for Microsoft Visual Studio
		//scanf("%c", &guess); // word compare
		//guess = getchar(); // error

		for (i = 0; i<lengthofword; i++)
		{
			if (guess == wordindex[indexnumber][i] /*&& guess != guessedword*/)
			{
				word[i] = guess;
				if (guess != guessedword)
					correcttestcount++;
			}
		}
		if (correcttestcount >= 1) // guess is correct
		{
			correctguess++;
			score += 10;
		}
		else {                                             // guess is flase or repeated

			if (guess == guessedword)
			{
				printf("Dont repeat !! \n");
				//system("pause");
			}
			life--;
		}
		correcttestcount = 0;
		guessedword = guess;
		//system("pause");
	}
	if (life <= 1)
	{
		system("cls");
		Fhangman(0);
		printf("\nYou loss !!\nThe answer was:%s \n", wordindex[indexnumber]);
	}
	else if (correctguess >= lengthofword)
	{
		system("cls");
		Fhangman(life);
		printf("\nYou Won!!!\nTOTAL SCORE: %d\nThe Answer was:%s\n", score, wordindex[indexnumber]);
	}
	return 0;
}
