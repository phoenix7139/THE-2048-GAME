#include <bits/stdc++.h>

using namespace std;

int grid[4][4];
int grid2[4][4];
char direction;


int rindex(int x)   //generates random indexes for initializing the grid
{
    int index;
    index=rand()%x;

return index;
}

void backup_grid()      //copies grid to grid to for undo function
{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				grid2[i][j]=grid[i][j];
}


int initialise_grid()   //makes 2 random indexes in the grid "2" and the rest "0"
{


    int i,j,a,b;

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			grid[i][j]=0;

	i=rindex(4);
	j=rindex(4);

		grid[i][j]=2;



	while(1)
    {
        a=rindex(4);
        if(a!=i)
            break;
    }
	while(1)
    {
        b=rindex(4);
        if(b!=j)
            break;
    }

        grid[a][b]=2;

}

int show_grid()  //inputs spaces to "0" and prints grid
{

    for(int i=0;i<4;i++)
				{
                cout<<"                       ";
				cout<<"\t\t     |";

					for(int j=0;j<4;j++)
					{
						if(grid[i][j])
							printf("%4d    |",grid[i][j]);
						else
							printf("%4c    |",' ');
					}

				cout<<endl<<endl;
				}
				cout<<endl<<endl;
}

int find_largest()     //finds the max tile in the grid and stores it in max
{
    int max=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(grid[i][j]>max)
				max=grid[i][j];
return max;
}

int endgame_condition()     //returns 0 if grid is filled resulting in a game over
{
	int k=1;

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(!grid[i][j])
				k=0;

		}
return k;
}

void undo()     //copying grid2 to grid to undo moves
{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				grid[i][j]=grid2[i][j];
}

int move_test()
{
	int k=0;

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(grid2[i][j]!=grid[i][j])
			{
				k=1;
				break;
			}
return k;
}

void spawn()        //to spawn random tiles after every move
{
    srand (time(NULL));

		int i,j,k;

		do
		{
		    i=rindex(4);
		    j=rindex(4);
		    k=rindex(10);

		}while(grid[i][j]);



		if(k<2)
		    grid[i][j]=4;

		else
		    grid[i][j]=2;


}

void move_tiles()       //moves the tiles into empty spaces without merging
{
switch(direction)
	{
		case 'w':
					for(int i=0;i<4;i++)
						for(int j=0;j<4;j++)
						{
							if(!grid[j][i])
							{
								for(int k=j+1;k<4;k++)
									if(grid[k][i])
									{
										grid[j][i]=grid[k][i];
										grid[k][i]=0;
										break;
									}
							}

						}break;

		case 's':
					for(int i=0;i<4;i++)
						for(int j=3;j>=0;j--)
						{
							if(!grid[j][i])
							{
								for(int k=j-1;k>=0;k--)
									if(grid[k][i])
									{
										grid[j][i]=grid[k][i];
										grid[k][i]=0;
										break;
									}
							}

						}break;
		case 'a':
					for(int i=0;i<4;i++)
						for(int j=0;j<4;j++)
						{
							if(!grid[i][j])
							{
								for(int k=j+1;k<4;k++)
									if(grid[i][k])
									{
										grid[i][j]=grid[i][k];
										grid[i][k]=0;
										break;
									}
							}

						}break;


		case 'd':
					for(int i=0;i<4;i++)
						for(int j=3;j>=0;j--)
						{
							if(!grid[i][j])
							{
								for(int k=j-1;k>=0;k--)
									if(grid[i][k])
									{
										grid[i][j]=grid[i][k];
										grid[i][k]=0;
										break;
									}
							}

						}break;

	}
}

void merge_tiles()
{

	switch(direction)
	{
		case 'w':
					for(int i=0;i<4;i++)
						for(int j=0;j<3;j++)
						{
							if(grid[j][i]==grid[j+1][i])
							{
								grid[j][i]+=grid[j+1][i];
								grid[j+1][i]=0;

							}
						}break;

		case 's':
					for(int i=0;i<4;i++)
						for(int j=3;j>0;j--)
						{
							if(grid[j][i]==grid[j-1][i])
							{
								grid[j][i]+=grid[j-1][i];
								grid[j-1][i]=0;
							}
						}break;

		case 'a':
					for(int i=0;i<4;i++)
						for(int j=0;j<3;j++)
						{
							if(grid[i][j]==grid[i][j+1])
							{
								grid[i][j]+=grid[i][j+1];
								grid[i][j+1]=0;
							}
						}break;

		case 'd':
					for(int i=0;i<4;i++)
						for(int j=3;j>0;j--)
						{
							if(grid[i][j]==grid[i][j-1])
							{
								grid[i][j]+=grid[i][j-1];
								grid[i][j-1]=0;
							}
						}break;


	}



}

void endgame_display()
{

system("cls");
cout<<"[GAME OVER]";

}

void wingame_display()
{

system("cls");
cout<<"[REACHED 2048]";


}

void starting_display()
{

cout<<"                                    ";
cout<<"THE 2048 GAME CREATED BY JYOTISHKA DASGUPTA"<<'\n'<<'\n'<<'\n';
cout<<endl;



}

void control_display()
{

cout<<endl<<endl<<endl;
char co[5][5];
co[0][0]='t';
co[0][1]='t';
co[0][2]='^';
co[0][3]='t';
co[0][4]='t';
co[1][0]='t';
co[1][1]='t';
co[1][2]='W';
co[1][3]='t';
co[1][4]='t';
co[2][0]='<';
co[2][1]='A';
co[2][2]='t';
co[2][3]='D';
co[2][4]='>';
co[3][0]='t';
co[3][1]='t';
co[3][2]='S';
co[3][3]='t';
co[3][4]='t';
co[4][0]='t';
co[4][1]='t';
co[4][2]='V';
co[4][3]='t';
co[4][4]='t';


for(int i=0;i<5;i++)
    {
        if(i==2)
            cout<<"             CONTROLS->                          ";
        else
            cout<<"                                                 ";
        for(int j=0;j<5;j++)
    {
        if(co[i][j]=='t')
            cout<<"   ";
        else
            cout<<co[i][j]<<"  ";


    }
    cout<<endl<<endl;
    }
    cout<<endl;
    cout<<"                                                PRESS U TO UNDO";
    cout<<endl<<endl<<endl;
}





int main()
{
    srand(time(NULL));      //to ensure that rand generates distinct values in each iteration

    initialise_grid();
    starting_display();
    show_grid();
    while(1)
    {
        control_display();
        cin>>direction;
        if(direction=='u')
        {
            undo();
            show_grid();
        }
        else
        {
            backup_grid();
            move_tiles();
            merge_tiles();
            move_tiles();
            int stat=move_test();
            if(stat)
            {
                spawn();
                show_grid();
            }


        }
        int m=find_largest();
        if(m==2048)
        {
            wingame_display();
            break;
        }

        int t=endgame_condition();
        if(t)
        {

            endgame_display();
            break;
        }


    }







    return 0;
}