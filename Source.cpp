#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
typedef struct Node {
	int Number;
	char Callsign[100];
	struct Node *next;
	struct Node* prev;
} Structure;
Structure* New_List(int SIZE,int color) {
	Structure* List_start = nullptr, *list_point=NULL,*temp=nullptr,*temp2=nullptr;
	List_start = (Structure*)malloc(sizeof(Structure));
	list_point = List_start;
	list_point->next=nullptr;
    bool is_first = true;
	for (int point = 1; point < SIZE + 1; point++) {
		int Wcount = 0;
		list_point->next= (Structure*)malloc(sizeof(Structure));
		list_point = list_point->next;
		list_point->Number = point;
		list_point->next = nullptr;
		list_point->prev = temp2;
		printf("\x1B[%dmEnter the word:\033[0m",color);
		while (true) {
            if (is_first and point == 1) {
                scanf_s("%c", &list_point->Callsign[Wcount]);
                is_first = false;
            }
                
			scanf_s("%c", &list_point->Callsign[Wcount]);
			if (list_point->Callsign[Wcount] == '\n') {
				list_point->Callsign[Wcount] = '\0';
				break;
			}
			Wcount++;
		}
		if (point == 1)
			temp = list_point;
		temp2 = list_point;
		
	}
	list_point->next = temp;
	list_point = list_point->next;
	list_point->prev = temp2;
	return List_start;
}
Structure* New_List_letters(int color, int *Sizeback) {
    Structure* List_start = nullptr, * list_point = NULL, * temp = nullptr, * temp2 = nullptr;
    int SIZE, This_point=0;
    char Temp_word_array[500];
    List_start = (Structure*)malloc(sizeof(Structure));
    list_point = List_start;
    list_point->next = nullptr;
    bool is_first = true;
    printf("\x1B[%dmEnter the line:\033[0m", color);
    while (true) {
        if (is_first) {
            scanf("%c", &Temp_word_array[This_point]);
            is_first = false;
        }
        scanf("%c", &Temp_word_array[This_point]);
        if (Temp_word_array[This_point] == '\n') {
            SIZE = This_point;
            *Sizeback = SIZE+1;
            Temp_word_array[This_point] == '\0';
            break;
        }
        This_point++;
    }
    This_point = 0;
    for (int point = 1; point < SIZE+2; point++) {
        int Wcount = 0;
        list_point->next = (Structure*)malloc(sizeof(Structure));
        list_point = list_point->next;
        list_point->Number = point;
        list_point->next = nullptr;
        list_point->prev = temp2;
        list_point->Callsign[0] = Temp_word_array[This_point];
        if(list_point->Callsign[0]=='\n')
            list_point->Callsign[0] =' ';
        list_point->Callsign[1] = '\0';
        if (point == 1)
            temp = list_point;
        temp2 = list_point;
        This_point++;
    }
    list_point->next = temp;
    list_point = list_point->next;
    list_point->prev = temp2;
    return List_start;
}
void data_block(Structure* p_begin, int Num,int color) {
    Structure* p = p_begin;
    char* tud = (char*)malloc(100 * sizeof(char));
    char* tw = (char*)malloc(100 * sizeof(char));
    char* tud_2 = (char*)malloc(100 * sizeof(char));
    int total_size = 0;
    bool looped = false;
    p = p->next;
    while (p->Number!=1 || (looped==false)) {
        int size = 0, i = 0;
        //sizecount
        while (p->Callsign[i] != '\0') {
            size++;
            i++;
        }
        *(tud + total_size) = 201;
        *(tud + total_size + size + 1) = 187;
        *(tud_2 + total_size) = 200;
        *(tud_2 + total_size + size + 1) = 188;
        i = 1;
        while (i <= size) {
           *(tud + total_size + i) = 205;
           *(tud_2 + total_size + i) = 205;
            i++;
        }
        *(tud + total_size + size + 2) = ' ';
        *(tud_2 + total_size + size + 2) = ' ';
        i = 1;
        if (p->Number == Num) {
            *(tw + total_size) = '>';
            *(tw + total_size + size + 1) = '<';
            *(tw + total_size + size + 2) = ' ';
        }
        else {
            *(tw + total_size) = 186;
            *(tw + total_size + size + 1) = 186;
            *(tw + total_size + size + 2) = ' ';
        }
        while (i <= size) {
            *(tw + total_size + i) = p->Callsign[i - 1];
            i++;
        }
        total_size += size + 3;
        tud = (char*)realloc(tud, total_size * 100 * sizeof(char*));
        tud_2 = (char*)realloc(tud_2, total_size * 100 * sizeof(char*));
        tw = (char*)realloc(tw, total_size * 100 * sizeof(char*));
        if (p->Number == 1)
            looped = true;
        p = p->next;
    }
    *(tw + total_size) = '\0';
    *(tud + total_size) = '\0';
    *(tud_2 + total_size) = '\0';
    printf("\x1B[%dm%s\n%s\n%s\033[0m",color, tud, tw, tud_2);
    printf("\n\x1B[%dmThe pointer is pointed on element %d.\033[0m\n",color, Num);
    free(tud);
    free(tud_2);
    free(tw);
}
int change_color(int colour) {
    printf("\x1B[%dm*-----List of colours---------------*\033[0m\n", colour);
    printf("\x1B[%dm|         1.GOLD       | GDI        |\033[0m\n", colour);
    printf("\x1B[%dm|         2.BRIGHT RED | NOD        |\033[0m\n", colour);
    printf("\x1B[%dm|         3.BLUE       | CABAL      |\033[0m\n", colour);
    printf("\x1B[%dm|         4.DARK BLUE  | ALLIES     |\033[0m\n", colour);
    printf("\x1B[%dm|         5.RED        | SOVIET     |\033[0m\n", colour);
    printf("\x1B[%dm|         6.PURPLE     | YURI       |\033[0m\n", colour);
    printf("\x1B[%dm|         7.CYAN       | UN         |\033[0m\n", colour);
    printf("\x1B[%dm|         8.YELLOW     | EMPIRE     |\033[0m\n", colour);
    printf("\x1B[%dm|         9.WHITE      | CIVILIAN   |\033[0m\n", colour);
    printf("\x1B[%dm*-----------------------------------*\033[0m\n", colour);
    int input;
    printf("\x1B[%dmSelect the colour:\033[0m", colour);
    scanf("%d", &input);
    switch (input) {
    case 1:
        return 93;
    case 2:
        return 91;
    case 3:
        return 36;
    case 4:
        return 94;
    case 5:
        return 31;
    case 6:
        return 95;
    case 7:
        return 96;
    case 8:
        return 33;
    case 9:
        return 97;
    default:
        return 37;
    }
}
int Change_point(int Color, int Now_point, int SIZE) {
    int input;
    printf("\x1B[%dm*----------Change point---------*\033[0m\n", Color);
    printf("\x1B[%dm|  1.Shift pointer forward to 1 |\033[0m\n", Color);
    printf("\x1B[%dm|  2.Shift pointer backward to 1|\033[0m\n", Color);
    printf("\x1B[%dm|  3.Enter your position        |\033[0m\n", Color);
    printf("\x1B[%dm|  4.Shift pointer to the start |\033[0m\n", Color);
    printf("\x1B[%dm|  5.Shift pointer to the end   |\033[0m\n", Color);
    printf("\x1B[%dm|  6.Leave it as it is          |\033[0m\n", Color);
    printf("\x1B[%dm*-------------------------------*\033[0m\n", Color);
    printf("\x1B[%dmSelect the menu item:\033[0m", Color);
    scanf("%d", &input);
    switch (input) {
    case 1:
        Now_point++;
        if (Now_point>SIZE) {
            Now_point = 1;
        }
      
        printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
        printf("\x1B[%dm|New point is established.|\033[0m\n", Color);
        printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
        return Now_point;
    case 2:
        Now_point--;
        if (Now_point <1) {
            Now_point = SIZE;
        }
        printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
        printf("\x1B[%dm|New point is established.|\033[0m\n", Color);
        printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
        return Now_point;
    case 3:
        printf("\x1B[%dmEnter your position:\033[0m", Color);
        scanf("%d", &input);
        if (input<1 or input>SIZE) {
            printf("\x1B[%dm*---------Error--------*\033[0m\n", Color);
            printf("\x1B[%dm|Invalid list position!|\033[0m\n", Color);
            printf("\x1B[%dm*----------------------*\033[0m\n", Color);
            return Now_point;
        }
        else {
            printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
            printf("\x1B[%dm|New point is established.|\033[0m\n", Color);
            printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
            Now_point = input;
            return Now_point;
        }
    case 4:
        return 1;
    case 5:
        return SIZE;
    case 6:
        printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
        printf("\x1B[%dm|  Operation is canceled. |\033[0m\n", Color);
        printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
        return Now_point;
    default:
        printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
        printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
        printf("\x1B[%dm*------------------*\033[0m\n", Color);
        return Now_point;
    }
    
}
void reveal_the_element_or_elements(Structure *List_start,int Position,int Color) {
    Structure* PosInList = List_start;
    int input;
    bool loop = false;
    PosInList = PosInList->next;
    printf("\x1B[%dm*--------Show the list-------*\033[0m\n", Color);
    printf("\x1B[%dm|     1.Show all elements    |\033[0m\n", Color);
    printf("\x1B[%dm|     2.Show selected element|\033[0m\n", Color);
    printf("\x1B[%dm|     3.Cancel the operation |\033[0m\n", Color);
    printf("\x1B[%dm*----------------------------*\033[0m\n", Color);
    printf("\x1B[%dmSelect the menu item:\033[0m", Color);
    scanf("%d", &input);
    switch (input) {
    case 1:
        printf("\x1B[%dm*-----Forward or reverse?----*\033[0m\n", Color);
        printf("\x1B[%dm|     1.Forward              |\033[0m\n", Color);
        printf("\x1B[%dm|     2.Reverse              |\033[0m\n", Color);
        printf("\x1B[%dm|     3.Cancel the operation |\033[0m\n", Color);
        printf("\x1B[%dm*----------------------------*\033[0m\n", Color);
        printf("\x1B[%dmSelect the menu item:\033[0m", Color);
        scanf("%d", &input);
        switch (input) {
        case 1:

            while (true) {
                if (PosInList->Number == Position)
                    break;
                PosInList = PosInList->prev;
            }
            printf("\x1B[%dm/----------------------------/\033[0m\n", Color);
            while (true) {
                if (PosInList->Number == Position and loop)
                    break;
                printf("\x1B[%dm%s\033[0m\n", Color, PosInList->Callsign);
                if (!loop) 
                    loop = true;
                PosInList = PosInList->next;
            }
            printf("\x1B[%dm/----------------------------/\033[0m\n", Color);
            break;
        case 2:
            while (true) {
                if (PosInList->Number == Position)
                    break;
                PosInList = PosInList->prev;
            }
            printf("\x1B[%dm/----------------------------/\033[0m\n", Color);
            while (true) {
                if (PosInList->Number == Position and loop)
                    break;
                printf("\x1B[%dm%s\033[0m\n", Color, PosInList->Callsign);
                if (!loop)
                    loop = true;
                PosInList = PosInList->prev;
            }
            printf("\x1B[%dm/----------------------------/\033[0m\n", Color);
            break;
        case 3:
            break;
        default:
            printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
            printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
            printf("\x1B[%dm*------------------*\033[0m\n", Color);
            break;
        }
        break;
    case 2:
        printf("\x1B[%dm/----------------------------/\033[0m\n", Color);
        while (true) {
            if (PosInList->Number == Position) {
                printf("\x1B[%dm%s\033[0m\n", Color,PosInList->Callsign);
                break;
            }
            PosInList = PosInList->next;
        }
        printf("\x1B[%dm/----------------------------/\033[0m\n", Color);
        break;
    case 3:
        break;
    default:
        printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
        printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
        printf("\x1B[%dm*------------------*\033[0m\n", Color);
        break;
    }
}
void delete_list(Structure* p_begin,int SIZE)
{
    Structure* p = p_begin;
    int count = 0;
    while (count<=SIZE) {
        Structure* tmp;
        tmp = p;
        p = p->next;
        free(tmp);
        count++;
    }
}
bool main_task(Structure* List_start,int Color,int SIZE) {
    Structure* p = List_start;
    char* tud = (char*)malloc(100 * sizeof(char));
    char* tw = (char*)malloc(100 * sizeof(char));
    char* tud_2 = (char*)malloc(100 * sizeof(char));
    int total_size = 0;
   
    bool looped = false, print_it = false, is_finded=false;
    p = p->next;
    while (p->Number != 1 || (looped == false)) {
        int size = 0, i = 0;
        //sizecount
        while (p->Callsign[i] != '\0') {
            if (p->Callsign[i] == p->Callsign[i + 1]) {
                print_it = true;
                is_finded = true;
            }
            i++;
        }
        i = 0;
        if (print_it) {
           
            while (p->Callsign[i] != '\0') {
                size++;
                i++;
            }
            *(tud + total_size) = 201;
            *(tud + total_size + size + 1) = 187;
            *(tud_2 + total_size) = 200;
            *(tud_2 + total_size + size + 1) = 188;
            i = 1;
            while (i <= size) {
                *(tud + total_size + i) = 205;
                *(tud_2 + total_size + i) = 205;
                i++;
            }
            *(tud + total_size + size + 2) = ' ';
            *(tud_2 + total_size + size + 2) = ' ';
            i = 1;
            *(tw + total_size) = 186;
            *(tw + total_size + size + 1) = 186;
            *(tw + total_size + size + 2) = ' ';
            while (i <= size) {
                *(tw + total_size + i) = p->Callsign[i - 1];
                i++;
            }
            total_size += size + 3;
            tud = (char*)realloc(tud, total_size * 100 * sizeof(char*));
            tud_2 = (char*)realloc(tud_2, total_size * 100 * sizeof(char*));
            tw = (char*)realloc(tw, total_size * 100 * sizeof(char*));
        }
        if (p->Number == 1)
            looped = true;
        p = p->next;
        print_it = false;
    }
    *(tw + total_size) = '\0';
    *(tud + total_size) = '\0';
    *(tud_2 + total_size) = '\0';
    printf("\x1B[%dm%s\n%s\n%s\033[0m\n", Color, tud, tw, tud_2);
    
    free(tud);
    free(tud_2);
    free(tw);
    return is_finded;
}
void Record_to_file(Structure* List_start, int Color, int Size) {
    Structure* PosInList = List_start;
    char Filename[35];
    int count = 0;
    printf("\x1B[%dmEnter the filename:\033[0m", Color);
    scanf("%s", &Filename, 35);
    FILE* Psi = fopen(Filename, "w");
    if (Psi) {
        PosInList = PosInList->next;
        while (count < Size) {
            fprintf(Psi, "%s", PosInList->Callsign);
            fprintf(Psi, "%c",' ');
            PosInList = PosInList->next;
            count++;
        }
        fprintf(Psi, "%c", "\0");
        fprintf(Psi, "%c", EOF);
        printf("\x1B[%dm*-------------Message-----------*\033[0m\n", Color);
        printf("\x1B[%dm| Data has been recorded to %s. |\033[0m\n", Color, Filename);
        printf("\x1B[%dm*-------------------------------*\033[0m\n", Color);
        fclose(Psi);
    }
    else {
        printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
        printf("\x1B[%dm|Invalid file name!|\033[0m\n", Color);
        printf("\x1B[%dm*------------------*\033[0m\n", Color);
    }
}
Structure* Read_list_from_file(int Color,int*S) {
    Structure* L_begin = NULL;
    Structure* L = NULL,*temp_start=NULL,*temp=NULL;
    int count = 0, Size;
    char filename[35],let, * Temp = nullptr;
    printf("\x1B[%dmEnter the filename:\033[0m", Color);
    scanf("%s", &filename, 35);
    FILE* Alpha = fopen(filename, "r");
    if (!Alpha) {
        printf("\x1B[%dm*-------Error-------*\033[0m\n", Color);
        printf("\x1B[%dm| Invalid filename! |\033[0m\n", Color);
        printf("\x1B[%dm*-------------------*\033[0m\n", Color);
        return NULL;
    
    }
    else {
        while ((let = getc(Alpha)) != EOF) {
            count++;
        }
        Size = count;
        Temp = (char*)malloc(Size * sizeof(char));
        count = 0;
        fclose(Alpha);
        FILE* Alpha = fopen(filename, "r");
        Size = 0;
        while ((let = getc(Alpha)) != EOF) {
            *(Temp + count) = let;
            if (let == ' ')
                Size++;
               
            
            count++;
        }
        L_begin = (Structure*)malloc(sizeof(Structure));
        L = L_begin;
        L->next = NULL;
        L->prev = NULL;
        count = 0;
        for (int count_1 = 1; count_1 <= Size; count_1++) {
            int count_2 = 0;
            L->next = (Structure*)malloc(sizeof(Structure));
            L = L->next;
            L->Number = count_1;
            L->prev = temp;
            L->next = NULL;
            
            while (true) {
                L->Callsign[count_2] = *(Temp + count);
                if (*(Temp + count) == ' ' or *(Temp + count) == '\0') {
                    L->Callsign[count_2] = '\0';
                    count++;
                    break;
                }
                count_2++;
                count++;
            }
            if (count_1 == 1)
                temp_start = L;
            temp = L;
            *S = count_1;
            *(Temp + count) == '\0';
        }
        L->next = temp_start;
        L = L->next;
        L->prev = temp;
    }
    return L_begin;
}
bool pass_find(Structure* p,int size, int Color) {
    bool write = false, isd=false;
    char Prew;
    Structure* temp = p;
    p = p->next;
    while (size>0) {
        if (p->Callsign[0] != ' ' && p->next != nullptr) {
            Prew = p->Callsign[0];
            p = p->next;
            if (Prew == p->Callsign[0] and !write) {
                temp = temp->next;
                while (true) {
                    if (temp->Callsign[0] == ' ') {
                        printf("\n");
                        break;
                    }
                    printf("\x1B[%dm%c\033[0m",Color, temp->Callsign[0]);
                    isd = true;
                    if (temp->next != NULL)
                        temp = temp->next;
                    else
                        break;
                }
                write = true;
            }
        }
        else {
            temp = p;
            p = p->next;
            write = false;
        }
        size--;
    }
    return isd;
}
Structure* swap(Structure* p, int point_1, int point_2, int SIZE) {
    Structure* this_point = p->next, * temp_1 = NULL, * temp_2 = NULL;
    int bufer;
    char bufer_2[400];
    if (point_1 > point_2) {
        bufer = point_1;
        point_1 = point_2;
        point_2 = bufer;
    }
    if (point_1 == point_2)
        return p;
    for (int i = 1; i <= SIZE; i++) {
        if (i == point_1)
            temp_1 = this_point;
        if (i == point_2)
            temp_2 = this_point;
        this_point = this_point->next;
    }
    int temp = 0;
    while (true) {
        bufer_2[temp] = temp_1->Callsign[temp];
        if (bufer_2[temp] == '\0')
            break;
        temp++;
    }
    temp = 0;
    while (true) {
        temp_1->Callsign[temp] = temp_2->Callsign[temp];
        if (temp_1->Callsign[temp] == '\0')
            break;
        temp++;
    }
    temp = 0;
    while (true) {
        temp_2->Callsign[temp] = bufer_2[temp];
        if (temp_2->Callsign[temp] == '\0')
            break;
        temp++;
    }
    return p;
}
Structure* Edit_element(Structure* L, int position, int SIZE, int Color) {
    Structure* L_point = L;
    bool is_first = true;
    int Wcount=0;
    while (L_point->Number != position) {
        L_point = L_point->next;
    }
    printf("\x1B[%dmEnter the word:\033[0m", Color);
    while (true) {
        if (is_first ) {
            scanf_s("%c", &L_point->Callsign[Wcount]);
            is_first = false;
        }

        scanf_s("%c", &L_point->Callsign[Wcount]);
        if (L_point->Callsign[Wcount] == '\n') {
            L_point->Callsign[Wcount] = '\0';
            break;
        }
        Wcount++;
    }
    return L;
}
Structure* New_element(Structure* L, int position, int SIZE, int Color) {
    Structure* L_point = L, * temp, *MCV=L;
    while (L_point->Number != position) {
        L_point = L_point->next;
    }
    temp = (Structure*)malloc(sizeof(Structure));
    temp->prev = L_point->prev;
    temp->next = L_point;
    L_point->prev = temp;
    L_point = temp->prev;
    L_point->next = temp;
    int Wcount = 0;
    bool is_first = true;
    printf("\x1B[%dmEnter the word:\033[0m", Color);
    while (true) {
        if (is_first==true) {
            scanf_s("%c", &temp->Callsign[Wcount]);
            is_first = false;
        }

        scanf_s("%c", &temp->Callsign[Wcount]);
        if (temp->Callsign[Wcount] == '\n') {
            temp->Callsign[Wcount] = '\0';
            break;
        }
        Wcount++;
    }
    if (position == 1) {
        L->next = temp;
    }
    return MCV;
}
Structure* renumbering(Structure* L, int SIZE) {
    Structure *L_point = L;
    L_point = L_point->next;
    for (int i = 1; i <= SIZE; i++) {
        L_point->Number = i;
        L_point = L_point->next;
   }
    return L;
}
Structure* remove_element(Structure* L, int position, int SIZE, int Color) {
    Structure* L_point = L, * temp,*temp_2, * MCV = L;
 
    while (L_point->Number != position) {
        L_point = L_point->next;
    }
    temp = L_point;
    temp_2 = L_point->prev;
    L_point = L_point->next;
    temp_2->next = L_point;
    L_point->prev = temp_2;
    free(temp);
    if (position == 1) {
        L->next = L_point;
    }
    return MCV;
}

void Record_to_file_2(Structure* List_start, int Color, int Size) {
    Structure* PosInList = List_start;
    char Filename[35];
    int count = 0;
    printf("\x1B[%dmEnter the filename:\033[0m", Color);
    scanf("%s", &Filename, 35);
    FILE* Psi = fopen(Filename, "w");
    if (Psi) {
        PosInList = PosInList->next;
        while (count < Size-1) {
            fprintf(Psi, "%s", PosInList->Callsign);
            PosInList = PosInList->next;
            count++;
        }
        fprintf(Psi, "%s", " ");
        fprintf(Psi, "%c", "\0");
        fprintf(Psi, "%c", EOF);
        printf("\x1B[%dm*-------------Message-----------*\033[0m\n", Color);
        printf("\x1B[%dm| Data has been recorded to %s. |\033[0m\n", Color, Filename);
        printf("\x1B[%dm*-------------------------------*\033[0m\n", Color);
        fclose(Psi);
    }
    else {
        printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
        printf("\x1B[%dm|Invalid file name!|\033[0m\n", Color);
        printf("\x1B[%dm*------------------*\033[0m\n", Color);
    }
}

void Format1(Structure* L, int SIZE) {
    Structure* p = L;
    int total_size = 0;
    FILE* TEMP = fopen("TEMP.txt", "w");
    bool looped = false, print_it = false, is_finded = false;
    p = p->next;
    while (p->Number != 1 || (looped == false)) {
        int size = 0, i = 0;
        //sizecount
        while (p->Callsign[i] != '\0') {
            if (p->Callsign[i] == p->Callsign[i + 1]) {
                print_it = true;
            }
            i++;
        }
        if (print_it) {
            fprintf(TEMP, "%s", p->Callsign);
            fprintf(TEMP, "%c",' ');
        }


        if (p->Number == 1)
            looped = true;
        p = p->next;
        print_it = false;
    }
    fprintf(TEMP, "%c", "\0");
    fprintf(TEMP, "%c", EOF);
    fclose(TEMP);
    delete_list(L, SIZE);
    TEMP = fopen("TEMP.txt", "r");
}
   
Structure* New_element_TO_END(Structure* L, int SIZE, int Color) {
    Structure* L_point = L, * temp,*TS;
    L_point = L_point->next;
    temp = L_point;
    L_point = L_point->prev;
    TS = (Structure*)malloc(sizeof(Structure));
    TS->next = temp;
    TS->prev = L_point;
    L_point->next = TS;
    temp->prev = TS;
    int Wcount = 0;
    bool is_first = true;
    printf("\x1B[%dmEnter the word:\033[0m", Color);
    while (true) {
        if (is_first == true) {
            scanf_s("%c", &TS->Callsign[Wcount]);
            is_first = false;
        }

        scanf_s("%c", &TS->Callsign[Wcount]);
        if (TS->Callsign[Wcount] == '\n') {
            TS->Callsign[Wcount] = '\0';
            break;
        }
        Wcount++;
    }
    return L;
}
Structure* RTF(int* S) {
    Structure* L_begin = NULL;
    Structure* L = NULL, * temp_start = NULL, * temp = NULL;
    int count = 0, Size;
    char let, * Temp = nullptr;
    FILE* Alpha = fopen("TEMP.txt", "r");
    
        while ((let = getc(Alpha)) != EOF) {
            count++;
        }
        Size = count;
        Temp = (char*)malloc(Size * sizeof(char));
        count = 0;
        fclose(Alpha);
        Alpha = fopen("TEMP.txt", "r");
        Size = 0;
        while ((let = getc(Alpha)) != EOF) {
            *(Temp + count) = let;
            if (let == ' ')
                Size++;


            count++;
        }
        L_begin = (Structure*)malloc(sizeof(Structure));
        L = L_begin;
        L->next = NULL;
        L->prev = NULL;
        count = 0;
        for (int count_1 = 1; count_1 <= Size; count_1++) {
            int count_2 = 0;
            L->next = (Structure*)malloc(sizeof(Structure));
            L = L->next;
            L->Number = count_1;
            L->prev = temp;
            L->next = NULL;

            while (true) {
                L->Callsign[count_2] = *(Temp + count);
                if (*(Temp + count) == ' ' or *(Temp + count) == '\0') {
                    L->Callsign[count_2] = '\0';
                    count++;
                    break;
                }
                count_2++;
                count++;
            }
            if (count_1 == 1)
                temp_start = L;
            temp = L;
            *S = count_1;
            *(Temp + count) == '\0';
        }
        L->next = temp_start;
        L = L->next;
        L->prev = temp;
        remove("TEMP.txt");
    return L_begin;
}


Structure* Read_gadost(int Color, int* S) {
    Structure* L_begin = NULL;
    Structure* L = NULL, * temp_start = NULL, * temp = NULL;
    int count = 0, Size;
    char filename[35], let, * Temp = nullptr;
    printf("\x1B[%dmEnter the filename:\033[0m", Color);
    scanf("%s", &filename, 35);
    FILE* Alpha = fopen(filename, "r");
    if (!Alpha) {
        printf("\x1B[%dm*-------Error-------*\033[0m\n", Color);
        printf("\x1B[%dm| Invalid filename! |\033[0m\n", Color);
        printf("\x1B[%dm*-------------------*\033[0m\n", Color);
        return NULL;
        
    }
    else {
        while ((let = getc(Alpha)) != EOF) {
            count++;
        }
        Size = count;
        Temp = (char*)malloc(Size * sizeof(char));
        count = 0;
        fclose(Alpha);
        FILE* Alpha = fopen(filename, "r");
        Size = 0;
        while ((let = getc(Alpha)) != EOF) {
            *(Temp + count) = let;
            Size++;
            count++;
        }
        L_begin = (Structure*)malloc(sizeof(Structure));
        L = L_begin;
        L->next = NULL;
        L->prev = NULL;
        count = 0;
        for (int count_1 = 1; count_1 <= Size-1; count_1++) {
            L->next = (Structure*)malloc(sizeof(Structure));
            L = L->next;
            L->Number = count_1;
            L->prev = temp;
            L->next = NULL;
            L->Callsign[0] = *(Temp + count);
            L->Callsign[1] = '\0';
            count++;
            if (count_1 == 1)
                temp_start = L;
            temp = L;
            *S = count_1;
            *(Temp + count) == '\0';
        }
        L->next = temp_start;
        L = L->next;
        L->prev = temp;
    }
    return L_begin;
}

void Format2(Structure* p, int size) {
    bool write = false;
    char Prew;
    Structure* temp = p;
    FILE* Temp = fopen("TEMP.txt", "w");
    p = p->next;
    while (size > 0) {
        if (p->Callsign[0] != ' ' && p->next != nullptr) {
            Prew = p->Callsign[0];
            p = p->next;
            if (Prew == p->Callsign[0] and !write) {
                temp = temp->next;
                while (true) {
                    if (temp->Callsign[0] == ' ') {
                        fprintf(Temp, "%c", temp->Callsign[0]);
                        break;
                    }
                    fprintf(Temp, "%c", temp->Callsign[0]);
                    if (temp->next != NULL)
                        temp = temp->next;
                    else
                        break;
                }
                write = true;
            }
        }
        else {
            temp = p;
            p = p->next;
            write = false;
        }
        size--;
    }
    fprintf(Temp, "%s", " ");
    fprintf(Temp, "%c", "\0");
    fprintf(Temp, "%c", EOF);
    fclose(Temp);
    delete_list(p, size);
}

Structure* RTF2(int* S) {
    Structure* L_begin = NULL;
    Structure* L = NULL, * temp_start = NULL, * temp = NULL;
    int count = 0, Size;
    char let, * Temp = nullptr;
    FILE* Alpha = fopen("TEMP.txt", "r");
    while ((let = getc(Alpha)) != EOF) {
        count++;
    }
    Size = count;
    Temp = (char*)malloc(Size * sizeof(char));
    count = 0;
    fclose(Alpha);
    Alpha = fopen("TEMP.txt", "r");
    Size = 0;
    while ((let = getc(Alpha)) != EOF) {
        *(Temp + count) = let;
        Size++;
        count++;
    }
    L_begin = (Structure*)malloc(sizeof(Structure));
    L = L_begin;
    L->next = NULL;
    L->prev = NULL;
    count = 0;
    for (int count_1 = 1; count_1 <= Size - 2; count_1++) {
        L->next = (Structure*)malloc(sizeof(Structure));
        L = L->next;
        L->Number = count_1;
        L->prev = temp;
        L->next = NULL;
        L->Callsign[0] = *(Temp + count);
        L->Callsign[1] = '\0';
        count++;
        if (count_1 == 1)
            temp_start = L;
        temp = L;
        *S = count_1;
        *(Temp + count) == '\0';
    }
    L->next = temp_start;
    L = L->next;
    L->prev = temp;
    remove("TEMP.txt");
    return L_begin;
}




int main() {
	int SIZE, Now_point = 1, Color=37;
	Structure* MCV = NULL;
    bool is_one_let = false;
	while (true) {
        int col = Color;
		char input;
        printf("\x1B[%dm*-----------------------------------MENU--------------------------------------*\033[0m\n",Color);
        printf("\x1B[%dm|                          1.Create the list                                  |\033[0m\n", Color);
        if (MCV) {
            printf("\x1B[%dm|                          2.Show the element                                 |\033[0m\n", Color);
            printf("\x1B[%dm|                          3.Change the position                              |\033[0m\n", Color);
            printf("\x1B[%dm|                          4.Find a words with two consecutive letters in list|\033[0m\n", Color);
            printf("\x1B[%dm|                          5.Record list to file                              |\033[0m\n", Color);
            printf("\x1B[%dm|                          6.Clear the list                                   |\033[0m\n", Color);
        }
        printf("\x1B[%dm|                          7.Change the color of menu                         |\033[0m\n", Color);
        printf("\x1B[%dm|                          8.Read list from file                              |\033[0m\n", Color);
        if(MCV)
            printf("\x1B[%dm|                          9.Edit the list                                    |\033[0m\n", Color);
        printf("\x1B[%dm*-----------------------------------------------------------------------------*\033[0m\n", Color);
        printf("\x1B[%dmSelect the item:\033[0m", Color);
        scanf("%s", &input);
        switch (input) {
        case'1':
            printf("\x1B[%dm*---Select the list type---*\033[0m\n", Color);
            printf("\x1B[%dm|   1.One node-one word    |\033[0m\n", Color);
            printf("\x1B[%dm|   2.One node-one letter  |\033[0m\n", Color);
            printf("\x1B[%dm|   3.Cancel the operation |\033[0m\n", Color);
            printf("\x1B[%dm*--------------------------*\033[0m\n", Color);
            printf("\x1B[%dmSelect the menu item:\033[0m", Color);
            scanf("%s", &input);
            switch (input) {
            case '1':
                printf("\x1B[%dmEnter the size of list:\033[0m", Color);
                scanf("%d", &SIZE);
                if (SIZE > 0) {
                    MCV = New_List(SIZE, Color);
                    printf("\x1B[%dm*----------Message-------*\033[0m\n", Color);
                    printf("\x1B[%dm|New list is established.|\033[0m\n", Color);
                    printf("\x1B[%dm*------------------------*\033[0m\n", Color);
                    is_one_let = false;
                }
                else {
                    printf("\x1B[%dm*-------Error-----*\033[0m\n", Color);
                    printf("\x1B[%dm| Invalid number! |\033[0m\n", Color);
                    printf("\x1B[%dm*-----------------*\033[0m\n", Color);
                }
                break;
            case'2':
                    MCV = New_List_letters(Color, &SIZE);
                    printf("\x1B[%dm*----------Message-------*\033[0m\n", Color);
                    printf("\x1B[%dm|New list is established.|\033[0m\n", Color);
                    printf("\x1B[%dm*------------------------*\033[0m\n", Color);
                    is_one_let = true;
                break;
            case '3':
                printf("\x1B[%dm*----------Message-------*\033[0m\n", Color);
                printf("\x1B[%dm| Operation is canceled. |\033[0m\n", Color);
                printf("\x1B[%dm*------------------------*\033[0m\n", Color);
                break;
            default:
                printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                printf("\x1B[%dm*------------------*\033[0m\n", Color);
                break;
            }
            
           
            break;
        case '2':
            if (MCV) {
                reveal_the_element_or_elements(MCV, Now_point, Color);
            }
            else {
                printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                printf("\x1B[%dm*------------------*\033[0m\n", Color);
            }
            break;
        case '3':
            if(MCV)
                Now_point = Change_point(Color, Now_point, SIZE);
            else {
                printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                printf("\x1B[%dm*------------------*\033[0m\n", Color);
            }
            break;
        case '4':
            if (MCV) {
                if (is_one_let) {
                    bool temp = false;
                    printf("\x1B[%dm=====================\033[0m\n", Color);
                   temp=pass_find(MCV, SIZE, Color);
                    printf("\x1B[%dm=====================\033[0m\n", Color);
                    if (temp) {
                        Format2(MCV, SIZE);
                        MCV = RTF2(&SIZE);
                        Now_point = 1;
                    }
                }
                else {
                    
                    if (main_task(MCV, Color, SIZE)) {
                        Format1(MCV, SIZE);
                        MCV = RTF(&SIZE);
                        Now_point = 1;
                    }
                    else {
                        printf("\x1B[%dm*------------------Message-----------------------*\033[0m\n", Color);
                        printf("\x1B[%dm| No words with two consecutive letters in list. |\033[0m\n", Color);
                        printf("\x1B[%dm*------------------------------------------------*\033[0m\n", Color);
                    }
                }
            }
            else {
                printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                printf("\x1B[%dm*------------------*\033[0m\n", Color);
            }
            break;
        case '5':
            if(MCV)
                if(!is_one_let)
                Record_to_file(MCV, Color, SIZE);
                else {
                    Record_to_file_2(MCV, Color, SIZE);
                    is_one_let = true;
                }
            else {
                printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                printf("\x1B[%dm*------------------*\033[0m\n", Color);
            }
            break;
        case '6':
            if (MCV) {
                delete_list(MCV,SIZE);
                printf("\x1B[%dm*-------Message----*\033[0m\n", Color);
                printf("\x1B[%dm| List is removed. |\033[0m\n", Color);
                printf("\x1B[%dm*------------------*\033[0m\n", Color);
                is_one_let = false;
                MCV = NULL;
            }
            else {
            printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
            printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
            printf("\x1B[%dm*------------------*\033[0m\n", Color);
            }
            break;
        case '7':
            Color = change_color(Color);
            if (col != Color) {
                printf("\x1B[%dm*-------Message----*\033[0m\n", Color);
                printf("\x1B[%dm|Colour is changed.|\033[0m\n", Color);
                printf("\x1B[%dm*------------------*\033[0m\n", Color);
                
            }
                
            break;
        case '8':
            printf("\x1B[%dm*---Select the list type---*\033[0m\n", Color);
            printf("\x1B[%dm|   1.One node-one word    |\033[0m\n", Color);
            printf("\x1B[%dm|   2.One node-one letter  |\033[0m\n", Color);
            printf("\x1B[%dm|   3.Cancel the operation |\033[0m\n", Color);
            printf("\x1B[%dm*--------------------------*\033[0m\n", Color);
            printf("\x1B[%dmSelect the menu item:\033[0m", Color);
            scanf("%s", &input);
            switch (input) {
            case '1':
                MCV = Read_list_from_file(Color, &SIZE);
                is_one_let = false;
                break;
            case '2':
                MCV = Read_gadost(Color, &SIZE);
                is_one_let = true;
                break;
            case '3':
                printf("\x1B[%dm*----------Message-------*\033[0m\n", Color);
                printf("\x1B[%dm| Operation is canceled. |\033[0m\n", Color);
                printf("\x1B[%dm*------------------------*\033[0m\n", Color);
                break;
            default:
                printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                printf("\x1B[%dm*------------------*\033[0m\n", Color);

                break;
            }
              
            if (MCV) {
                printf("\x1B[%dm*----------Message-------*\033[0m\n", Color);
                printf("\x1B[%dm|New list is established.|\033[0m\n", Color);
                printf("\x1B[%dm*------------------------*\033[0m\n", Color);
            }
            break;
        case '9':
            int el;
            printf("\x1B[%dm*-----What do you want to change in list?-----*\033[0m\n", Color);
            printf("\x1B[%dm|               1.Swap elements               |\033[0m\n", Color);
            printf("\x1B[%dm|               2.Add new element             |\033[0m\n", Color);
            printf("\x1B[%dm|               3.Remove element              |\033[0m\n", Color);
            printf("\x1B[%dm|               4.Redact any element          |\033[0m\n", Color);
            printf("\x1B[%dm|               5.Nothing                     |\033[0m\n", Color);
            printf("\x1B[%dm*---------------------------------------------*\033[0m\n", Color);
            printf("\x1B[%dmSelect the menu item:\033[0m", Color);
            scanf("%s", &input);
            switch (input) {
            case'1':
                int x, y;
                printf("\x1B[%dmEnter the point 1:\033[0m", Color);
                scanf("%d", &x);
                printf("\x1B[%dmEnter the point 2:\033[0m", Color);
                scanf("%d", &y);
                if (x > 0 and x <= SIZE and y > 0 and y <= SIZE) {
                    MCV = swap(MCV, x, y, SIZE);
                    printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
                    printf("\x1B[%dm| List has been redacted. |\033[0m\n", Color);
                    printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
                }
                else {
                    printf("\x1B[%dm*-------Error-----*\033[0m\n", Color);
                    printf("\x1B[%dm| Invalid number! |\033[0m\n", Color);
                    printf("\x1B[%dm*-----------------*\033[0m\n", Color);
                }
                break;
            case '2':
                printf("\x1B[%dmAdd element to(1. Your point 2. Selected point 3. Nothing):\033[0m", Color);
                scanf("%s", &input);
                switch (input) {
                case '1':
                    printf("\x1B[%dmEnter the element number:\033[0m", Color);
                    scanf("%d", &el);
                    if (el > 0 and el <= SIZE) {
                        MCV = New_element(MCV, el, SIZE, Color);
                        SIZE++;
                        MCV = renumbering(MCV, SIZE);
                        printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
                        printf("\x1B[%dm| List has been redacted. |\033[0m\n", Color);
                        printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
                    }
                    else {
                        if (el == SIZE + 1) {
                            MCV = New_element_TO_END(MCV, SIZE, Color);
                            SIZE++;
                            MCV = renumbering(MCV, SIZE);
                            printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
                            printf("\x1B[%dm| List has been redacted. |\033[0m\n", Color);
                            printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
                  
                        }
                        else {
                            printf("\x1B[%dm*-------Error-----*\033[0m\n", Color);
                            printf("\x1B[%dm| Invalid number! |\033[0m\n", Color);
                            printf("\x1B[%dm*-----------------*\033[0m\n", Color);
                        }
                    }
                    break;
                case '2':
                    if (Now_point > 0) {
                        MCV = New_element(MCV, Now_point, SIZE, Color);
                        SIZE++;
                        MCV = renumbering(MCV, SIZE);
                        printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
                        printf("\x1B[%dm| List has been redacted. |\033[0m\n", Color);
                        printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
                    }
                    else {
                        printf("\x1B[%dm*-------Error-----*\033[0m\n", Color);
                        printf("\x1B[%dm| Invalid number! |\033[0m\n", Color);
                        printf("\x1B[%dm*-----------------*\033[0m\n", Color);
                    }
                    break;
                case '3':
                    printf("\x1B[%dm*----------Message-------*\033[0m\n", Color);
                    printf("\x1B[%dm| Operation is canceled. |\033[0m\n", Color);
                    printf("\x1B[%dm*------------------------*\033[0m\n", Color);
                    break;
                default:
                    printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                    printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                    printf("\x1B[%dm*------------------*\033[0m\n", Color);
                    break;
                }
                break;
            case '3':
                printf("\x1B[%dmRemove element from(1. Your point 2. Selected point 3. Nothing):\033[0m", Color);
                scanf("%s", &input);
                switch (input) {
                case '1':
                    printf("\x1B[%dmEnter the element number:\033[0m", Color);
                    scanf("%d", &el);
                    
                    if (el > 0 and el <= SIZE and SIZE>=1) {
                        if (el > 0 and el <= SIZE and SIZE > 1) {
                            MCV = remove_element(MCV, el, SIZE, Color);
                            SIZE--;
                            MCV = renumbering(MCV, SIZE);
                            printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
                            printf("\x1B[%dm| List has been redacted. |\033[0m\n", Color);
                            printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
                            if (Now_point < SIZE or Now_point < SIZE)
                                Now_point = 1;
                        }
                        else {
                            if (SIZE == 1 && el > 0 && el <= SIZE) {
                                delete_list(MCV, SIZE);
                                printf("\x1B[%dm*-------Message----*\033[0m\n", Color);
                                printf("\x1B[%dm| List is removed. |\033[0m\n", Color);
                                printf("\x1B[%dm*------------------*\033[0m\n", Color);
                                is_one_let = false;
                                MCV = NULL;
                            }
                        }
                      
                    }
                    else {
                        printf("\x1B[%dm*-------Error-----*\033[0m\n", Color);
                        printf("\x1B[%dm| Invalid number! |\033[0m\n", Color);
                        printf("\x1B[%dm*-----------------*\033[0m\n", Color);
                    }
                    break;
                case '2':
                    if (Now_point > 0 and SIZE >= 1) {
                        if (Now_point > 0 and SIZE > 1) {
                            MCV = remove_element(MCV, Now_point, SIZE, Color);
                            SIZE--;
                            MCV = renumbering(MCV, SIZE);
                            Now_point--;
                            printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
                            printf("\x1B[%dm| List has been redacted. |\033[0m\n", Color);
                            printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
                            if (Now_point == 0)
                                Now_point = 1;
                        }
                        else {
                            if (Now_point > 0 and SIZE == 1) {
                                delete_list(MCV, SIZE);
                                printf("\x1B[%dm*-------Message----*\033[0m\n", Color);
                                printf("\x1B[%dm| List is removed. |\033[0m\n", Color);
                                printf("\x1B[%dm*------------------*\033[0m\n", Color);
                                is_one_let = false;
                                MCV = NULL;
                            }
                        }
                    }
                    else {
                        printf("\x1B[%dm*-------Error-----*\033[0m\n", Color);
                        printf("\x1B[%dm| Invalid number! |\033[0m\n", Color);
                        printf("\x1B[%dm*-----------------*\033[0m\n", Color);
                    }
                    break;
                case '3':
                    printf("\x1B[%dm*----------Message-------*\033[0m\n", Color);
                    printf("\x1B[%dm| Operation is canceled. |\033[0m\n", Color);
                    printf("\x1B[%dm*------------------------*\033[0m\n", Color);
                    break;
                default:
                    printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                    printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                    printf("\x1B[%dm*------------------*\033[0m\n", Color);
                    break;
                }
            
       
                break;
            case '4':
                printf("\x1B[%dmAdd element to(1. Your point 2. Selected point 3. Nothing):\033[0m", Color);
                scanf("%s", &input);
                switch (input) {
                case '1':
                    printf("\x1B[%dmEnter the element number:\033[0m", Color);
                    scanf("%d", &el);
                    if (el > 0 and el <= SIZE) {
                        MCV = Edit_element(MCV, el, SIZE, Color);
                        printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
                        printf("\x1B[%dm| List has been redacted. |\033[0m\n", Color);
                        printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
                    }
                    else {
                        printf("\x1B[%dm*-------Error-----*\033[0m\n", Color);
                        printf("\x1B[%dm| Invalid number! |\033[0m\n", Color);
                        printf("\x1B[%dm*-----------------*\033[0m\n", Color);
                    }
                    break;
                case '2':
                    if (Now_point > 0) {
                        MCV = Edit_element(MCV, Now_point, SIZE, Color);
                        printf("\x1B[%dm*----------Message--------*\033[0m\n", Color);
                        printf("\x1B[%dm| List has been redacted. |\033[0m\n", Color);
                        printf("\x1B[%dm*-------------------------*\033[0m\n", Color);
                    }
                    else {
                        printf("\x1B[%dm*-------Error-----*\033[0m\n", Color);
                        printf("\x1B[%dm| Invalid number! |\033[0m\n", Color);
                        printf("\x1B[%dm*-----------------*\033[0m\n", Color);
                    }
                    break;
                case '3':
                    printf("\x1B[%dm*----------Message-------*\033[0m\n", Color);
                    printf("\x1B[%dm| Operation is canceled. |\033[0m\n", Color);
                    printf("\x1B[%dm*------------------------*\033[0m\n", Color);
                    break;
                default:
                    printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                    printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                    printf("\x1B[%dm*------------------*\033[0m\n", Color);
                    break;
                }
                break;
            case '5':
                printf("\x1B[%dm*----------Message-------*\033[0m\n", Color);
                printf("\x1B[%dm| Operation is canceled. |\033[0m\n", Color);
                printf("\x1B[%dm*------------------------*\033[0m\n", Color);
                break;
            default:
                printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
                printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
                printf("\x1B[%dm*------------------*\033[0m\n", Color);

                break;
            }
            break;
        default:
            printf("\x1B[%dm*-------Error------*\033[0m\n", Color);
            printf("\x1B[%dm|Invalid menu item!|\033[0m\n", Color);
            printf("\x1B[%dm*------------------*\033[0m\n", Color);
            
            break;
        }
        system("pause");
        system("cls");
		if(MCV)
            data_block(MCV,Now_point, Color);
	}
	return 0;
}