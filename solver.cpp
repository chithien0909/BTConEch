#include <iostream>
#include <stack>
#include <malloc.h>

using namespace std;

typedef struct{
   bool idEmpty[7];
   int pProgBlue[3];
   int pProgRed[3];
}State;

typedef struct Node{
   State state;
   struct Node* Parent;
   int no_fucntion;
}Node;


char* options[]={"start", "chuyen con ech xanh thu nhat 1", "chuyen con ech xanh thu nhat 2", "chuyen con ech xanh thu hai 1", "chuyen con ech xanh thu hai 2","chuyen con ech xanh thu ba 1",
"chuyen con ech xanh thu ba 2",
"chuyen con ech do thu nhat 1", "chuyen con ech do thu nhat 2",
"chuyen con ech do thu hai 1", "chuyen con ech do thu hai 2",
"chuyen con ech do thu ba 1", "chuyen con ech do thu ba 2"};

bool compareStates(State s, State s2){
    for(int i = 0; i < 7; i++)
       if (s.idEmpty[i] != s2.idEmpty[i]) return false;	//neu vi tri trang thai 1 khac vi tri trang thai 2 thi return false

    for(int i = 0; i < 3; i++){
       if(!((s.pProgBlue[i] == s2.pProgBlue[i]) && (s.pProgRed[i] == s2.pProgRed[i]))) return false; //so sanh vi tri ech xanh voi nhau, ech do voi nhau
    }

     return true;
}

void initState(State * state){	//khoi tao mang cac tang da
    for(int i = 0; i < 7; i++){
        state->idEmpty[i] = false;
}
    state->idEmpty[3] = true; //khoi tao vi tri o trong nam o giua
    for(int i = 0; i < 3; i++){
        state->pProgBlue[i] = i; //khoi tao vi tri ech xanh nam tu 0 den 2 nam ben trai
        state->pProgRed[i] = 4 + i;	//khoi tao vi tri ech do nam o vi tri 4 den 6 nam ben phai
    }
}

bool find_State(State state, stack<Node*> openStack){ //ham tim trang thai
   while(!openStack.empty()){ //trong khi ngan xep open co phan tu
      if(compareStates(state, openStack.top()->state)) //tim cac trang thai khac nhau
         return true;
         openStack.pop(); //them cac trang thai vao ngan xep open
   }
   return false;
}

void copyArray(int arr[], int arr1[], int length = 3){ //ham copy mang
    for(int i = 0; i < length; i++) //length = 3 la vi tri tung loai ech
        arr[i] = arr1[i]; //gan vi tri i cua mang 2 cho mang 1
}

void copyArray(bool arr[], bool arr1[], int length = 7){
    for(int i = 0; i < length; i++) //length = 7 la vi tri tat ca cac tang da
        arr[i] = arr1[i];
}

bool isGoal(State state){ //ham kiem tra trang thai hien tai co phai trang thai ket thuc hay khong
    for(int i = 0; i < 3; i++){
        if(!(state.pProgBlue[i] > 3 && state.pProgRed[i] < 3)) //neu tat ca ech xanh khong nam ben phai va tat ca ech do khong nam ben trai thi khong phai trang thai ket thuc
            return false;
    }
    return true;
}

bool blueProg1Move1(State curr_state, State * result){ //ham dinh nghia ech xanh thu nhat di chuyen 1 o sang phai
    if(((curr_state.pProgBlue[0]+1) <= 6) &&  curr_state.idEmpty[curr_state.pProgBlue[0]+1]){
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgBlue[0] += 1;
        result->idEmpty[curr_state.pProgBlue[0]+1] = false;
        result->idEmpty[curr_state.pProgBlue[0]]= true;
        return true;
    }
    return false;
}

bool blueProg1Move2(State curr_state, State * result){ //ham dinh nghia ech xanh thu nhat di chuyen 2 o sang phai
    if(((curr_state.pProgBlue[0]+2) <= 6) &&  curr_state.idEmpty[curr_state.pProgBlue[0]+2]){
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgBlue[0] += 2;
        result->idEmpty[curr_state.pProgBlue[0]+2] = false;
        result->idEmpty[curr_state.pProgBlue[0]]   = true;
        return true;
    }
    return false;
}

bool blueProg2Move1(State curr_state, State * result){ //ham dinh nghia ech xanh thu 2 di chuyen 1 o sang phai
    if(((curr_state.pProgBlue[1]+1) <= 6) &&  curr_state.idEmpty[curr_state.pProgBlue[1]+1]){
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgBlue[1] += 1;
        result->idEmpty[curr_state.pProgBlue[1]+1] = false;
        result->idEmpty[curr_state.pProgBlue[1]]= true;
        return true;
    }
    return false;
}

bool blueProg2Move2(State curr_state, State * result){ //ham dinh nghia ech xanh thu 2 di chuyen 2 o sang phai
    if(((curr_state.pProgBlue[1]+2) <= 6) &&  curr_state.idEmpty[curr_state.pProgBlue[1]+2]){
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgBlue[1] += 2;
        result->idEmpty[curr_state.pProgBlue[1]+2] = false;
        result->idEmpty[curr_state.pProgBlue[1]]= true;
        return true;
    }
    return false;
}

bool blueProg3Move1(State curr_state, State * result){ //ham dinh nghia ech xanh thu 3 di chuyen 1 o sang phai
    if(((curr_state.pProgBlue[2]+1) <= 6) && curr_state.idEmpty[curr_state.pProgBlue[2]+1]){
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgBlue[2] += 1;
        result->idEmpty[curr_state.pProgBlue[2]+1] = false;
        result->idEmpty[curr_state.pProgBlue[2]]= true;
        return true;
    }
    return false;
}

bool blueProg3Move2(State curr_state, State * result){ //ham dinh nghia ech xanh thu 3 di chuyen 2 o sang phai
    if(((curr_state.pProgBlue[2]+2) <= 6) &&  curr_state.idEmpty[curr_state.pProgBlue[2]+2]){
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgBlue[2] += 2;
        result->idEmpty[curr_state.pProgBlue[2]+2] = false;
        result->idEmpty[curr_state.pProgBlue[2]]= true;
        return true;
    }
    return false;
}

bool redProg1Move1(State curr_state, State * result){ // ham dinh nghia ech do thu 1 di chuyen 1 o sang trai
    if(((curr_state.pProgRed[0] - 1) >= 0) && curr_state.idEmpty[curr_state.pProgRed[0]-1]){
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgRed[0]-=1;
        result->idEmpty[curr_state.pProgRed[0]-1] = false;
        result->idEmpty[curr_state.pProgRed[0]] = true;
        return true;
    }
    return false;
}

bool redProg1Move2(State curr_state, State * result){ // ham dinh nghia ech do thu  1 di chuyen 2 o sang trai
    if(((curr_state.pProgRed[0] - 2) >= 0) && curr_state.idEmpty[curr_state.pProgRed[0]-2]){
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgRed[0]-=2;
        result->idEmpty[curr_state.pProgRed[0]-2] = false;
        result->idEmpty[curr_state.pProgRed[0]] = true;
        return true;
    }
    return false;
}

bool redProg2Move1(State curr_state, State * result){ //ham dinh nghia ech do thu 2 di chuyen 1 o sang trai
    if(((curr_state.pProgRed[1] - 1) >= 0) && curr_state.idEmpty[curr_state.pProgRed[1]-1]){
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgRed[1]-=1;
        result->idEmpty[curr_state.pProgRed[1]-1] = false;
        result->idEmpty[curr_state.pProgRed[1]] = true;
        return true;
    }
    return false;
}

bool redProg2Move2(State curr_state, State * result){ //ham dinh nghia ech do thu 2 di chuyen 2 o sang trai
    if((curr_state.pProgRed[1] - 2) >= 0 && curr_state.idEmpty[curr_state.pProgRed[1]- 2]){
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgRed[1]-=2;
        result->idEmpty[curr_state.pProgRed[1]-2] = false;
        result->idEmpty[curr_state.pProgRed[1]] = true;
        return true;
    }
    return false;
}

bool redProg3Move1(State curr_state, State * result){ // ham dinh nghia ech do thu 3 di chuyen 1 o sang trai
    if(((curr_state.pProgRed[1] - 1) >= 0) && curr_state.idEmpty[curr_state.pProgRed[2]- 1]){
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgRed[2]-=1;
        result->idEmpty[curr_state.pProgRed[2]-1] = false;
        result->idEmpty[curr_state.pProgRed[2]] = true;
        return true;
    }
    return false;
}

bool redProg3Move2(State curr_state, State * result){ // ham dinh nghia ech do thu 3 di chuyen 2 o sang trai
    if(((curr_state.pProgRed[2] - 2) >= 0) && curr_state.idEmpty[curr_state.pProgRed[2]- 2]){
        copyArray(result->pProgRed, curr_state.pProgRed);
        copyArray(result->pProgBlue, curr_state.pProgBlue);
        copyArray(result->idEmpty, curr_state.idEmpty);
        result->pProgRed[2]-=2;
        result->idEmpty[curr_state.pProgRed[2]-2] = false;
        result->idEmpty[curr_state.pProgRed[2]] = true;
        return true;
    }
    return false;
}


bool call_operator(State cur_state, State * result, int opt){ // ham goi cac hanh dong
    switch(opt){
        case 1: return blueProg1Move1(cur_state, result);
        case 2: return blueProg1Move2(cur_state, result);
        case 3: return blueProg2Move1(cur_state, result);
        case 4: return blueProg2Move2(cur_state, result);
        case 5: return blueProg3Move1(cur_state, result);
        case 6: return blueProg3Move2(cur_state, result);
        case 7: return redProg1Move1(cur_state, result);
        case 8: return redProg1Move2(cur_state, result);
        case 9: return redProg2Move1(cur_state, result);
        case 10: return redProg2Move2(cur_state, result);
        case 11: return redProg3Move1(cur_state, result);
        case 12: return redProg3Move2(cur_state, result);
    }
}

Node* DFS_Algorithm(State state){ // ham thuat toan deep first search
    stack<Node*> Open_DFS;
    stack<Node*> Close_DFS;
    Node* root = (Node*)malloc(sizeof(Node));
    root->state = state;
    root->Parent = NULL;
    root->no_fucntion = 0;
    Open_DFS.push(root);
    while(!Open_DFS.empty()){
        Node* node = Open_DFS.top();
        Open_DFS.pop();
        Close_DFS.push(node);
        if(isGoal(node->state))
            return node;

        for(int opt = 1; opt <= 12; opt++){
            State newstate;
            if(call_operator(node->state, &newstate, opt)){
                if(find_State(newstate, Open_DFS) || find_State(newstate, Close_DFS))
                    continue;

            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->state = newstate;
            newNode->Parent = node;
            newNode->no_fucntion = opt;
            Open_DFS.push(newNode);
         }
      }
   }
   return NULL;
}

void printState(State s){
    for(int i = 0; i < 7; i++)
        cout << s.idEmpty[i] << " ";
        cout << endl;

    for(int i = 0; i < 3; i++){
        cout << s.pProgBlue[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 3; i++){
        cout << s.pProgRed[i] << " ";
    }
    cout << endl;
}

void print_WaysToGetGoal(Node* node){
    stack<Node*> stackPrint;

    while(node->Parent != NULL){
        stackPrint.push(node);
        node = node->Parent;
    }

    stackPrint.push(node);
    int no_action = 0;
    while(!stackPrint.empty()){
        cout << "Action " << no_action <<  " " << options[stackPrint.top()->no_fucntion] << endl;
        printState(stackPrint.top()->state);
        stackPrint.pop();
        no_action++;
    }
}
