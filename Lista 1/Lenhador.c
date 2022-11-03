# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>

int treeHeight, branches;
bool isDamaged = false;
char lumberDirection;
char commands[50];
char screen[7][11];
int layersDestroyed = 0;

enum symbols{
    lumber = 'L',
    tree = '|',
    branch = '-',
    limit = '~',
    leftDamage = '>',
    rightDamage = '<',
    left = 'E',
    right = 'D',
    change = 'T',
    cut = 'B'
};
void setLumberPosition(void);
void cutsTree(int branchRegister[2 * branches + 1]);
void breakTree(int branchRegister[]);
void drawtree(void);
void printScreen(void);
void changeSides(void);
void endGame(void);
void notifyInvalidCommand(void;);
void drawBranches(int branchRegister[]);
bool checkDangerousZones(char side, int line);
void clearBranchesArea(void);



int main(int argc, char const *argv[])
{   
    // input
    scanf("%d %d", &treeHeight, &branches);
    int branchRegister[2 * branches + 1];
    for (int column = 0; column < 11; column++)
    {
        for (int line = 0; line < 7; line++)
        {
            screen[line][column] = (char) 32;
        }
        
    }
    
    char temporaryVar;
    for (int i = 0; i < 2 * branches; i += 2){
        scanf("%*c %c %d", &temporaryVar, &branchRegister[i + 1]);
        branchRegister[i] = (int) temporaryVar;
    }
    branchRegister[2 * branches] = 0;
    scanf("%*c%c", &lumberDirection);
    scanf("%s", commands);
    printf("\n");
    // define limits
    for (int i = 0; i < 11; i++)
    {
        screen[0][i] = limit;
        screen[6][i] = limit;
    }
    drawtree();
    setLumberPosition();
    drawBranches(branchRegister);
    printScreen();
    for (int i = 0; i < 50; i++)
    {
        if (commands[i] == (char) cut)
        {
            cutsTree(branchRegister);
        }
        else if (commands[i] == (char) change)
        {   
            if (checkDangerousZones(right, 4) || checkDangerousZones(left, 4) || checkDangerousZones(right, 5) || checkDangerousZones(left, 5))
            {
                notifyInvalidCommand();
                continue;
            } else
            {
                changeSides();
            }
        }
        else
        {
            exit(EXIT_FAILURE);
        }
        
        printScreen();
    }
    

    return 0;
}

void setLumberPosition(void){
    if (lumberDirection == (char) left)
    {
        screen[4][2] = (char) lumber;
        screen[5][2] = (char) lumber;
        screen[4][8] = ' ';
        screen[5][8] = ' ';
    }
    else
    {
        screen[4][8] = (char) lumber;
        screen[5][8] = (char) lumber;
        screen[4][2] = ' ';
        screen[5][2] = ' ';
    }
}

void cutsTree(int branchRegister[2 * branches + 1]){
    if (isDamaged){
        breakTree(branchRegister);
        isDamaged = false;
    }
    else if (lumberDirection == (char) left)
    {
        screen[5][4] = (char) leftDamage;
        isDamaged = true;
    }
    else
    {
        screen[5][6] = (char) rightDamage;
        isDamaged = true;
    }
}

void breakTree(int branchRegister[]) {
    if (checkDangerousZones(lumberDirection, 3))
    {
        endGame();
    } else {
        layersDestroyed++;
        drawtree();
        drawBranches(branchRegister);
    }
}

void drawtree(void){
    int treeLayers;
    if (treeHeight - layersDestroyed >= 5)
    {
        treeLayers = 5;
    } else
    {
        treeLayers = treeHeight - layersDestroyed;
    }
    for (int line = 0; line < 5; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            if (line < treeLayers)
            {
                screen[5 - line][4 + column] = tree;
            }
            else{
                screen[5 - line][4 + column] = ' ';
            }
            
            
        }
    }
}

void printScreen(void) {
    for (int line = 0; line < 7; line++){
        for (int column = 0; column < 11; column++){
            printf("%c", screen[line][column]);
        }
    printf("\n");
    }   
}

void changeSides(void){
    lumberDirection = (char) (lumberDirection == (char) left) ? (char) right : (char) left;
    setLumberPosition();
}

void endGame(void){
    printf("**morreu**\n");
    exit(EXIT_SUCCESS);
}

void notifyInvalidCommand(void){
    printf("**beep**\n");
}

bool checkDangerousZones(char side, int line){
    // return true if there is branches on the dangerous zone.
    if (side == (char) left)
    {
        return (screen[line][2] == (char) branch) ? true : false;
    }
    else if (side == (char) right)
    {
        return (screen[line][8] == (char) branch) ? true : false;
    }   
}

void drawBranches(int branchRegister[]) {
    clearBranchesArea();
    for (int b = 0; b < 2 * branches; b += 2)
    {
        for (int screenIndex = 5; screenIndex > 0; screenIndex--)
        {
            if (branchRegister[b + 1] == screenIndex + layersDestroyed)
            {

                for (int j = 0; j < 3; j++)
                {
                    if (branchRegister[b] == left)
                    {
                        screen[6 - screenIndex][j + 1] = (char) branch;
                    }
                    else
                    {
                        screen[6 - screenIndex][j + 8] = (char) branch;
                    }
                }
            }
        }
    }
}

void clearBranchesArea(void){
    for (int line = 1; line <= 5; line++) {
        for (int column = 0; column < 3; column++)
        {
            screen[line][column + 1] = ' ';
            screen[line][column + 8] = ' ';        
        }
    }
    setLumberPosition();
}