/*****************************************
******************************************
*********Havvanur Bozömeroğlu*************
**************1306180022******************
******************************************
*****************************************/



#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h> //rand fonksiyonu için
#include <time.h> //srand fonksiyonu için
#include <string>
#include <sstream>
#include <string.h>

using namespace std;



void gameContinue();
void newGame();
void gameExit();
int randomDiceFirst();
int randomFirstDice();
int randomSecondDice();
void writeTableFile(string table[7][13]);
void readTableFile();
void XPlayerGame(string table[7][13]);
void CommandEachLevel(int diceValue, string diceValueString, string sourceSlot, string table[7][13]);
void AskCommand (int diceValue, string diceValueString, string table[7][13]);
void TargetControlX(string nowGamer, int i, int j,int diceValue, string diceValueString, string sourceSlot, string table[7][13]);
void TargetControlY(string nowGamer, int i, int j,int diceValue, string diceValueString, string sourceSlot, string table[7][13]);
bool Collection(string nowGamer, int i, int j, int diceValue, string diceValueString, string table[7][13]);
void readDiceFile();
void WriteDiceFile(string nowGamer, string diceNo1, string diceNo2, string table[7][13]);
void winPerson(string nowGamer);

/*string table[7][13] = {{"  ","A ","B ","C ","D ","E ","F ","G ","H ","I ","J ","K ","L "},
                       {"1 ","5Y","  ","  ","  ","3X","  ","5X","  ","  ","  ","  ","2Y"},
                       {"2 ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
                       {"3 ","  ","  ","  ","0X","  ","  ","  ","  ","0Y","  ","  "," "},
                       {"4 ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
                       {"5 ","5X","  ","  ","  ","3Y","  ","5Y","  ","  ","  ","  ","2X"},
                       {"  ","A ","B ","C ","D ","E ","F ","G ","H ","I ","J ","K ","L "}};
*/


int main(){
    string sdecision;

    cout << endl << endl;
    cout << "************************************************************" << endl;
    cout << "*********************WELCOME THE GAME***********************" << endl;
    cout << "************************************************************" << endl << endl << endl;
    cout << "Please decide what you want to do and enter the number." << endl;
    cout << "     1-Continue Game \n     2-New Game \n     3-Exit" << endl << endl;



    for(int i=0; i<=10; i++){
        cout << "Your decision: ";
        cin >> sdecision;

        if(sdecision == "1"){
            gameContinue();
            break;
        }else if(sdecision == "2"){
            newGame();
            break;
        }else if(sdecision == "3"){
            gameExit();
            break;
        }else cout << "Please enter a valid expression." << endl;
    }

    return 0;
}

void gameContinue(){
    system("cls");
    readTableFile();
    string table[7][13] = {{"  ","A ","B ","C ","D ","E ","F ","G ","H ","I ","J ","K ","L "},
                       {"1 ","5Y","  ","  ","  ","3X","  ","5X","  ","  ","  ","  ","2Y"},
                       {"2 ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
                       {"3 ","  ","  ","  ","0X","  ","  ","  ","  ","0Y","  ","  ","  "},
                       {"4 ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
                       {"5 ","5X","  ","  ","  ","3Y","  ","5Y","  ","  ","  ","  ","2X"},
                       {"  ","A ","B ","C ","D ","E ","F ","G ","H ","I ","J ","K ","L "}};

    ifstream readFile("Table.dat");
    char letter = ' ' ;

    for(int i = 0; i<7;  i++){
        for(int j = 0; j<13; j++){


                string temp = table[i][j];
                readFile.get(letter);
                temp[0] = letter;
                readFile.get(letter);
                temp[1] = letter;
                table[i][j] = temp;
                readFile.get(letter);
        }
        readFile.get(letter);
    }

    readFile.close();

    string str = table[3][6];
    string str1 = table[3][7];

    int firstdice =  stoi(str);
    int seconddice = stoi(str1);

   AskCommand (seconddice, str1, table);
   if(table[3][12] == "X "){
        table[3][12] = "Y ";
   }else table[3][12] = "X ";

    XPlayerGame(table);
}

void newGame(){
    system("cls");
    string table[7][13] = {{"  ","A ","B ","C ","D ","E ","F ","G ","H ","I ","J ","K ","L "},
                       {"1 ","5Y","  ","  ","  ","3X","  ","5X","  ","  ","  ","  ","2Y"},
                       {"2 ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
                       {"3 ","  ","  ","  ","0X","  ","  ","  ","  ","0Y","  ","  "," "},
                       {"4 ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
                       {"5 ","5X","  ","  ","  ","3Y","  ","5Y","  ","  ","  ","  ","2X"},
                       {"  ","A ","B ","C ","D ","E ","F ","G ","H ","I ","J ","K ","L "}};


    cout << endl;
  //  readWriteFile(table);
    if( randomDiceFirst() == 1){
        cout << "X can start the game." << endl;
        cout << "Press any key to continue." << endl;
        char continuee;
        cin >> continuee;
        system("cls");
        table[3][12] = "X ";

        XPlayerGame(table);
    }else {
        cout << "Y can start the game." << endl;
         cout << "Press any key to continue." << endl;
        char continuee;
        cin >> continuee;
        system("cls");
        table[3][12] = "Y ";
        XPlayerGame(table);
    }



}

void gameExit(){
    exit(0);
}

int randomDiceFirst(){

    int diceValueX = randomFirstDice();
    int diceValueY = randomSecondDice();
    if(diceValueX == diceValueY){
        randomDiceFirst();                                          //first or 1 or X
    }else if(diceValueX < diceValueY){                              // second or 2 or Y
        cout << "X: " << diceValueX << endl;
        cout << "Y: " << diceValueY << endl;
        ofstream writeFile("Dice.dat");
        writeFile << "X: " << diceValueX << endl;
        writeFile << "Y: " << diceValueY << endl;
        writeFile.close();
        return 2;
    }else{
        cout << "X: " << diceValueX << endl;
        cout << "Y: " << diceValueY << endl;
        ofstream writeFile("Dice.dat");
        writeFile << "X: " << diceValueX << endl;
        writeFile << "Y: " << diceValueY << endl;
        writeFile.close();
        return 1;

    }


}

void readDiceFile(){
    cout << endl;
    ifstream readFile("Dice.dat");
    string line="";
    while ( getline(readFile, line) ){
        cout << line << endl;
    }
    readFile.close();
}

void WriteDiceFile(string nowGamer, string diceNo1, string diceNo2, string table[7][13]){
    ofstream writeFile("Dice.dat", ios::out|ios::app);
    writeFile << nowGamer << "  " << diceNo1 << "  " << diceNo2 << " " << endl;
    writeFile.close();

}

void readTableFile(){
    cout << endl << endl;

    ifstream readFile("Table.dat");
    string line="";

    while ( getline(readFile, line) ){
        cout << line << endl;
    }
    readFile.close();
}

void writeTableFile(string table[7][13]){

    cout << endl << endl;

    ofstream writeFile("Table.dat");

    for(int i=0; i<7; i++){
        for(int j=0; j<13; j++){
            writeFile << table[i][j];
            writeFile <<" ";
        }
        writeFile << endl;
    }
    writeFile.close();

}

void XPlayerGame(string table[7][13]){

     int firstdice = randomFirstDice();
     int seconddice = randomSecondDice();
     string str= to_string(firstdice);
     string str1= to_string(seconddice);

     table[3][6] = str + " " ;
     table[3][7] = str1 + " ";

    writeTableFile(table);
    readTableFile();
    string continuee;
    if(table[3][12] == "X "){
        if(firstdice == seconddice){
            for(int a = 1; a<=firstdice; a++){
                AskCommand(firstdice, str1, table);
            }
        }else{
            AskCommand(firstdice,str,table);
            AskCommand(seconddice,str1,table);
            WriteDiceFile("X ", str, str1, table);
        }
        table[3][12] = "Y ";
        XPlayerGame(table);
    }else{
        if(firstdice == seconddice){
            for(int a = 1; a<=firstdice; a++){
                AskCommand(firstdice, str1, table);
            }
        }else{
            AskCommand(firstdice,str,table);
            AskCommand(seconddice,str1,table);
            WriteDiceFile("Y ", str, str1, table);
        }
        table[3][12] ="X ";
        XPlayerGame(table);
    }





}

void AskCommand (int diceValue, string diceValueString, string table[7][13]){
    cout << endl;
     cout << "If you want to quit the game, press the Q key." << endl;
     cout << "Enter source slot for Dice: " << diceValue << endl;
     string yourcommand2 = "";
     cin >> yourcommand2 ;
     if(yourcommand2 == "q" || yourcommand2 == "Q") gameExit();
     else CommandEachLevel(diceValue,diceValueString,yourcommand2, table);
}

void CommandEachLevel(int diceValue, string diceValueString, string sourceSlot, string table[7][13]){
    string tempTable[5][13] = {{" ","A ","B" ,"C" ,"D" ,"E ","F" ,"G ","H" ,"I" ,"J" ,"K" ,"L "},
                               {"1","1A","1B" ,"1C" ,"1D" ,"1E","1F","1G","1H" ,"1I" ,"1J" ,"1K" ,"1L"},
                               {"2","1a" ,"1b" ,"1c" ,"1d" ,"1e" ,"1f" ,"1g" ,"1h" ,"1i" ,"1j" ,"1k" ,"1l" },
                               {"3","5A" ,"5B" ,"5C" ,"5D" ,"5E","5F","5G","5H" ,"5I" ,"5J" ,"5K" ,"5L" },
                               {"4","5a" ,"5b" ,"5c" ,"5d" ,"5e" ,"5f" ,"5g" ,"5h" ,"5i" ,"5j" ,"5k" ,"5l"}};

    string nowGamer = table[3][12];
    int i, j, count = 0;


    if(nowGamer[0] == 'X'){
        for(j = 0; j<13; j++){
            if(sourceSlot == tempTable[1][j]){
                i = 1;
                count ++;
                TargetControlX(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table );
                break;
            }
            if(sourceSlot == tempTable[2][j]){
                i = 1;
                count ++;
                TargetControlX(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table );
                break;
            }
            if(sourceSlot == tempTable[3][j]){
                i = 5;
                count ++;
                TargetControlX(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table );
                break;
            }
            if(sourceSlot == tempTable[4][j]){
                i = 5;
                count ++;
                TargetControlX(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table );
                break;
            }
            if(sourceSlot == "3d" || sourceSlot == "3D"){
                count++;
                TargetControlX(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table);
                break;
            }
        }
        if(count == 0){
            cout << "Wrong Commad!!" << endl;
            AskCommand(diceValue, diceValueString, table);
        }
    }
        if(nowGamer[0] == 'Y'){
        for(j = 0; j<13; j++){
            if(sourceSlot == tempTable[1][j]){
                i = 1;
                count ++;
                TargetControlY(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table );
                break;
            }
            if(sourceSlot == tempTable[2][j]){
                i = 1;
                count ++;
                TargetControlY(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table );
                break;
            }
            if(sourceSlot == tempTable[3][j]){
                i = 5;
                count ++;
                TargetControlY(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table );
                break;
            }
            if(sourceSlot == tempTable[4][j]){
                i = 5;
                count ++;
                TargetControlY(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table );
                break;
            }
            if(sourceSlot == "3i" || sourceSlot == "3I"){
                count++;
                TargetControlY(nowGamer, i, j, diceValue, diceValueString, sourceSlot, table);
                break;
            }
        }
        if(count == 0){
            cout << "Wrong Commad!!" << endl;
            AskCommand(diceValue, diceValueString, table);
        }
    }


}

void TargetControlX(string nowGamer, int i, int j,int diceValue, string diceValueString, string sourceSlot, string table[7][13]){
    int temptable1[7][13] = {{0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,13,14,15,16,17,18,19,20,21,22,23,24},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,12,11,10,9,8,7,6,5,4,3,2,1},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0}};

    string kaynak = table[i][j];



    if(kaynak[1] == 'Y'){
        cout << "Wrong Command!!" << endl;
        AskCommand(diceValue,diceValueString,table);
    }else{

    string control = table[5][12];
    int deleteCount = 0;

        if(sourceSlot == "3d" || sourceSlot == "3D"){
        if(table[5][12] == "  "){
            control[0] = '1';
            control[1] = 'X';
            table[5][12] = control;
            i = 5;
            j = 12;
            deleteCount++;
        }else if(control[1] == 'X'){
            int controli = int(control[0]);
            controli++;
            control[0] = char(controli);
            table[5][12] = control;
            i = 5;
            j = 12;
            deleteCount++;
        }else{
            if(control[0] == '1'){
                string broken = table[3][9];
                int brokenDice = int(broken[0]);
                brokenDice++;
                broken[0] = char(brokenDice);
                table[3][9] = broken;
                control[0] = '1';
                control[1] = 'X';
                table[5][12] = control;
                i = 5;
                j = 12;
                deleteCount++;
            }else{
                cout << "Wrong Command!!" << endl;
                AskCommand(diceValue,diceValueString,table);
            }
        }
    }

    kaynak = table[i][j];
   int target = temptable1[i][j];
    target = target + diceValue;

    bool turn = false;
    int k, l;
    if(target > 24){
        turn = Collection(nowGamer, i, j, diceValue, diceValueString, table);
    }else{


         for( int a=0; a<7; a++){
            for( int b=0; b<13; b++){
                if(temptable1[a][b] == target) {
                    k = a;
                    l = b;
                }
            }
    }






    string hedef = table[k][l];


   if(kaynak[1] == nowGamer[0]){     //oyuna aynen devam bir hata veya başka bir olay yok

        if(hedef[1] == nowGamer[0] ){     //oyuna aynen devam bir hata veya başka bir olay yok

            int kaynakValue = int(kaynak[0]);
            kaynakValue--;
            if(char(kaynakValue) == '0'){
                table[i][j] = "  ";
            }else{
                char kaynakValuee = char(kaynakValue);
                kaynak[0] = kaynakValuee;
                table[i][j] = kaynak;
            }

            int hedefValue = int(hedef[0]);
            hedefValue ++;
            char hedefValuee = char(hedefValue);
            hedef[0] = hedefValuee;
            table[k][l] = hedef;

            if(deleteCount == 1){
                string deleteLocation = table[3][4];
                int deleteValue = int(deleteLocation[0]);
                deleteValue--;
                char deleteValuee = char(deleteValue);
                deleteLocation[0] = deleteValuee;
                table[3][4] = deleteLocation;
            }

            writeTableFile(table);
            readTableFile();


        }else if(hedef == "  " ){      //hedef slotun boş olma durumu
            int kaynakValue = int(kaynak[0]);
            kaynakValue--;
            if(char(kaynakValue) == '0'){
                table[i][j] = "  ";
            }else{
                char kaynakValuee = char(kaynakValue);
                kaynak[0] = kaynakValuee;
                table[i][j] = kaynak;
            }


            hedef[0] = '1';
            char nowGamerr = nowGamer[0];
            hedef[1] = nowGamerr;
            table[k][l] = hedef;
             if(deleteCount == 1){
                string deleteLocation = table[3][4];
                int deleteValue = int(deleteLocation[0]);
                deleteValue--;
                char deleteValuee = char(deleteValue);
                deleteLocation[0] = deleteValuee;
                table[3][4] = deleteLocation;
            }

            writeTableFile(table);
            readTableFile();



        }else {
            if(hedef[0] == '1'){      //pul kırma durumu
                int kaynakValue = int(kaynak[0]);
                kaynakValue--;
                if(char(kaynakValue) == '0'){
                    table[i][j] = "  ";
                    if(sourceSlot == "3d" || sourceSlot == "3D"){
                        string control2 = "  ";
                        control2[0] = '0';
                        control2[1] = 'X';
                        table[i][j] = control2;
                    }
                }else{
                    char kaynakValuee = char(kaynakValue);
                    kaynak[0] = kaynakValuee;
                    table[i][j] = kaynak;
                }

                hedef[0] = '1';
                char nowGamerr = nowGamer[0];
                hedef[1] = nowGamerr;
                table[k][l] = hedef;

                string broken = table[3][9];
                int brokenDice = int(broken[0]);
                brokenDice++;
                broken[0] = char(brokenDice);
                table[3][9] = broken;


                if(deleteCount == 1){
                    string deleteLocation = table[3][4];
                    int deleteValue = int(deleteLocation[0]);
                    deleteValue--;
                    char deleteValuee = char(deleteValue);
                    deleteLocation[0] = deleteValuee;
                    table[3][4] = deleteLocation;
                }

                writeTableFile(table);
                readTableFile();


            }else{                         //gidilecek slot karşı tarafın taşları ile dolu
                cout << "Wrong Command!!" << endl;
                AskCommand(diceValue,diceValueString,table);
            }
        }
    }
}
} }

void TargetControlY(string nowGamer, int i, int j,int diceValue, string diceValueString, string sourceSlot, string table[7][13]){
    int temptable1[7][13] = {{0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,12,11,10,9,8,7,6,5,4,3,2,1},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,13,14,15,16,17,18,19,20,21,22,23,24},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0}};



     string kaynak = table[i][j];


    if(kaynak[1] == 'X'){
        cout << "Wrong Command!!" << endl;
        AskCommand(diceValue,diceValueString,table);
    }else{


    string control = table[1][12];
    int deleteCount = 0;


    if(sourceSlot == "3i" || sourceSlot == "3I"){
        if(table[1][12] == "  "){
            control[0] = '1';
            control[1] = 'Y';
            table[1][12] = control;
            i = 1;
            j = 12;
            deleteCount++;
        }else if(control[1] == 'Y'){
            int controli = int(control[0]);
            controli++;
            control[0] = char(controli);
            table[1][12] = control;
            i = 1;
            j = 12;
            deleteCount++;
        }else{
            if(control[0] == '1'){
                string broken = table[3][4];
                int brokenDice = int(broken[0]);
                brokenDice++;
                broken[0] = char(brokenDice);
                table[3][4] = broken;
                control[0] = '1';
                control[1] = 'Y';
                table[1][12] = control;
                i = 1;
                j = 12;
                deleteCount++;
            }else{
                cout << "Wrong Command!!" << endl;
                AskCommand(diceValue,diceValueString,table);
            }
        }
    }



    kaynak = table[i][j];
     int target = temptable1[i][j];
    target = target + diceValue;

    bool turn = false;
    int k, l;
    if(target > 24){
        turn = Collection(nowGamer, i, j, diceValue, diceValueString, table);
    }else{


         for( int a=0; a<7; a++){
            for( int b=0; b<13; b++){
                if(temptable1[a][b] == target) {
                    k = a;
                    l = b;
                }
            }
        }



        string hedef = table[k][l];


       if(kaynak[1] == nowGamer[0]){     //oyuna aynen devam bir hata veya başka bir olay yok

            if(hedef[1] == nowGamer[0] ){     //oyuna aynen devam bir hata veya başka bir olay yok

                int kaynakValue = int(kaynak[0]);
                kaynakValue--;
                if(char(kaynakValue) == '0'){
                    table[i][j] = "  ";
                }else{
                    char kaynakValuee = char(kaynakValue);
                    kaynak[0] = kaynakValuee;
                    table[i][j] = kaynak;
                }

                int hedefValue = int(hedef[0]);
                hedefValue ++;
                char hedefValuee = char(hedefValue);
                hedef[0] = hedefValuee;
                table[k][l] = hedef;
                if(deleteCount == 1){
                    string deleteLocation = table[3][9];
                    int deleteValue = int(deleteLocation[0]);
                    deleteValue--;
                    char deleteValuee = char(deleteValue);
                    deleteLocation[0] = deleteValuee;
                    table[3][9] = deleteLocation;
                }

                writeTableFile(table);
                readTableFile();


            }else if(hedef == "  " ){      //hedef slotun boş olma durumu
                int kaynakValue = int(kaynak[0]);
                kaynakValue--;
                if(char(kaynakValue) == '0'){
                    table[i][j] = "  ";
                }else{
                    char kaynakValuee = char(kaynakValue);
                    kaynak[0] = kaynakValuee;
                    table[i][j] = kaynak;
                }

                hedef[0] = '1';
                char nowGamerr = nowGamer[0];
                hedef[1] = nowGamerr;
                table[k][l] = hedef;
                if(deleteCount == 1){
                    string deleteLocation = table[3][9];
                    int deleteValue = int(deleteLocation[0]);
                    deleteValue--;
                    char deleteValuee = char(deleteValue);
                    deleteLocation[0] = deleteValuee;
                    table[3][9] = deleteLocation;
                }

                writeTableFile(table);
                readTableFile();



            }else {
                if(hedef[0] == '1'){      //pul kırma durumu
                    int kaynakValue = int(kaynak[0]);
                    kaynakValue--;
                    if(char(kaynakValue) == '0'){
                        table[i][j] = "  ";
                        if(sourceSlot == "3i" || sourceSlot == "3I"){
                            string control2 = "  ";
                            control2[0] = '0';
                            control2[1] = 'Y';
                            table[i][j] = control2;
                        }
                    }else{
                        char kaynakValuee = char(kaynakValue);
                        kaynak[0] = kaynakValuee;
                        table[i][j] = kaynak;
                    }

                    hedef[0] = '1';
                    char nowGamerr = nowGamer[0];
                    hedef[1] = nowGamerr;
                    table[k][l] = hedef;

                    string broken = table[3][4];
                    int brokenDice = int(broken[0]);
                    brokenDice++;
                    broken[0] = char(brokenDice);
                    table[3][4] = broken;
                    if(deleteCount == 1){
                        string deleteLocation = table[3][9];
                        int deleteValue = int(deleteLocation[0]);
                        deleteValue--;
                        char deleteValuee = char(deleteValue);
                        deleteLocation[0] = deleteValuee;
                        table[3][9] = deleteLocation;
                    }

                    writeTableFile(table);
                    readTableFile();


                }else{                         //gidilecek slot karşı tarafın taşları ile dolu
                    cout << "Wrong Command!!" << endl;
                    AskCommand(diceValue,diceValueString,table);
                }
            }
        }
    }
}
}

bool Collection(string nowGamer, int i, int j, int diceValue, string diceValueString, string table[7][13]){
    int leftDown = 0, leftUp = 0, rightDown = 0, rightUp = 0;
    bool turn = false;
    for(int a = 0; a < 7; a++){
        for(int b = 0; b < 13; b++){
            string control = "  ";
            if(a == 5 && b < 7 && b > 0){
                control = table[a][b];
                if(control[1] == nowGamer[0]) leftDown++;

            }
            if(a == 5 && b > 6){
                control = table[a][b];
                if(control[1] == nowGamer[0]) rightDown++;

            }
            if(a == 1 && b < 7 && b > 0){
                control = table[a][b];
                if(control[1] == nowGamer[0]) leftUp++;

            }
            if(a == 1 && b > 6){
                control = table[a][b];
                if(control[1] == nowGamer[0]) rightUp++;

            }
        }
    }
    if(nowGamer[0] == 'X' && leftDown == 0 && rightDown == 0 && leftUp == 0){
        if(rightUp == 0){
            winPerson(nowGamer);
        }else{
            string kaynak = table[i][j];
            int kaynakValue = int(kaynak[0]);
            kaynakValue--;

            if(char(kaynakValue) == '0'){
                table[i][j] = "  ";
                turn = true;
            }else{
                char kaynakValuee = char(kaynakValue);
                kaynak[0] = kaynakValuee;
                table[i][j] = kaynak;
                turn = true;
            }
            writeTableFile(table);
            readTableFile();
        }
    }else if(nowGamer[0] == 'Y' && leftDown == 0 && rightUp == 0 && leftUp == 0){
        if(rightDown == 0){
            winPerson(nowGamer);
        }else{
            string kaynak = table[i][j];
            int kaynakValue = int(kaynak[0]);
            kaynakValue--;

            if(char(kaynakValue) == '0'){
                table[i][j] = "  ";
                turn = true;
            }else{
                char kaynakValuee = char(kaynakValue);
                kaynak[0] = kaynakValuee;
                table[i][j] = kaynak;
                turn = true;
        }
        writeTableFile(table);
        readTableFile();
    }
    }else{
                cout << "Wrong Command!!" << endl;
                AskCommand(diceValue,diceValueString,table);
            }
    return turn;
}

void winPerson(string nowGamer){
        system("cls");
        cout << endl << endl << endl << endl << endl << endl;
        cout << "-------------------------------------------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "----------- Winner " << nowGamer << "-----------------------" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "-------------------------------------------" << endl;

        ofstream writeFile("Dice.dat", ios::out|ios::app);
        writeFile << " Winner " << nowGamer << endl;
        writeFile.close();
        string exitt;
        cout << "Press any key to finish." << endl;
        cin >> exitt;
        gameExit();
}

int randomFirstDice(){

    srand(time(0));
    int diceValue = rand()%485+1;
    return diceValue%6+1;
}

int randomSecondDice(){

    srand(time(0));
    int diceValue = rand()%258+1;
    return diceValue%6+1;
}


