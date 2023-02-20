// khai bao Stack
#define MaxLength 100
typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Top_idx;
}Stack;


// khoi tao Stack rong
void makenullStack(Stack *pS){
	pS->Top_idx = MaxLength;
	//(*pS).Top_idx = MaxLength
}

// kiem tra Stack rong
int emptyStack(Stack S){
	return S.Top_idx == MaxLength;
}

// kiem tra Stack day
int fullStack(Stack S){
	return S.Top_idx == 0;
}

// them phan tu x vao dinh Stack
void push(ElementType x, Stack *pS){
	if(fullStack(*pS))
		printf("Ngan xep day!");
	else{
		pS->Top_idx = pS->Top_idx - 1;
		pS->Elements[pS->Top_idx] = x;
	}
	
}

// xoa phan tu tai dinh Stack
void pop(Stack *pS){
	if(emptyStack(*pS))
		printf("Ngan xep rong!");
	else
		pS->Top_idx++;
	
}

// tra ve phan tu tai dinh Stack
ElementType top(Stack S){
	return S.Elements[S.Top_idx];
}

// nhap Stack
void readStack(Stack *pS){
	makenullStack(pS);
	int n;
	scanf("%d", &n);
	ElementType x;
	while(n--){
		scanf("%d", &x);
		push(x, pS);
	}
}


// in Stack
void printStack(Stack S){
	int i = S.Top_idx;
	while(i != 0){
		printf("%d ", S.Elements[S.Top_idx]);
		pop(&S);
	}
}

//kiem tra chuoi
int ktChuoi(){
	Stack S;
	makenullStack(&S);
	char s[100];
	fgets(s, 100, stdin);
	if(s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] = '\0';
	for(int i = 0; i != strlen(s); i++){
		if(s[i] == '(')
			push(s[i], &S);
		if(s[i] == ')'){
			if(!emptyStack(S))
				pop(&S);
			else
				return 0;
		}
	}
	if(emptyStack(S))
		return 1;
	return 0;
}

// chuye trto sang hto
void chuyenHauto(char trto[], char hto[]){
	Stack S;
	int p = 0;
	makenullStack(&S);
	for(int i = 0; i != strlen[trto]; i++){
		if((trto[i] >= '0' && trto[i] <= '9') || (trto[i] >= 'a' && trto[i] <= 'z')){
			hto[p] = trto[i];
			p++;
		}
		else if(trto[i] == '(')
			push(trto[i], &S);
		else if(trto[i] == ')'){
			while(top(S) != '(' ){
				hto[p] = top(S);
				p++;
				pop(&S);
			}
			pop(&S);
		}
		else if(trto[i] == '+' || trto[i] == '-' || trto[i] == '*' || trto[i] == '/'){
			while(!emptyStack(S) && top(S) != '(' && (mucUutien(trto) <= mucUutien(top(S))){
				hto[p] = top(S);
				p++;
				pop(&S);
			}
			push(trto[i], &S);
		}
		
	}
	while(!emptyStack(S)){
		hto[p] = top(S);
		p++;
		pop(&S);
	}
	hto[p] = '\0';
}
